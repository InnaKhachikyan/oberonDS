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
             Get * : PROCEDURE (h: Map; key: KObject): VObject;
    AddOrReplace * : PROCEDURE (h: Map; key: KObject; value: VObject);
          Remove * : PROCEDURE (h: Map; key: KObject): VObject; 
            Keys * : PROCEDURE (h: Map): DArray;
          Values * : PROCEDURE (h: Map): DArray;
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
    VAR     i : INTEGER;
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
    VAR     i : INTEGER;
        aNode : AObject;
         node : Node;
        entry : MapEntry;
    BEGIN
        FOR i := 0 TO h.container.numberOfElements - 1 DO
            aNode := DynamicArray.Get(h.container, i);
            entry := aNode(Node).entry;
            IF entry.key = key THEN
                entry.value := value;
                RETURN;
            END;
        END;
        NEW(node);
        NEW(entry);
        entry.key := key;
        entry.value := value;
        node(Node).entry := entry;
        DynamicArray.Add(h.container, node);
    END AddOrReplace;

    PROCEDURE Remove* (h : Map; key : KObject) : VObject;
    VAR     i : INTEGER;
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

    PROCEDURE Keys* (h : Map) : DArray;
    VAR     i : INTEGER;
         node : AObject;
        entry : MapEntry;
         keys : DArray;
    BEGIN
        keys := DynamicArray.Create(h.container.numberOfElements);
        FOR i := 0 TO h.container.numberOfElements - 1 DO
            node := DynamicArray.Get(h.container, i);
            entry := node(Node).entry;
            DynamicArray.Add(keys, entry.key);
        END;
        RETURN keys;
    END Keys;

    PROCEDURE Values* (h : Map) : DArray;
    VAR     i : INTEGER;
         node : AObject;
        entry : MapEntry;
       values : DArray;
    BEGIN
        values := DynamicArray.Create(h.container.numberOfElements);
        FOR i := 0 TO h.container.numberOfElements - 1 DO
            node := DynamicArray.Get(h.container, i);
            entry := node(Node).entry;
            DynamicArray.Add(values, entry.value);
        END;
        RETURN values;
    END Values;

    PROCEDURE Power* (base, exponent : INTEGER) : HUGEINT;
    VAR i, result : HUGEINT;
    BEGIN
        result := 1;
        FOR i := 0 TO exponent - 1 DO
            result := result * base;
        END;
        RETURN result;
    END Power;

	(* hashcode calculates a huge number using digits of the address    
	of the key taking into consideration their order, for now coefficient 
	var is a concrete number, it is temporary, I'll change it when I
	figure out how to generate random number *) 
    PROCEDURE HashCode* (key: KObject): HUGEINT;
    VAR 
        adr: HUGEINT;
        coefficient: INTEGER;
        i: INTEGER;
        digit: HUGEINT;
        hash: HUGEINT;
    BEGIN
        i := 0;
        coefficient := 37;
        hash := 0;
        adr := SYSTEM.VAL(HUGEINT, SYSTEM.ADR(key));
        Out.String("key address: "); Out.Int(adr, 0); Out.Ln;
        WHILE adr > 0 DO
            digit := adr MOD 10;  (* Extract the least significant digit *)
            Out.String("digit: "); Out.Int(digit, 0); Out.Ln;
            adr := adr DIV 10;    (* Move to the next digit *)
            
            hash := hash + digit * (Power(coefficient, i));
            i := i + 1;
        END;
        
        RETURN hash;
    END HashCode;

        PROCEDURE IsPrime*(n: INTEGER): BOOLEAN;
    VAR 
        i: INTEGER;
        upto : INTEGER;
    BEGIN
        i := 2;
        upto := SYSTEM.VAL(INTEGER, Math.sqrt(n));
        WHILE i <= upto DO
            IF n MOD i = 0 THEN
                RETURN FALSE;
            END;
            i := i + 1;
        END;
        RETURN TRUE;
    END IsPrime;

	(* finds the first prime that is greater than a given number
	in our case we need a prime that is bigger than the range of the 
	Dynamic arry *)
    PROCEDURE NextPrime* (n: INTEGER): INTEGER;
    VAR 
        i: INTEGER;
        prime: BOOLEAN;
    BEGIN
        i := n+1;
        WHILE TRUE DO
            prime := IsPrime(i);
            IF prime THEN
                RETURN i;
            END;
            i := i + 1;
        END;
    END NextPrime;

	(* compression function is used to compress the hugeint generated
	by the hashcode and return an int in the range of the dynamic array;
	for now vars a and b are given concrete values, that's temporary;
	I'll change it, when figure out how to generate random numbers *)
    PROCEDURE CompressHash* (hash: HUGEINT; range: INTEGER): INTEGER;
    VAR 
        a : HUGEINT;
        b : HUGEINT;
        prime : HUGEINT;
        result : HUGEINT;
        returnVal : INTEGER;
    BEGIN
        a := 11;
        b := 17;
        prime := FirstPrime(range);
        result := (a * hash + b);
        result := result MOD prime;
        result := result MOD range;
        returnVal := SYSTEM.VAL(INTEGER, result);
        RETURN returnVal;
    END CompressHash;

    PROCEDURE HashFunction* (key: KObject; range: INTEGER): INTEGER;
    VAR 
        hash: HUGEINT;
        returnVal: INTEGER;
    BEGIN
        hash := HashCode(key);
        returnVal := CompressHash(hash, range);
        RETURN returnVal;
    END HashFunction;

END Map.
