MODULE HashMapTest;
IMPORT Out, HashMap, Map, DynamicArray;

TYPE
     AObject* = DynamicArray.AObject;
 AObjectDesc* = DynamicArray.AObjectDesc;

      DArray* = DynamicArray.DArray;
  DArrayDesc* = DynamicArray.DArrayDesc;

       KVMap* = Map.KVMap;
   KVMapDesc* = Map.KVMapDesc;
    
        HMap* = HashMap.HMap;
    HMapDesc* = HashMap.HMapDesc;
    
        AKey* = POINTER TO AKeyDesc;
    AKeyDesc* = RECORD (HashMap.KObjectDesc);
         key* : INTEGER;
    END;
    
      AValue* = POINTER TO AValueDesc;
  AValueDesc* = RECORD (HashMap.VObjectDesc);
       value* : INTEGER;
  END;

        Node* = HashMap.Node;
    NodeDesc* = HashMap.NodeDesc;

    MapEntry* = HashMap.MapEntry;
MapEntryDesc* = HashMap.MapEntryDesc;

VAR
    hashMap1* : HMap;
    hashMap2* : HMap;
    hashMap3* : HMap;

      aNode1* : AObject;
      aNode2* : AObject;

      entry1* : HashMap.MapEntry;
      entry2* : HashMap.MapEntry;

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
    Out.String("------Test HashMap------"); Out.Ln;

    hashMap1 := HashMap.Create(10);
    hashMap2 := HashMap.Create(10);
    hashMap3 := HashMap.Create(10);

    NEW(key1);
    key1.key := 1;
    NEW(value1);
    value1.value := 1;
    HashMap.AddOrReplace(hashMap1, key1, value1);

    NEW(key2);
    key2.key := 2;
    NEW(value2);
    value2.value := 2;
    HashMap.AddOrReplace(hashMap1, key2, value2);

    NEW(key3);
    key3.key := 3;
    NEW(value3);
    value3.value := 3;
    HashMap.AddOrReplace(hashMap1, key3, value3);

    NEW(key4);
    key4.key := 4;
    NEW(value4);
    value4.value := 4;
    HashMap.AddOrReplace(hashMap1, key4, value4);

    NEW(key5);
    key5.key := 5;
    NEW(value5);
    value5.value := 5;
    HashMap.AddOrReplace(hashMap1, key5, value5);

    NEW(key6);
    key6.key := 6;
    NEW(value6);
    value6.value := 6;
    HashMap.AddOrReplace(hashMap1, key6, value6);

    NEW(key7);
    key7.key := 7;
    NEW(value7);
    value7.value := 7;
    HashMap.AddOrReplace(hashMap1, key7, value7);

    NEW(key8);
    key8.key := 8;
    NEW(value8);
    value8.value := 8;
    HashMap.AddOrReplace(hashMap1, key8, value8);

    NEW(key9);
    key9.key := 9;
    NEW(value9);
    value9.value := 9;
    HashMap.AddOrReplace(hashMap1, key9, value9);

    Out.String("------Testing method NumberOfElements------"); Out.Ln;
    IF HashMap.NumberOfElements(hashMap1) = 9 THEN 
        Out.String("NumberOfElements Test passed"); Out.Ln;
    ELSE
        Out.String("NumberOfElements Test failed"); Out.Ln;
    END;

    Out.String("------Testing method IsEmpty------"); Out.Ln;
    IF HashMap.IsEmpty(hashMap1) = FALSE THEN
        Out.String("IsEmpty Test passed"); Out.Ln;
    ELSE
        Out.String("IsEmpty Test failed"); Out.Ln;
    END;

    Out.String("------Testing method Get------"); Out.Ln;
    IF HashMap.Get(hashMap1, key1) = value1 THEN
        Out.String("Get Test passed"); Out.Ln;
    ELSE
        Out.String("Get Test failed"); Out.Ln;
    END;

    Out.String("------Testing method Remove------"); Out.Ln;
    IF HashMap.Remove(hashMap1, key1) = value1 THEN
        IF HashMap.Get(hashMap1, key1) = NIL THEN
            Out.String("Remove Test passed"); Out.Ln;
        ELSE
            Out.String("Remove Test failed"); Out.Ln;
        END;
    END;

    Out.String("------Testing method AddOrReplace------"); Out.Ln;
    NEW(key10);
    key10.key := 10;
    NEW(value10);
    value10.value := 10;
    key10 := key1;
    HashMap.AddOrReplace(hashMap1, key10, value10);
    IF HashMap.Get(hashMap1, key1) = value10 THEN
        IF HashMap.Get(hashMap1, key10) = value10 THEN
            Out.String("AddOrReplace Test passed"); Out.Ln;
        ELSE
            Out.String("AddOrReplace Test failed"); Out.Ln;
        END;
    END;

END HashMapTest.
