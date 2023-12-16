MODULE MapTest;
IMPORT Map, Out, DynamicArray;

    TYPE    
        AObject* = DynamicArray.AObject;
        AObjectDesc* = DynamicArray.AObjectDesc;

        KObject* = Map.KObject;
        KObjectDesc* = Map.KObjectDesc;

        VObject* = Map.VObject;
        VObjectDesc* = Map.VObjectDesc;

        Node* = Map.Node;
        NodeDesc* = Map.NodeDesc;

        MapEntry* = Map.MapEntry;
        MapEntryDesc* = Map.MapEntryDesc;

        AKey* = POINTER TO AKeyDesc;
        AKeyDesc* = RECORD (Map.KObjectDesc);
        key* : INTEGER;
        END;

        AValue* = POINTER TO AValueDesc;
        AValueDesc* = RECORD (Map.VObjectDesc);
        value* : INTEGER;
        END;

VAR
    h* : Map.Map;
    i* : INTEGER;
    k* : AKey;
    v* : AValue;
    entry* : Map.MapEntry;
    node* : Map.Node;
    returnVal* : VObject;

BEGIN
    Out.String("Creating map with capacity 10"); Out.Ln;
    h := Map.Create(10);

    NEW(k);
    k.key := 1;   

    NEW(v);
    v.value := 1;

    Out.String("Adding key 1 with value 1"); Out.Ln;
    Out.Int(Map.NumberOfElements(h), 0); Out.Ln;
    Map.AddOrReplace(h, k, v);

END MapTest.