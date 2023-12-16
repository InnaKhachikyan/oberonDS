MODULE MapTest;
IMPORT Map, Out, DynamicArray;

    TYPE    
            KObject* = Map.KObject;
        KObjectDesc* = Map.KObjectDesc;

               AKey* = POINTER TO AKeyDesc;
           AKeyDesc* = RECORD (Map.KObjectDesc);
                key* : INTEGER;
        END;

            VObject* = Map.VObject;
        VObjectDesc* = Map.VObjectDesc;

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
    IF k IS KObject THEN
        Out.String("k is KObject"); Out.Ln;
    END;

END MapTest.