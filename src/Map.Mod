MODULE Map;
IMPORT DynamicArray, Out;

TYPE
           AObject* = DynamicArray.AObject;
       AObjectDesc* = DynamicArray.AObjectDesc;

            DArray* = DynamicArray.DArray;
        DArrayDesc* = DynamicArray.DArrayDesc;

           KObject* = POINTER TO KObjectDesc;
       KObjectDesc* = RECORD;
        END;

              VObject* = POINTER TO VObjectDesc;    
            VObjectDesc* = RECORD;
        END;

      (* A MapEntry is a key-value pair. *)
          MapEntry * = POINTER TO MapEntryDesc;
      MapEntryDesc * = RECORD;
               key* : KObject;
             value* : VObject;
    END;

      (* Node which will store MapEntry *)
              Node* = POINTER TO NodeDesc;
          NodeDesc* = RECORD (AObjectDesc);
             entry* : MapEntry;
              next* : Node;
    END;

    (* A Map is a collection of nodes storing key-value pairs with a container DArray. *)
               Map* = POINTER TO MapDesc;
           MapDesc* = RECORD;
        container* : DynamicArray.DArray;
          Create * : PROCEDURE (capacity: INTEGER): Map;
NumberOfElements * : PROCEDURE (h: Map): INTEGER;
         IsEmpty * : PROCEDURE (h: Map): BOOLEAN;

  (* ContainsKey * : PROCEDURE (h: Map; key: KObject): BOOLEAN;*)

             Get * : PROCEDURE (h: Map; key: KObject): VObject;
    AddOrReplace * : PROCEDURE (h: Map; key: KObject; value: VObject);
          Remove * : PROCEDURE (h: Map; key: KObject): VObject; 
        END;

    
    PROCEDURE Create* (capacity : INTEGER) : Map;
    VAR h : Map;
    BEGIN
        NEW(h);
        h.container := DynamicArray.Create(capacity);
        RETURN h;
    END Create;

    PROCEDURE NumberOfElements* (h : Map) : INTEGER;
    BEGIN
        RETURN h.container.numberOfElements;
    END NumberOfElements;

    PROCEDURE IsEmpty* (h : Map) : BOOLEAN;
    BEGIN
        RETURN h.container.numberOfElements = 0;
    END IsEmpty;

    PROCEDURE Get* (h : Map; key : KObject) : VObject;
    VAR i : INTEGER;
        node : AObject;
        entry : MapEntry;
    BEGIN
        FOR i := 0 TO h.container.numberOfElements - 1 DO
            node := DynamicArray.Get(h.container, i);
            entry := node(Node).entry;
            IF entry.key = key THEN
                RETURN entry.value;
            END;
        END;
        RETURN NIL;
    END Get;

    PROCEDURE AddOrReplace* (h : Map; key : KObject; value : VObject);
    VAR i : INTEGER;
        node : AObject;
        entry : MapEntry;
    BEGIN
        (* FOR i := 0 TO h.container.numberOfElements - 1 DO
            Out.String("looping");Out.Int(i,0); Out.Ln;
            node := DynamicArray.Get(h.container, i);
            entry := node(Node).entry;
            IF entry.key = key THEN
                entry.value := value;
                RETURN;
            END;
        END; *)
        NEW(node);
        NEW(entry);
        entry.key := key;
        entry.value := value;
        node(Node).entry := entry;
        DynamicArray.Add(h.container, node);
    END AddOrReplace;

    PROCEDURE Remove* (h : Map; key : KObject) : VObject;
    VAR i : INTEGER;
        node : AObject;
        entry : MapEntry;
    BEGIN
        FOR i := 0 TO h.container.numberOfElements - 1 DO
            node := DynamicArray.Get(h.container, i);
            entry := node(Node).entry;
            IF entry.key = key THEN
                node := DynamicArray.Delete(h.container, i);
                RETURN entry.value;
            END;
        END;
        RETURN NIL;
    END Remove;

END Map.