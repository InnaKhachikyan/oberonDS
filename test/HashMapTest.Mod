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

i : INTEGER;
j : INTEGER;
hash1 : INTEGER; hash2 : INTEGER; hash3 : INTEGER;  hash4 : INTEGER; hash5 : INTEGER; hash6 : INTEGER; hash7 : INTEGER; hash8 : INTEGER; hash9 : INTEGER; hash10 : INTEGER;
hash11 : INTEGER; hash12 : INTEGER; hash13 : INTEGER; hash14 : INTEGER; hash15 : INTEGER; hash16 : INTEGER; hash17 : INTEGER; hash18 : INTEGER; hash19 : INTEGER; hash20 : INTEGER;
hash21 : INTEGER; hash22 : INTEGER; hash23 : INTEGER; hash24 : INTEGER; hash25 : INTEGER; hash26 : INTEGER; hash27 : INTEGER; hash28 : INTEGER; hash29 : INTEGER; hash30 : INTEGER;
hash31 : INTEGER; hash32 : INTEGER; hash33 : INTEGER; hash34 : INTEGER; hash35 : INTEGER; hash36 : INTEGER; hash37 : INTEGER; hash38 : INTEGER; hash39 : INTEGER; hash40 : INTEGER;
hash41 : INTEGER; hash42 : INTEGER; hash43 : INTEGER; hash44 : INTEGER; hash45 : INTEGER; hash46 : INTEGER; hash47 : INTEGER; hash48 : INTEGER; hash49 : INTEGER; hash50 : INTEGER;
hash51 : INTEGER; hash52 : INTEGER; hash53 : INTEGER; hash54 : INTEGER; hash55 : INTEGER; hash56 : INTEGER; hash57 : INTEGER; hash58 : INTEGER; hash59 : INTEGER; hash60 : INTEGER;

aNode1 : NObject;
aNode2 : NObject;
aNode3 : NObject;

node1 : Node;
node2 : Node;
node3 : Node;

entry1 : MapEntry;
entry2 : MapEntry;
entry3 : MapEntry;

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

vobj1 : VObject;
vobj2 : VObject;
vobj3 : VObject;

keysContainer : kObjectArray;
valuesContainer : vObjectArray;

hashValues : ARRAY 100 OF INTEGER;

adr1 : HUGEINT; adr2 : HUGEINT; adr3 : HUGEINT; adr4 : HUGEINT; adr5 : HUGEINT; adr6 : HUGEINT; adr7 : HUGEINT; adr8 : HUGEINT; adr9 : HUGEINT; adr10 : HUGEINT;
adr11 : HUGEINT; adr12 : HUGEINT; adr13 : HUGEINT; adr14 : HUGEINT; adr15 : HUGEINT; adr16 : HUGEINT; adr17 : HUGEINT; adr18 : HUGEINT; adr19 : HUGEINT; adr20 : HUGEINT;
adr21 : HUGEINT; adr22 : HUGEINT; adr23 : HUGEINT; adr24 : HUGEINT; adr25 : HUGEINT; adr26 : HUGEINT; adr27 : HUGEINT; adr28 : HUGEINT; adr29 : HUGEINT; adr30 : HUGEINT;
adr31 : HUGEINT; adr32 : HUGEINT; adr33 : HUGEINT; adr34 : HUGEINT; adr35 : HUGEINT; adr36 : HUGEINT; adr37 : HUGEINT; adr38 : HUGEINT; adr39 : HUGEINT; adr40 : HUGEINT;
adr41 : HUGEINT; adr42 : HUGEINT; adr43 : HUGEINT; adr44 : HUGEINT; adr45 : HUGEINT; adr46 : HUGEINT; adr47 : HUGEINT; adr48 : HUGEINT; adr49 : HUGEINT; adr50 : HUGEINT;
adr51 : HUGEINT; adr52 : HUGEINT; adr53 : HUGEINT; adr54 : HUGEINT; adr55 : HUGEINT; adr56 : HUGEINT; adr57 : HUGEINT; adr58 : HUGEINT; adr59 : HUGEINT; adr60 : HUGEINT;

