MODULE MapTest;
IMPORT Map, Out, DynamicArray, SYSTEM;

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

VAR
        prime* : BOOLEAN;
         map1* : Map.Map;
         map2* : Map.Map;
         map3* : Map.Map;
            i* : INTEGER;
     kAddress* : HUGEINT;
   hashResult* : HUGEINT;

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

        entry* : Map.MapEntry;
        aNode* : AObject;
         node* : Map.Node;
   returnVal1* : VObject;
   returnVal2* : VObject;
   returnVal3* : VObject;

   returnKey1* : KObject;
   returnKey2* : KObject;
   returnKey3* : KObject;

     returnA1* : AObject;
     returnA2* : AObject;
     returnA3* : AObject;

 keysIterator* : DynamicArray.DArray;
valueIterator* : DynamicArray.DArray;

BEGIN
    Out.String("Creating map1 with capacity 10");
    map1 := Map.Create(10);
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

    Out.String("Adding key1, value1 to map1"); Out.Ln;
    Map.AddOrReplace(map1, key1, value1);
    Map.AddOrReplace(map1, key2, value2);
    Map.AddOrReplace(map1, key3, value3);
    Map.AddOrReplace(map1, key4, value4);
    Map.AddOrReplace(map1, key5, value5);
    Map.AddOrReplace(map1, key6, value6);
    Map.AddOrReplace(map1, key7, value7);
    Map.AddOrReplace(map1, key8, value8);
    Map.AddOrReplace(map1, key9, value9);
    Map.AddOrReplace(map1, key10, value10);

    FOR i := 0 TO map1.container.numberOfElements - 1 DO
        aNode := DynamicArray.Get(map1.container, i);
        entry := aNode(Node).entry;
        Out.String("key: "); Out.Int(entry.key(AKey).key, 0); Out.String(" value: "); Out.Int(entry.value(AValue).value, 0); Out.Ln;
    END;

    Out.String("number of elements before removal: "); Out.Ln;
    Out.Int(map1.container.numberOfElements, 0); Out.Ln;

    Out.String("Removing key5 from map1"); Out.Ln;
    returnVal1 := Map.Remove(map1, key5);
    Out.String("key5 value: "); Out.Int(returnVal1(AValue).value, 0); Out.Ln;
    
    Out.String("number of elements after removal: "); Out.Ln;
    Out.Int(map1.container.numberOfElements, 0); Out.Ln;

    FOR i := 0 TO map1.container.numberOfElements - 1 DO
        aNode := DynamicArray.Get(map1.container, i);
        entry := aNode(Node).entry;
        Out.String("key: "); Out.Int(entry.key(AKey).key, 0); Out.String(" value: "); Out.Int(entry.value(AValue).value, 0); Out.Ln;
    END;

    Out.String("Testing iterator of keys"); Out.Ln;
    keysIterator := Map.Keys(map1);
    FOR i := 0 TO keysIterator.numberOfElements - 1 DO
        returnA1 := DynamicArray.Get(keysIterator,i);
        returnKey1  := returnA1(KObject);
        Out.String("key: "); Out.Int(returnKey1(AKey).key, 0); Out.Ln;
    END;

    Out.String("Testing iterator of values"); Out.Ln;
    valueIterator := Map.Values(map1);
    FOR i := 0 TO valueIterator.numberOfElements - 1 DO
        returnA2 := DynamicArray.Get(valueIterator,i);
        returnVal2  := returnA2(VObject);
        Out.String("value: "); Out.Int(returnVal2(AValue).value, 0); Out.Ln;
    END;

    Out.String("testing hashcode: "); Out.Ln;
    key2 := key1;
    kAddress := SYSTEM.VAL(HUGEINT, SYSTEM.ADR(key1));
    Out.String("key1 address: "); Out.Int(kAddress, 0); Out.Ln;
    hashResult := Map.HashCode(key1);
    hashResult := Map.HashCode(key2);

    Out.String("testing FirstPrime method: "); Out.Ln;
    i := Map.FirstPrime(1429);
    Out.Int(i, 0); Out.Ln;

    Out.String("testing hashFunction"); Out.Ln;
    hashResult := Map.HashFunction(key1, 10);
    Out.Int(hashResult, 0); Out.Ln;

    key2 := key1;
    hashResult := Map.HashFunction(key2, 10);
    Out.Int(hashResult, 0); Out.Ln;

    key3 := key1;
    hashResult := Map.HashFunction(key3, 10);
    Out.Int(hashResult, 0); Out.Ln;

END MapTest.
