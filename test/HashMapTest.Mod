MODULE HashMapTest;
IMPORT Out, HashMap, SYSTEM, Math;

TYPE
      NObject* = HashMap.NObject;
  NObjectDesc* = HashMap.NObjectDesc;

      KObject* = HashMap.KObject;
  KObjectDesc* = HashMap.KObjectDesc;

         HKey* = POINTER TO HKeyDesc;
     HKeyDesc* = RECORD (HashMap.KObjectDesc);
          key* : INTEGER;
     END;

      VObject* = HashMap.VObject;
  VObjectDesc* = HashMap.VObjectDesc;

       HValue* = POINTER TO HValueDesc;
   HValueDesc* = RECORD (HashMap.VObjectDesc);
        value* : INTEGER;
   END;

     MapEntry* = HashMap.MapEntry;
 MapEntryDesc* = HashMap.MapEntryDesc;

         Node* = HashMap.Node;
     NodeDesc* = HashMap.NodeDesc;

    HashTable* = HashMap.HashTable;
HashTableDesc* = HashMap.HashTableDesc;

 kObjectArray* = HashMap.kObjectArray;
 vObjectArray* = HashMap.vObjectArray;

VAR
        hTable1 : HashTable;
        hTable2 : HashTable;
        hTable3 : HashTable;

         aNode1 : NObject;
         aNode2 : NObject;
         aNode3 : NObject;

          node1 : Node;
          node2 : Node;
          node3 : Node;

         entry1 : MapEntry;
         entry2 : MapEntry;
         entry3 : MapEntry;

          vkey1 : VObject;
          vkey2 : VObject;
          vkey3 : VObject;

              i : INTEGER;
              j : INTEGER;

  keysContainer : kObjectArray;
valuesContainer : vObjectArray;

key1 : HKey; key2 : HKey; key3 : HKey; key4 : HKey; key5 : HKey; key6 : HKey; key7 : HKey; key8 : HKey; key9 : HKey; key10 : HKey;
key11 : HKey; key12 : HKey; key13 : HKey; key14 : HKey; key15 : HKey; key16 : HKey; key17 : HKey; key18 : HKey; key19 : HKey; key20 : HKey;
key21 : HKey; key22 : HKey; key23 : HKey; key24 : HKey; key25 : HKey; key26 : HKey; key27 : HKey; key28 : HKey; key29 : HKey; key30 : HKey;
key31 : HKey; key32 : HKey; key33 : HKey; key34 : HKey; key35 : HKey; key36 : HKey; key37 : HKey; key38 : HKey; key39 : HKey; key40 : HKey;
key41 : HKey; key42 : HKey; key43 : HKey; key44 : HKey; key45 : HKey; key46 : HKey; key47 : HKey; key48 : HKey; key49 : HKey; key50 : HKey;
key51 : HKey; key52 : HKey; key53 : HKey; key54 : HKey; key55 : HKey; key56 : HKey; key57 : HKey; key58 : HKey; key59 : HKey; key60 : HKey;

value1 : HValue; value2 : HValue; value3 : HValue; value4 : HValue; value5 : HValue; value6 : HValue; value7 : HValue; value8 : HValue; value9 : HValue; value10 : HValue;
value11 : HValue; value12 : HValue; value13 : HValue; value14 : HValue; value15 : HValue; value16 : HValue; value17 : HValue; value18 : HValue; value19 : HValue; value20 : HValue;
value21 : HValue; value22 : HValue; value23 : HValue; value24 : HValue; value25 : HValue; value26 : HValue; value27 : HValue; value28 : HValue; value29 : HValue; value30 : HValue;
value31 : HValue; value32 : HValue; value33 : HValue; value34 : HValue; value35 : HValue; value36 : HValue; value37 : HValue; value38 : HValue; value39 : HValue; value40 : HValue;
value41 : HValue; value42 : HValue; value43 : HValue; value44 : HValue; value45 : HValue; value46 : HValue; value47 : HValue; value48 : HValue; value49 : HValue; value50 : HValue;
value51 : HValue; value52 : HValue; value53 : HValue; value54 : HValue; value55 : HValue; value56 : HValue; value57 : HValue; value58 : HValue; value59 : HValue; value60 : HValue;

