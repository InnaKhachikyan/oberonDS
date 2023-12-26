MODULE HashMap;
IMPORT SYSTEM, Out, Math;

TYPE
         NObject* = POINTER TO NObjectDesc;
     NObjectDesc* = RECORD;
     END;

         KObject* = POINTER TO KObjectDesc;
     KObjectDesc* = RECORD (NObjectDesc);
     END;

         VObject* = POINTER TO VObjectDesc;
     VObjectDesc* = RECORD (NObjectDesc);
     END;

        MapEntry* = POINTER TO MapEntryDesc;
    MapEntryDesc* = RECORD (NObjectDesc);
             key* : KObject;
           value* : VObject;
    END;

            Node* = POINTER TO NodeDesc;
        NodeDesc* = RECORD (NObjectDesc);
       CreateNode : PROCEDURE (entry: MapEntry): Node;
           entry* : MapEntry;
            next* : Node;
        END;

       hcontainer = POINTER TO ARRAY OF NObject;
    (* kObjectArray* = POINTER TO ARRAY OF KObject; *)

    kObjectArray* = POINTER TO kObjectArrayDesc;
kObjectArrayDesc* = RECORD;
CreateKObjectArray : PROCEDURE (capacity: INTEGER): kObjectArray;
capacity* : INTEGER;
container* : POINTER TO ARRAY OF KObject;
END;

    (* vObjectArray* = POINTER TO ARRAY OF VObject; *)

    vObjectArray* = POINTER TO vObjectArrayDesc;
vObjectArrayDesc* = RECORD;
CreateVObjectArray : PROCEDURE (capacity: INTEGER): vObjectArray;
capacity* : INTEGER;
container* : POINTER TO ARRAY OF VObject;
END;

       HashTable* = POINTER TO HashTableDesc;
   HashTableDesc* = RECORD;
       container* : hcontainer;
          Create* : PROCEDURE (capacity: INTEGER): HashTable;
NumberOfElements* : PROCEDURE (h: HashTable): INTEGER;
         IsEmpty* : PROCEDURE (h: HashTable): BOOLEAN;
          IsPrime : PROCEDURE (n: INTEGER): BOOLEAN;
            Power : PROCEDURE (base, exponent : INTEGER): HUGEINT;
        NextPrime : PROCEDURE (n: INTEGER): INTEGER;
         HashCode : PROCEDURE (key: KObject): HUGEINT;
     CompressHash : PROCEDURE (hash: HUGEINT; range: INTEGER): INTEGER;
     HashFunction : PROCEDURE (key: KObject; range: INTEGER): INTEGER;
             Get* : PROCEDURE (h: HashTable; key: KObject): VObject;
    AddOrReplace* : PROCEDURE (h: HashTable; key: KObject; value: VObject);
          Remove* : PROCEDURE (h: HashTable; key: KObject): VObject; 
            Keys* : PROCEDURE (h: HashTable): kObjectArray; 
          Values* : PROCEDURE (h: HashTable): vObjectArray;
           Resize : PROCEDURE (h: HashTable);
 numberOfElements : INTEGER;
         capacity : INTEGER;
END;

PROCEDURE CreateKObjectArray (size: INTEGER): kObjectArray;
VAR
    k : kObjectArray;
BEGIN
    NEW(k);
    k.capacity := size;
    NEW(k.container, k.capacity);
    RETURN k;
END CreateKObjectArray;

PROCEDURE CreateVObjectArray (size: INTEGER): vObjectArray;
VAR
    v : vObjectArray;
BEGIN
    NEW(v);
    v.capacity := size;
    NEW(v.container, v.capacity);
    RETURN v;
END CreateVObjectArray;

PROCEDURE Create* (size : INTEGER) : HashTable;
VAR
    h : HashTable;
BEGIN
    NEW(h);
    h.numberOfElements := 0;
    h.capacity := size;
    NEW(h.container, size);
    RETURN h;
END Create;

PROCEDURE NumberOfElements* (h : HashTable) : INTEGER;
BEGIN
    RETURN h.numberOfElements;
END NumberOfElements;

PROCEDURE IsEmpty* (h : HashTable) : BOOLEAN;
BEGIN
    RETURN h.numberOfElements = 0;
END IsEmpty;

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
    Out.Ln;Out.String("adr: "); Out.Int(adr, 0); Out.Ln;
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
            temp : INTEGER;
        prime : HUGEINT;
       result : HUGEINT;
    returnVal : INTEGER;
BEGIN
    a := 7681;
    b := 6983;
    temp := SYSTEM.VAL(INTEGER,(range * a * b));
    prime := NextPrime(temp);
    result := (a * hash + b);
    (*result := result MOD prime;*)
    result := result MOD range;
    returnVal := SYSTEM.VAL(INTEGER, result);
    RETURN returnVal;
END CompressHash;

PROCEDURE HashFunction* (key: KObject; range: INTEGER) : INTEGER;
VAR 
         hash : HUGEINT;
    returnVal : INTEGER;
BEGIN 
    hash := HashCode(key);
    returnVal := CompressHash(hash, range);
    Out.String("------hash: "); Out.Int(returnVal, 0); Out.Ln;
    RETURN returnVal;
END HashFunction;

