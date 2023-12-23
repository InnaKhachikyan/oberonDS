MODULE HashMap;
IMPORT SYSTEM, Out, Math, DynamicArray, Map;

TYPE
          AObject* = DynamicArray.AObject;
      AObjectDesc* = DynamicArray.AObjectDesc;

           DArray* = DynamicArray.DArray;
       DArrayDesc* = DynamicArray.DArrayDesc;

            KVMap* = Map.KVMap;
        KVMapDesc* = Map.KVMapDesc;

    (* A MapEntry is a key-value pair *)
         MapEntry* = Map.MapEntry;
     MapEntryDesc* = Map.MapEntryDesc;

          KObject* = Map.KObject;
      KObjectDesc* = Map.KObjectDesc;

          VObject* = Map.VObject;
      VObjectDesc* = Map.VObjectDesc;

(* Node which will store MapEntry and a reference to next *)
             Node* = POINTER TO NodeDesc;
         NodeDesc* = RECORD (AObjectDesc);
            entry* : Map.MapEntry;
             next* : Node;
        END;

(* A HashMap is a collection of nodes storing key-value pairs *)
             HMap* = POINTER TO HMapDesc;
         HMapDesc* = RECORD(KVMapDesc);
           IsPrime : PROCEDURE (n: INTEGER): BOOLEAN;
             Power : PROCEDURE (base, exponent : INTEGER): HUGEINT;
         NextPrime : PROCEDURE (n: INTEGER): INTEGER;
          HashCode : PROCEDURE (key: KObject): HUGEINT;
      CompressHash : PROCEDURE (hash: HUGEINT; range: INTEGER): INTEGER;
      HashFunction : PROCEDURE (key: KObject; range: INTEGER): INTEGER;
END;

PROCEDURE NumberOfElements* (h : HMap) : INTEGER;
BEGIN
    RETURN Map.NumberOfElements(h);
END NumberOfElements;

PROCEDURE IsEmpty* (h : HMap) : BOOLEAN;
BEGIN
    RETURN Map.IsEmpty(h);
END IsEmpty;

PROCEDURE Create* (capacity : INTEGER) : HMap;
VAR 
    h : HMap;
BEGIN
    NEW(h);
    h.container := DynamicArray.Create(capacity);
    RETURN h;
END Create;

PROCEDURE Get* (h : HMap; key : KObject) : VObject;
VAR     
        i : INTEGER;
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

PROCEDURE Remove* (h : HMap; key : KObject) : VObject;
VAR     
        i : INTEGER;
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

PROCEDURE Keys* (h : HMap) : DArray;
VAR     
        i : INTEGER;
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

PROCEDURE Values* (h : HMap) : DArray;
VAR     
         i : INTEGER;  
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

PROCEDURE Power (base, exponent : INTEGER) : HUGEINT;
VAR 
    i, result : HUGEINT;
BEGIN
    result := 1;
    FOR i:= 0 TO exponent - 1 DO
        result := result * base;
    END;
    RETURN result;
END Power;

PROCEDURE IsPrime (n: INTEGER) : BOOLEAN;
VAR 
       i : INTEGER;
    upto : INTEGER;
BEGIN
    i := 2;
    upto := SYSTEM.VAL(INTEGER, Math.sqrt(n));
    WHILE i <= upto DO
        IF n MOD i = 0 THEN
            RETURN FALSE;
        END;
        i := i+1;
    END;
    RETURN TRUE;
END IsPrime;

PROCEDURE NextPrime (n: INTEGER) : INTEGER;
VAR 
        i : INTEGER;
    prime : BOOLEAN;
BEGIN
    i := n + 1;
    WHILE TRUE DO
        prime := IsPrime(i);
        IF prime THEN
            RETURN i;
        END;
        i := i + 1;
    END;
END NextPrime;

PROCEDURE HashCode (key: KObject) : HUGEINT;
VAR  
            adr : HUGEINT;
    coefficient : INTEGER;
              i : INTEGER;
          digit : HUGEINT;
           hash : HUGEINT;
BEGIN
    i := 0;
    coefficient := 37;
    hash := 0;
    adr := SYSTEM.VAL(HUGEINT, SYSTEM.ADR(key));
    WHILE adr > 0 DO
        digit := adr MOD 10;
        adr := adr DIV 10;
        hash := hash + digit * (Power(coefficient, i));
        i := i + 1;
    END;
    RETURN hash;
END HashCode;

PROCEDURE CompressHash (hash: HUGEINT; range: INTEGER) : INTEGER;
VAR 
            a : HUGEINT;
            b : HUGEINT;
        prime : HUGEINT;
       result : HUGEINT;
    returnVal : INTEGER;
BEGIN
    a := 11;
    b := 17;
    prime := NextPrime(range);
    result := (a * hash + b);
    result := result MOD prime;
    returnVal := SYSTEM.VAL(INTEGER, result);
    RETURN returnVal;
END CompressHash;

PROCEDURE HashFunction (key: KObject; range: INTEGER) : INTEGER;
VAR 
         hash : HUGEINT;
    returnVal : INTEGER;
BEGIN 
    hash := HashCode(key);
    returnVal := CompressHash(hash, range);
    RETURN returnVal;
END HashFunction;

PROCEDURE AddOrReplace* (h : HMap; key : KObject; value : VObject);
VAR     
    index : INTEGER;
    aNode : AObject;
     node : Node;
    entry : MapEntry;
BEGIN
    index := HashFunction(key, h.container.capacity);
    aNode := DynamicArray.Get(h.container, index);
    IF aNode = NIL THEN
        NEW(node);
        NEW(entry);
        entry.key := key;
        entry.value := value;
        node(Node).entry := entry;
        DynamicArray.Add(h.container, node);
    ELSE
        WHILE aNode(Node).next # NIL DO
            aNode := aNode(Node).next;
        END;
        NEW(node);
        NEW(entry);
        entry.key := key;
        entry.value := value;
        node(Node).entry := entry;
        aNode(Node).next := node;
    END;
END AddOrReplace;

END HashMap.