BEGIN
    hashValues[0] := hash1; hashValues[1] := hash2; hashValues[2] := hash3; hashValues[3] := hash4; hashValues[4] := hash5; hashValues[5] := hash6; hashValues[6] := hash7; hashValues[7] := hash8; hashValues[8] := hash9; hashValues[9] := hash10;
    hashValues[10] := hash11; hashValues[11] := hash12; hashValues[12] := hash13; hashValues[13] := hash14; hashValues[14] := hash15; hashValues[15] := hash16; hashValues[16] := hash17; hashValues[17] := hash18; hashValues[18] := hash19; hashValues[19] := hash20;
    hashValues[20] := hash21; hashValues[21] := hash22; hashValues[22] := hash23; hashValues[23] := hash24; hashValues[24] := hash25; hashValues[25] := hash26; hashValues[26] := hash27; hashValues[27] := hash28; hashValues[28] := hash29; hashValues[29] := hash30;
    hashValues[30] := hash31; hashValues[31] := hash32; hashValues[32] := hash33; hashValues[33] := hash34; hashValues[34] := hash35; hashValues[35] := hash36; hashValues[36] := hash37; hashValues[37] := hash38; hashValues[38] := hash39; hashValues[39] := hash40;
    hashValues[40] := hash41; hashValues[41] := hash42; hashValues[42] := hash43; hashValues[43] := hash44; hashValues[44] := hash45; hashValues[45] := hash46; hashValues[46] := hash47; hashValues[47] := hash48; hashValues[48] := hash49; hashValues[49] := hash50;
    hashValues[50] := hash51; hashValues[51] := hash52; hashValues[52] := hash53; hashValues[53] := hash54; hashValues[54] := hash55; hashValues[55] := hash56; hashValues[56] := hash57; hashValues[57] := hash58; hashValues[58] := hash59; hashValues[59] := hash60;

    Out.String("Creating HashTable with capacity 100"); Out.Ln;
    hTable1 := HashMap.Create(100);

    NEW(key1); key1.key := 1; adr1 := SYSTEM.VAL(HUGEINT, key1);
    (*    hash1 := HashMap.HashFunction(key1,100);  *)
    hash1 := HashMap.HashFunction(key1,100);
    
    NEW(key2); key2.key := 2; adr2 := SYSTEM.VAL(HUGEINT, key2);
    (*    hash2 := HashMap.HashFunction(key2,100);    *)
    hash2 := HashMap.HashFunction(key2,100);

    NEW(key3); key3.key := 3; adr3 := SYSTEM.VAL(HUGEINT, key3);
    (*    hash3 := HashMap.HashFunction(key3,100);    *)
    hash3 := HashMap.HashFunction(key3,100);

    NEW(key4); key4.key := 4; adr4 := SYSTEM.VAL(HUGEINT, key4);
    (*    hash4 := HashMap.HashFunction(key4,100);    *)
    hash4 := HashMap.HashFunction(key4,100);

    NEW(key5); key5.key := 5; adr5 := SYSTEM.VAL(HUGEINT, key5);
    (*    hash5 := HashMap.HashFunction(key5,100);    *)
    hash5 := HashMap.HashFunction(key5,100);

    NEW(key6); key6.key := 6; adr6 := SYSTEM.VAL(HUGEINT, key6);
    (*    hash6 := HashMap.HashFunction(key6,100);    *)
    hash6 := HashMap.HashFunction(key6,100);

    NEW(key7); key7.key := 7; adr7 := SYSTEM.VAL(HUGEINT, key7);
    (*    hash7 := HashMap.HashFunction(key7,100);    *)
    hash7 := HashMap.HashFunction(key7,100);

    NEW(key8); key8.key := 8; adr8 := SYSTEM.VAL(HUGEINT, key8);
    (*    hash8 := HashMap.HashFunction(key8,100);    *)
    hash8 := HashMap.HashFunction(key8,100);

    NEW(key9); key9.key := 9; adr9 := SYSTEM.VAL(HUGEINT, key9);
    (*    hash9 := HashMap.HashFunction(key9,100);    *)
    hash9 := HashMap.HashFunction(key9,100);

    NEW(key10); key10.key := 10; adr10 := SYSTEM.VAL(HUGEINT, key10);
    (*    hash10 := HashMap.HashFunction(key10,100);    *)
    hash10 := HashMap.HashFunction(key10,100);

    NEW(key11); key11.key := 11; adr11 := SYSTEM.VAL(HUGEINT, key11);
    (*    hash11 := HashMap.HashFunction(key11,100);    *)
    hash11 := HashMap.HashFunction(key11,100);

    NEW(key12); key12.key := 12; adr12 := SYSTEM.VAL(HUGEINT, key12);
    (*    hash12 := HashMap.HashFunction(key12,100);    *)
    hash12 := HashMap.HashFunction(key12,100);

    NEW(key13); key13.key := 13; adr13 := SYSTEM.VAL(HUGEINT, key13);
    (*    hash13 := HashMap.HashFunction(adr13,100);    *)
    hash13 := HashMap.HashFunction(key13,100);

    NEW(key14); key14.key := 14; adr14 := SYSTEM.VAL(HUGEINT, key14);
    (*    hash14 := HashMap.HashFunction(adr14,100);    *)
    hash14 := HashMap.HashFunction(key14,100);

    NEW(key15); key15.key := 15; adr15 := SYSTEM.VAL(HUGEINT, key15);
    (*    hash15 := HashMap.HashFunction(adr15,100);    *)
    hash15 := HashMap.HashFunction(key15,100);

    NEW(key16); key16.key := 16; adr16 := SYSTEM.VAL(HUGEINT, key16);
    (*    hash16 := HashMap.HashFunction(adr16,100);    *)
    hash16 := HashMap.HashFunction(key16,100);

    NEW(key17); key17.key := 17; adr17 := SYSTEM.VAL(HUGEINT, key17);
    (*    hash17 := HashMap.HashFunction(adr17,100);    *)
    hash17 := HashMap.HashFunction(key17,100);

    NEW(key18); key18.key := 18; adr18 := SYSTEM.VAL(HUGEINT, key18);
    (*    hash18 := HashMap.HashFunction(adr18,100);    *)
    hash18 := HashMap.HashFunction(key18,100);

    NEW(key19); key19.key := 19; adr19 := SYSTEM.VAL(HUGEINT, key19);
    (*    hash19 := HashMap.HashFunction(adr19,100);    *)
    hash19 := HashMap.HashFunction(key19,100);

    NEW(key20); key20.key := 20; adr20 := SYSTEM.VAL(HUGEINT, key20);
    (*    hash20 := HashMap.HashFunction(adr20,100);    *)
    hash20 := HashMap.HashFunction(key20,100);

    NEW(key21); key21.key := 21; adr21 := SYSTEM.VAL(HUGEINT, key21);
    (*    hash21 := HashMap.HashFunction(adr21,100);    *)
    hash21 := HashMap.HashFunction(key21,100);

    NEW(key22); key22.key := 22; adr22 := SYSTEM.VAL(HUGEINT, key22);
    (*    hash22 := HashMap.HashFunction(adr22,100);    *)
    hash22 := HashMap.HashFunction(key22,100);

    NEW(key23); key23.key := 23; adr23 := SYSTEM.VAL(HUGEINT, key23);
    (*    hash23 := HashMap.HashFunction(adr23,100);    *)
    hash23 := HashMap.HashFunction(key23,100);

    NEW(key24); key24.key := 24; adr24 := SYSTEM.VAL(HUGEINT, key24);
    (*    hash24 := HashMap.HashFunction(adr24,100);    *)
    hash24 := HashMap.HashFunction(key24,100);

    NEW(key25); key25.key := 25; adr25 := SYSTEM.VAL(HUGEINT, key25);
    (*    hash25 := HashMap.HashFunction(adr25,100);    *)
    hash25 := HashMap.HashFunction(key25,100);

    NEW(key26); key26.key := 26; adr26 := SYSTEM.VAL(HUGEINT, key26);
    (*    hash26 := HashMap.HashFunction(adr26,100);    *)
    hash26 := HashMap.HashFunction(key26,100);

    NEW(key27); key27.key := 27; adr27 := SYSTEM.VAL(HUGEINT, key27);
    (*    hash27 := HashMap.HashFunction(adr27,100);    *)
    hash27 := HashMap.HashFunction(key27,100); 

    NEW(key28); key28.key := 28; adr28 := SYSTEM.VAL(HUGEINT, key28);
    (*    hash28 := HashMap.HashFunction(adr28,100);    *)
    hash28 := HashMap.HashFunction(key28,100);

    NEW(key29); key29.key := 29; adr29 := SYSTEM.VAL(HUGEINT, key29);
    (*    hash29 := HashMap.HashFunction(adr29,100);    *)
    hash29 := HashMap.HashFunction(key29,100); 

    hashValues[0] := hash1; hashValues[1] := hash2; hashValues[2] := hash3; hashValues[3] := hash4; hashValues[4] := hash5; hashValues[5] := hash6; hashValues[6] := hash7; hashValues[7] := hash8; hashValues[8] := hash9; hashValues[9] := hash10;
    hashValues[10] := hash11; hashValues[11] := hash12; hashValues[12] := hash13; hashValues[13] := hash14; hashValues[14] := hash15; hashValues[15] := hash16; hashValues[16] := hash17; hashValues[17] := hash18; hashValues[18] := hash19; hashValues[19] := hash20;
    hashValues[20] := hash21; hashValues[21] := hash22; hashValues[22] := hash23; hashValues[23] := hash24; hashValues[24] := hash25; hashValues[25] := hash26; hashValues[26] := hash27; hashValues[27] := hash28; hashValues[28] := hash29; hashValues[29] := hash30;

    FOR i := 0 TO 29 DO
        FOR j := i TO 29 DO
            IF i # j THEN
                IF hashValues[i] = hashValues[j] THEN
                    Out.String("hash"); Out.Int(i+1,0); Out.String(" is equal to hash"); Out.Int(j+1,0); Out.Ln;
                END;
            END;
        END;
    END;



END HashMapTest.