(*PROCEDURE Get* (h : HashTable; key : KObject) : VObject;
VAR
    index : INTEGER;
     node : NObject;
    entry : MapEntry;
    aNode : Node;
BEGIN
    index := HashFunction(key, h.capacity);
    node := h.container[index];
    WHILE node # NIL DO
        aNode := node(Node);
        entry := aNode.entry;
        IF entry.key = key THEN
            RETURN entry.value;
        END;
        node := aNode.next;
    END;
    RETURN NIL;
END Get;*)

(*PROCEDURE Resize (h : HashTable);
VAR
         newSize : INTEGER;
    newContainer : hcontainer;
               i : INTEGER;
           nobj1 : NObject;
           nobj2 : NObject;
           node1 : Node;
           node2 : Node;
           entry : MapEntry;
        newIndex : INTEGER;
BEGIN
    Out.String("Entering Resize"); Out.Ln;
    newSize := NextPrime(h.capacity * 2);
    NEW(newContainer, newSize);
    FOR i := 0 TO h.capacity - 1 DO
        Out.String("printing i: "); Out.Int(i, 0); Out.Ln;
        IF h.container[i] # NIL THEN
            Out.Ln; Out.String("entered first IF statement"); Out.Ln;
            nobj1 := h.container[i];
            IF nobj1 # NIL THEN
                Out.Ln; Out.String("entered second IF statement"); Out.Ln;
                entry := nobj1(Node).entry;
                newIndex := HashFunction(entry.key, newSize);
                Out.String("printing newIndex: "); Out.Int(newIndex, 0); Out.Ln;
                IF newContainer[newIndex] = NIL THEN
                    NEW(node1);
                    node1.entry := entry;
                    node1.next := NIL;
                    newContainer[newIndex] := node1;
                ELSE
                    nobj2 := newContainer[newIndex];
                    NEW(node2);
                    node2.entry := entry;
                    node2.next := nobj2(Node);
                    newContainer[newIndex] := node2;
                END;
            END;
        END;
    END;
    h.container := newContainer;
    h.capacity := newSize;
END Resize;*)

(*PROCEDURE AddOrReplace* (h : HashTable; key : KObject; value : VObject);
VAR
    index : INTEGER;
     node : NObject;
    entry : MapEntry;
    aNode : Node;
    size : INTEGER;
BEGIN
    Out.String("Entering AddOrReplace"); Out.Ln;
    size := SYSTEM.VAL(INTEGER, h.capacity/2);
    Out.String("printing size: ");Out.Int(size, 0); Out.Ln;
    IF h.numberOfElements = size THEN
        Out.String("Entered Resizing"); Out.Ln;
        Resize(h);
    END;
    index := HashFunction(key, h.capacity);
    Out.Ln; Out.String("printing index: "); Out.Int(index, 0); Out.Ln;
    node := h.container[index];
    IF node = NIL THEN
        NEW(aNode);
        NEW(entry);
        entry.key := key;
        entry.value := value;
        aNode.entry := entry;
        aNode.next := NIL;
        h.container[index] := aNode;
        INC(h.numberOfElements);
        RETURN;
    ELSE
        WHILE node # NIL DO
            aNode := node(Node);
            entry := aNode.entry;
            IF entry.key = key THEN
                entry.value := value;
                RETURN;
            END;
            node := aNode.next;
        END;
        NEW(aNode);
        NEW(entry);
        entry.key := key;
        entry.value := value;
        aNode.entry := entry;
        node := h.container[index];
        aNode.next := node(Node);
        h.container[index] := aNode;
        INC(h.numberOfElements);
    END;
    Out.String("Exiting AddOrReplace"); Out.Ln;
END AddOrReplace;*)

(*PROCEDURE Remove* (h : HashTable; key : KObject) : VObject;
VAR
    index : INTEGER;
     node : NObject;
    entry : MapEntry;
    aNode : Node;
BEGIN
    index := HashFunction(key, h.capacity);
    node := h.container[index];
    IF node = NIL THEN
        RETURN NIL;
    ELSE
        WHILE node # NIL DO
            aNode := node(Node);
            entry := aNode.entry;
            IF entry.key = key THEN
                h.container[index] := aNode.next;
                DEC(h.numberOfElements);
                RETURN entry.value;
            END;
            node := aNode.next;
        END;
        RETURN NIL;
    END;
END Remove;*)

PROCEDURE Keys* (h : HashTable) : kObjectArray;
VAR
    keys : kObjectArray;
    i : INTEGER;
    j : INTEGER;
    node : NObject;
    aNode : Node;
    entry : MapEntry;
BEGIN
    keys := CreateKObjectArray(h.numberOfElements);
    j := 0;
    FOR i := 0 TO h.capacity - 1 DO
        node := h.container[i];
        WHILE node # NIL DO
            aNode := node(Node);
            entry := aNode.entry;
            keys.container[j] := entry.key;
            j := j + 1;
            node := aNode.next;
        END;
    END;
    RETURN keys;
END Keys;

PROCEDURE Values* (h : HashTable) : vObjectArray;
VAR
    values : vObjectArray;
    i : INTEGER;
    j : INTEGER;
    node : NObject;
    aNode : Node;
    entry : MapEntry;
BEGIN
    values := CreateVObjectArray(h.numberOfElements);
    j := 0;
    FOR i := 0 TO h.capacity - 1 DO
        node := h.container[i];
        WHILE node # NIL DO
            aNode := node(Node);
            entry := aNode.entry;
            values.container[j] := entry.value;
            j := j + 1;
            node := aNode.next;
        END;
    END;
    RETURN values;
END Values;

END HashMap.