BEGIN
    Out.String("Creating hashtable");Out.Ln;
    hTable1 := HashMap.Create(100);

    NEW(key1); key1(HKey).key := 1; NEW(value1); value1(HValue).value := 1;
    NEW(key2); key2(HKey).key := 2; NEW(value2); value2(HValue).value := 2;
    NEW(key3); key3(HKey).key := 3; NEW(value3); value3(HValue).value := 3;
    NEW(key4); key4(HKey).key := 4; NEW(value4); value4(HValue).value := 4;
    NEW(key5); key5(HKey).key := 5; NEW(value5); value5(HValue).value := 5;
    NEW(key6); key6(HKey).key := 6; NEW(value6); value6(HValue).value := 6;
    NEW(key7); key7(HKey).key := 7; NEW(value7); value7(HValue).value := 7;
    NEW(key8); key8(HKey).key := 8; NEW(value8); value8(HValue).value := 8;
    NEW(key9); key9(HKey).key := 9; NEW(value9); value9(HValue).value := 9;
    NEW(key10); key10(HKey).key := 10; NEW(value10); value10(HValue).value := 10;

    Out.Ln; Out.String("-----testing the AddOrReplace method-----");Out.Ln;
    HashMap.AddOrReplace(hTable1, key1, value1);
    HashMap.AddOrReplace(hTable1, key2, value2);
    HashMap.AddOrReplace(hTable1, key3, value3);
    HashMap.AddOrReplace(hTable1, key4, value4);
    HashMap.AddOrReplace(hTable1, key5, value5);
    HashMap.AddOrReplace(hTable1, key6, value6);
    HashMap.AddOrReplace(hTable1, key7, value7);
    HashMap.AddOrReplace(hTable1, key8, value8);
    HashMap.AddOrReplace(hTable1, key9, value9);
    HashMap.AddOrReplace(hTable1, key10, value10);

    Out.Ln; Out.String("-----testing the Get method BEFORE RESIZE-----");Out.Ln;
    IF HashMap.Get(hTable1,key1) = value1 THEN
        IF HashMap.Get(hTable1,key2) = value2 THEN
            IF HashMap.Get(hTable1,key9) = value9 THEN
                Out.String("Get method works");Out.Ln;
            ELSE
                Out.String("Get method does not work");Out.Ln;
            END;
        ELSE
            Out.String("Get method does not work");Out.Ln;
        END;
    ELSE
        Out.String("Get method does not work");Out.Ln;
    END;

    Out.Ln;Out.String("-----testing the AddOrReplace to replace value-----");Out.Ln;
    key11 := key8; NEW(value11); value11.value := 11;
    HashMap.AddOrReplace(hTable1, key11, value11);
    IF HashMap.Get(hTable1,key8) = value11 THEN
        Out.String("AddOrReplace method works");Out.Ln;
    ELSE
        Out.String("AddOrReplace method does not work");Out.Ln;
    END;

    Out.Ln; Out.String("-----testing the resize method-----");Out.Ln;
    NEW(key12); key12.key := 12; NEW(value12); value12(HValue).value := 12;
    NEW(key13); key13.key := 13; NEW(value13); value13(HValue).value := 13;
    NEW(key14); key14.key := 14; NEW(value14); value14(HValue).value := 14;
    NEW(key15); key15.key := 15; NEW(value15); value15(HValue).value := 15;
    NEW(key16); key16.key := 16; NEW(value16); value16(HValue).value := 16;
    NEW(key17); key17.key := 17; NEW(value17); value17(HValue).value := 17;
    NEW(key18); key18.key := 18; NEW(value18); value18(HValue).value := 18;
    NEW(key19); key19.key := 19; NEW(value19); value19(HValue).value := 19;
    NEW(key20); key20.key := 20; NEW(value20); value20(HValue).value := 20;
    NEW(key21); key21.key := 21; NEW(value21); value21(HValue).value := 21;
    NEW(key22); key22.key := 22; NEW(value22); value22(HValue).value := 22;
    NEW(key23); key23.key := 23; NEW(value23); value23(HValue).value := 23;
    NEW(key24); key24.key := 24; NEW(value24); value24(HValue).value := 24;
    NEW(key25); key25.key := 25; NEW(value25); value25(HValue).value := 25;
    NEW(key26); key26.key := 26; NEW(value26); value26(HValue).value := 26;
    NEW(key27); key27.key := 27; NEW(value27); value27(HValue).value := 27;
    NEW(key28); key28.key := 28; NEW(value28); value28(HValue).value := 28;
    NEW(key29); key29.key := 29; NEW(value29); value29(HValue).value := 29;
    NEW(key30); key30.key := 30; NEW(value30); value30(HValue).value := 30;
    NEW(key31); key31.key := 31; NEW(value31); value31(HValue).value := 31;
    NEW(key32); key32.key := 32; NEW(value32); value32(HValue).value := 32;
    NEW(key33); key33.key := 33; NEW(value33); value33(HValue).value := 33;
    NEW(key34); key34.key := 34; NEW(value34); value34(HValue).value := 34;
    NEW(key35); key35.key := 35; NEW(value35); value35(HValue).value := 35;
    NEW(key36); key36.key := 36; NEW(value36); value36(HValue).value := 36;
    NEW(key37); key37.key := 37; NEW(value37); value37(HValue).value := 37;
    NEW(key38); key38.key := 38; NEW(value38); value38(HValue).value := 38;
    NEW(key39); key39.key := 39; NEW(value39); value39(HValue).value := 39;
    NEW(key40); key40.key := 40; NEW(value40); value40(HValue).value := 40;
    NEW(key41); key41.key := 41; NEW(value41); value41(HValue).value := 41;
    NEW(key42); key42.key := 42; NEW(value42); value42(HValue).value := 42;
    NEW(key43); key43.key := 43; NEW(value43); value43(HValue).value := 43;
    NEW(key44); key44.key := 44; NEW(value44); value44(HValue).value := 44;
    NEW(key45); key45.key := 45; NEW(value45); value45(HValue).value := 45;
    NEW(key46); key46.key := 46; NEW(value46); value46(HValue).value := 46;
    NEW(key47); key47.key := 47; NEW(value47); value47(HValue).value := 47;
    NEW(key48); key48.key := 48; NEW(value48); value48(HValue).value := 48;
    NEW(key49); key49.key := 49; NEW(value49); value49(HValue).value := 49;
    NEW(key50); key50.key := 50; NEW(value50); value50(HValue).value := 50;
    NEW(key51); key51.key := 51; NEW(value51); value51(HValue).value := 51;
    NEW(key52); key52.key := 52; NEW(value52); value52(HValue).value := 52;
    NEW(key53); key53.key := 53; NEW(value53); value53(HValue).value := 53;
    NEW(key54); key54.key := 54; NEW(value54); value54(HValue).value := 54;
    
    Out.String("Number of elements: "); i := HashMap.NumberOfElements(hTable1); Out.Int(i, 0); Out.Ln;

    HashMap.AddOrReplace(hTable1, key12, value12);
    HashMap.AddOrReplace(hTable1, key13, value13);
    HashMap.AddOrReplace(hTable1, key14, value14);
    HashMap.AddOrReplace(hTable1, key15, value15);
    HashMap.AddOrReplace(hTable1, key16, value16);
    HashMap.AddOrReplace(hTable1, key17, value17);
    HashMap.AddOrReplace(hTable1, key18, value18);
    HashMap.AddOrReplace(hTable1, key19, value19);
    HashMap.AddOrReplace(hTable1, key20, value20);
    HashMap.AddOrReplace(hTable1, key21, value21);
    HashMap.AddOrReplace(hTable1, key22, value22);
    HashMap.AddOrReplace(hTable1, key23, value23);
    HashMap.AddOrReplace(hTable1, key24, value24);
    HashMap.AddOrReplace(hTable1, key25, value25);
    HashMap.AddOrReplace(hTable1, key26, value26);
    HashMap.AddOrReplace(hTable1, key27, value27);
    HashMap.AddOrReplace(hTable1, key28, value28);
    HashMap.AddOrReplace(hTable1, key29, value29);
    HashMap.AddOrReplace(hTable1, key30, value30);

    Out.String("Number of elements: "); i := HashMap.NumberOfElements(hTable1); Out.Int(i, 0); Out.Ln;

    HashMap.AddOrReplace(hTable1, key31, value31);
    HashMap.AddOrReplace(hTable1, key32, value32);
    HashMap.AddOrReplace(hTable1, key33, value33);
    HashMap.AddOrReplace(hTable1, key34, value34);
    HashMap.AddOrReplace(hTable1, key35, value35);
    HashMap.AddOrReplace(hTable1, key36, value36);
    HashMap.AddOrReplace(hTable1, key37, value37);
    HashMap.AddOrReplace(hTable1, key38, value38);
    HashMap.AddOrReplace(hTable1, key39, value39);
    HashMap.AddOrReplace(hTable1, key40, value40);
    HashMap.AddOrReplace(hTable1, key41, value41);
    HashMap.AddOrReplace(hTable1, key42, value42);
    HashMap.AddOrReplace(hTable1, key43, value43);
    HashMap.AddOrReplace(hTable1, key44, value44);
    HashMap.AddOrReplace(hTable1, key45, value45);
    HashMap.AddOrReplace(hTable1, key46, value46);
    HashMap.AddOrReplace(hTable1, key47, value47);
    HashMap.AddOrReplace(hTable1, key48, value48);
    HashMap.AddOrReplace(hTable1, key49, value49);
    HashMap.AddOrReplace(hTable1, key50, value50);
    HashMap.AddOrReplace(hTable1, key51, value51);

    Out.String("Number of elements: "); i := HashMap.NumberOfElements(hTable1); Out.Int(i, 0); Out.Ln;

    HashMap.AddOrReplace(hTable1, key52, value52);
    Out.String("Testing methods after resize");Out.Ln;  
    Out.String("Number of elements: "); i := HashMap.NumberOfElements(hTable1); Out.Int(i, 0); Out.Ln;

    Out.Ln; Out.String("-----testing the Get method AFTER RESIZE-----");Out.Ln;
    IF HashMap.Get(hTable1,key18) = value18 THEN
        IF HashMap.Get(hTable1,key21) = value21 THEN
            IF HashMap.Get(hTable1,key38) = value38 THEN
                IF HashMap.Get(hTable1,key43) = value43 THEN
                    IF HashMap.Get(hTable1,key52) = value52 THEN
                        Out.String("Get method works ---1");Out.Ln;
                    ELSE
                        Out.String("Get method does not work ---2");Out.Ln;
                    END;
                ELSE
                    Out.String("Get method does not work ---3");Out.Ln;
                END;
            ELSE
                Out.String("Get method does not work ---4");Out.Ln;
            END;
        ELSE
            Out.String("Get method does not work ---5");Out.Ln;
        END;
    ELSE
        Out.String("Get method does not work ---6");Out.Ln;
    END;

    Out.Ln; Out.String("-----testing the AddOrReplace to replace value AFTER RESIZE-----");Out.Ln;
    key53 := key18; NEW(value53); value53.value := 53;
    HashMap.AddOrReplace(hTable1, key53, value53);
    IF HashMap.Get(hTable1,key18) = value53 THEN
        Out.String("AddOrReplace method works");Out.Ln;
    ELSE
        Out.String("AddOrReplace method does not work");Out.Ln;
    END;

    Out.Ln; Out.String("-----testing the Remove method-----");Out.Ln;
    vkey1 := HashMap.Remove(hTable1, key19);
    i := vkey1(HValue).value;
    IF i = 19 THEN
        Out.String("Remove method works");Out.Ln;
    ELSE
        Out.String("Remove method does not work");Out.Ln;
    END;

    Out.String("Number of elements: "); i := HashMap.NumberOfElements(hTable1); Out.Int(i, 0); Out.Ln;


    Out.Ln; Out.String("-----testing the iterator of keys-----");Out.Ln;
    keysContainer := HashMap.Keys(hTable1);
    Out.Int(keysContainer.capacity,0);Out.Ln;
    FOR j := 0 TO (keysContainer.capacity-1) DO
        IF keysContainer.container[j] # NIL THEN
            Out.Int(keysContainer.container[j](HKey).key,0);Out.Ln;
        ELSE
            Out.String("Keys method does not work");Out.Ln;
        END;
    END;

    Out.Ln; Out.String("-----testing the iterator of values-----");Out.Ln;
    valuesContainer := HashMap.Values(hTable1);
    Out.Int(valuesContainer.capacity,0);Out.Ln;
    FOR j := 0 TO (valuesContainer.capacity-1) DO
        IF valuesContainer.container[j] # NIL THEN
            Out.Int(valuesContainer.container[j](HValue).value,0);Out.Ln;
        ELSE
            Out.String("Values method does not work");Out.Ln;
        END;
    END;

END HashMapTest.


