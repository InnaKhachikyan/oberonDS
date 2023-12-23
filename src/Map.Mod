MODULE Map;
IMPORT DynamicArray, Out, SYSTEM, Math;

TYPE
          AObject* = DynamicArray.AObject;
      AObjectDesc* = DynamicArray.AObjectDesc;

           DArray* = DynamicArray.DArray;
       DArrayDesc* = DynamicArray.DArrayDesc;

          KObject* = POINTER TO KObjectDesc;
      KObjectDesc* = RECORD (AObjectDesc);
      END;

          VObject* = POINTER TO VObjectDesc;    
      VObjectDesc* = RECORD (AObjectDesc);
      END;

     (* A MapEntry is a key-value pair. *)
         MapEntry* = POINTER TO MapEntryDesc;
     MapEntryDesc* = RECORD(AObjectDesc);
              key* : KObject;
            value* : VObject;
    END;

(* A KVMap is a collection of nodes storing key-value pairs with a container DArray. *)
            KVMap* = POINTER TO KVMapDesc;
        KVMapDesc* = RECORD;
        container* : DynamicArray.DArray;
           Create* : PROCEDURE (capacity: INTEGER): KVMap;
 NumberOfElements* : PROCEDURE (h: KVMap): INTEGER;
          IsEmpty* : PROCEDURE (h: KVMap): BOOLEAN;
              Get* : PROCEDURE (h: KVMap; key: KObject): VObject;
     AddOrReplace* : PROCEDURE (h: KVMap; key: KObject; value: VObject);
           Remove* : PROCEDURE (h: KVMap; key: KObject): VObject; 
             Keys* : PROCEDURE (h: KVMap): DArray;
           Values* : PROCEDURE (h: KVMap): DArray;
   END;

    
PROCEDURE Create* (capacity : INTEGER) : KVMap;
VAR 
    h : KVMap;
BEGIN
    NEW(h);
    h.container := DynamicArray.Create(capacity);
    RETURN h;
END Create;

PROCEDURE NumberOfElements* (h : KVMap) : INTEGER;
BEGIN
    RETURN h.container.numberOfElements;
END NumberOfElements;

PROCEDURE IsEmpty* (h : KVMap) : BOOLEAN;
BEGIN
    RETURN h.container.numberOfElements = 0;
END IsEmpty;

PROCEDURE Get* (h : KVMap; key : KObject) : VObject;
VAR     
        i : INTEGER;
    entry : AObject;
BEGIN
    FOR i := 0 TO h.container.numberOfElements - 1 DO
        entry := DynamicArray.Get(h.container, i);
        IF entry(MapEntry).key = key THEN
            RETURN entry(MapEntry).value;
        END;
    END;
    RETURN NIL;
END Get;

PROCEDURE AddOrReplace* (h : KVMap; key : KObject; value : VObject);
VAR     
        i : INTEGER;
   aEntry : AObject;
    entry : MapEntry;
BEGIN
    FOR i := 0 TO h.container.numberOfElements - 1 DO
        aEntry := DynamicArray.Get(h.container, i);
        IF aEntry(MapEntry).key = key THEN
            entry.value := value;
            RETURN;
        END;
    END;
    NEW(entry);
    entry.key := key;
    entry.value := value;
    DynamicArray.Add(h.container, entry);
END AddOrReplace;

PROCEDURE Remove* (h : KVMap; key : KObject) : VObject;
VAR     
         i : INTEGER;
    aEntry : AObject;
BEGIN
    FOR i := 0 TO h.container.numberOfElements - 1 DO
        aEntry := DynamicArray.Get(h.container, i);
        IF aEntry(MapEntry).key = key THEN
            aEntry := DynamicArray.Delete(h.container, i);
            RETURN aEntry(MapEntry).value;
        END;
    END;
    RETURN NIL;
END Remove;

PROCEDURE Keys* (h : KVMap) : DArray;
VAR     
        i : INTEGER;
    entry : AObject;
     keys : DArray;
BEGIN
    keys := DynamicArray.Create(h.container.numberOfElements);
    FOR i := 0 TO h.container.numberOfElements - 1 DO
        entry := DynamicArray.Get(h.container, i);
        DynamicArray.Add(keys, entry(MapEntry).key);
    END;
    RETURN keys;
END Keys;

PROCEDURE Values* (h : KVMap) : DArray;
VAR     
        i : INTEGER;
    entry : AObject;
   values : DArray;
BEGIN
    values := DynamicArray.Create(h.container.numberOfElements);
    FOR i := 0 TO h.container.numberOfElements - 1 DO
        entry := DynamicArray.Get(h.container, i);
        DynamicArray.Add(values, entry(MapEntry).value);
    END;
    RETURN values;
END Values;

END Map.
