MODULE HashMapTest;
IMPORT Map, Out, DynamicArray, HashMap;

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

        AObject* = DynamicArray.AObject;
    AObjectDesc* = DynamicArray.AObjectDesc;

           Node* = Map.Node;
       NodeDesc* = Map.NodeDesc;

           HMap* = HashMap.HMap;
       HMapDesc* = HashMap.HMapDesc;
END;

VAR
    hashMap1* : HashMap.HMap;
    hashMap2* : HMap;
    hashMap3* : HMap;

        key1* : AKey;
        key2* : AKey;
        key3* : AKey;
        key4* : AKey;
        key5* : AKey;
        key6* : AKey;
        key7* : AKey;
        key8* : AKey;
        key9* : AKey;
       key10* : AKey;

      value1* : AValue;
      value2* : AValue;
      value3* : AValue;
      value4* : AValue;
      value5* : AValue;
      value6* : AValue;
      value7* : AValue;
      value8* : AValue;
      value9* : AValue;
     value10* : AValue;

BEGIN
    Out.String("Testing HashMap...");
    Out.Ln;

    NEW(key1);
    key1.key := 1;
    NEW(key2);
    key2.key := 2;
    NEW(key3);
    key3.key := 3;
    NEW(key4);
    key4.key := 4;
    NEW(key5);
    key5.key := 5;
    NEW(key6);
    key6.key := 6;
    NEW(key7);
    key7.key := 7;
    NEW(key8);
    key8.key := 8;
    NEW(key9);
    key9.key := 9;
    NEW(key10);
    key10.key := 10;

    NEW(value1);
    value1.value := 1;
    NEW(value2);
    value2.value := 2;
    NEW(value3);
    value3.value := 3;
    NEW(value4);
    value4.value := 4;
    NEW(value5);
    value5.value := 5;
    NEW(value6);
    value6.value := 6;
    NEW(value7);
    value7.value := 7;
    NEW(value8);
    value8.value := 8;
    NEW(value9);
    value9.value := 9;
    NEW(value10);
    value10.value := 10;

    hashMap1 := HashMap.Create(10);
    hashMap2 := HashMap.Create(15);
    hashMap3 := HashMap.Create(20);

    hashMap1.AddOrReplace(hashMap1, key1, value1);
    hashMap1.AddOrReplace(hashMap1, key2, value2);
    hashMap1.AddOrReplace(hashMap1, key3, value3);
    hashMap1.AddOrReplace(hashMap1, key4, value4);
    hashMap1.AddOrReplace(hashMap1, key5, value5);
    hashMap1.AddOrReplace(hashMap1, key6, value6);
    hashMap1.AddOrReplace(hashMap1, key7, value7);
    hashMap1.AddOrReplace(hashMap1, key8, value8);
    hashMap1.AddOrReplace(hashMap1, key9, value9);

    key10 := key1;

    hashMap1.AddOrReplace(hashMap1, key10, value10);

    Out.String("HashMap1: ");Out.Ln;
    Out.String("Size: ");Out.Int(hashMap1.Size(hashMap1), 0);Out.Ln;
    Out.String("Capacity: ");Out.Int(hashMap1.Capacity(hashMap1), 0); Out.Ln;
    
    Out.String("HashMap1 key1 value: "); Out.Int(hashMap1.Get(hashMap1, key1).value, 0); Out.Ln;

END HashMapTest.