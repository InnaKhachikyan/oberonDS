/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtpam */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "HashMap.h"
#include "Math.h"
#include "Out.h"

typedef
	struct HashMapTest_HKeyDesc *HashMapTest_HKey;

typedef
	struct HashMapTest_HKeyDesc { /* HashMap_KObjectDesc */
		INT16 key;
	} HashMapTest_HKeyDesc;

typedef
	struct HashMapTest_HValueDesc *HashMapTest_HValue;

typedef
	struct HashMapTest_HValueDesc { /* HashMap_VObjectDesc */
		INT16 value;
	} HashMapTest_HValueDesc;


static HashMap_HashTable HashMapTest_hTable1, HashMapTest_hTable2, HashMapTest_hTable3;
static INT16 HashMapTest_i, HashMapTest_j, HashMapTest_hash1, HashMapTest_hash2, HashMapTest_hash3, HashMapTest_hash4, HashMapTest_hash5, HashMapTest_hash6, HashMapTest_hash7, HashMapTest_hash8, HashMapTest_hash9, HashMapTest_hash10, HashMapTest_hash11, HashMapTest_hash12, HashMapTest_hash13, HashMapTest_hash14, HashMapTest_hash15, HashMapTest_hash16, HashMapTest_hash17, HashMapTest_hash18, HashMapTest_hash19, HashMapTest_hash20, HashMapTest_hash21, HashMapTest_hash22, HashMapTest_hash23, HashMapTest_hash24, HashMapTest_hash25, HashMapTest_hash26, HashMapTest_hash27, HashMapTest_hash28, HashMapTest_hash29, HashMapTest_hash30, HashMapTest_hash31, HashMapTest_hash32, HashMapTest_hash33, HashMapTest_hash34, HashMapTest_hash35, HashMapTest_hash36, HashMapTest_hash37, HashMapTest_hash38, HashMapTest_hash39, HashMapTest_hash40, HashMapTest_hash41, HashMapTest_hash42, HashMapTest_hash43, HashMapTest_hash44, HashMapTest_hash45, HashMapTest_hash46, HashMapTest_hash47, HashMapTest_hash48, HashMapTest_hash49, HashMapTest_hash50, HashMapTest_hash51, HashMapTest_hash52, HashMapTest_hash53, HashMapTest_hash54, HashMapTest_hash55, HashMapTest_hash56, HashMapTest_hash57, HashMapTest_hash58, HashMapTest_hash59, HashMapTest_hash60;
static HashMap_NObject HashMapTest_aNode1, HashMapTest_aNode2, HashMapTest_aNode3;
static HashMap_Node HashMapTest_node1, HashMapTest_node2, HashMapTest_node3;
static HashMap_MapEntry HashMapTest_entry1, HashMapTest_entry2, HashMapTest_entry3;
static HashMapTest_HKey HashMapTest_key1, HashMapTest_key2, HashMapTest_key3, HashMapTest_key4, HashMapTest_key5, HashMapTest_key6, HashMapTest_key7, HashMapTest_key8, HashMapTest_key9, HashMapTest_key10, HashMapTest_key11, HashMapTest_key12, HashMapTest_key13, HashMapTest_key14, HashMapTest_key15, HashMapTest_key16, HashMapTest_key17, HashMapTest_key18, HashMapTest_key19, HashMapTest_key20, HashMapTest_key21, HashMapTest_key22, HashMapTest_key23, HashMapTest_key24, HashMapTest_key25, HashMapTest_key26, HashMapTest_key27, HashMapTest_key28, HashMapTest_key29, HashMapTest_key30, HashMapTest_key31, HashMapTest_key32, HashMapTest_key33, HashMapTest_key34, HashMapTest_key35, HashMapTest_key36, HashMapTest_key37, HashMapTest_key38, HashMapTest_key39, HashMapTest_key40, HashMapTest_key41, HashMapTest_key42, HashMapTest_key43, HashMapTest_key44, HashMapTest_key45, HashMapTest_key46, HashMapTest_key47, HashMapTest_key48, HashMapTest_key49, HashMapTest_key50, HashMapTest_key51, HashMapTest_key52, HashMapTest_key53, HashMapTest_key54, HashMapTest_key55, HashMapTest_key56, HashMapTest_key57, HashMapTest_key58, HashMapTest_key59, HashMapTest_key60;
static HashMapTest_HValue HashMapTest_value1, HashMapTest_value2, HashMapTest_value3, HashMapTest_value4, HashMapTest_value5, HashMapTest_value6, HashMapTest_value7, HashMapTest_value8, HashMapTest_value9, HashMapTest_value10, HashMapTest_value11, HashMapTest_value12, HashMapTest_value13, HashMapTest_value14, HashMapTest_value15, HashMapTest_value16, HashMapTest_value17, HashMapTest_value18, HashMapTest_value19, HashMapTest_value20, HashMapTest_value21, HashMapTest_value22, HashMapTest_value23, HashMapTest_value24, HashMapTest_value25, HashMapTest_value26, HashMapTest_value27, HashMapTest_value28, HashMapTest_value29, HashMapTest_value30, HashMapTest_value31, HashMapTest_value32, HashMapTest_value33, HashMapTest_value34, HashMapTest_value35, HashMapTest_value36, HashMapTest_value37, HashMapTest_value38, HashMapTest_value39, HashMapTest_value40, HashMapTest_value41, HashMapTest_value42, HashMapTest_value43, HashMapTest_value44, HashMapTest_value45, HashMapTest_value46, HashMapTest_value47, HashMapTest_value48, HashMapTest_value49, HashMapTest_value50, HashMapTest_value51, HashMapTest_value52, HashMapTest_value53, HashMapTest_value54, HashMapTest_value55, HashMapTest_value56, HashMapTest_value57, HashMapTest_value58, HashMapTest_value59, HashMapTest_value60;
static HashMap_VObject HashMapTest_vobj1, HashMapTest_vobj2, HashMapTest_vobj3;
static HashMap_kObjectArray HashMapTest_keysContainer;
static HashMap_vObjectArray HashMapTest_valuesContainer;
static INT16 HashMapTest_hashValues[100];
static INT64 HashMapTest_adr1, HashMapTest_adr2, HashMapTest_adr3, HashMapTest_adr4, HashMapTest_adr5, HashMapTest_adr6, HashMapTest_adr7, HashMapTest_adr8, HashMapTest_adr9, HashMapTest_adr10, HashMapTest_adr11, HashMapTest_adr12, HashMapTest_adr13, HashMapTest_adr14, HashMapTest_adr15, HashMapTest_adr16, HashMapTest_adr17, HashMapTest_adr18, HashMapTest_adr19, HashMapTest_adr20, HashMapTest_adr21, HashMapTest_adr22, HashMapTest_adr23, HashMapTest_adr24, HashMapTest_adr25, HashMapTest_adr26, HashMapTest_adr27, HashMapTest_adr28, HashMapTest_adr29, HashMapTest_adr30, HashMapTest_adr31, HashMapTest_adr32, HashMapTest_adr33, HashMapTest_adr34, HashMapTest_adr35, HashMapTest_adr36, HashMapTest_adr37, HashMapTest_adr38, HashMapTest_adr39, HashMapTest_adr40, HashMapTest_adr41, HashMapTest_adr42, HashMapTest_adr43, HashMapTest_adr44, HashMapTest_adr45, HashMapTest_adr46, HashMapTest_adr47, HashMapTest_adr48, HashMapTest_adr49, HashMapTest_adr50, HashMapTest_adr51, HashMapTest_adr52, HashMapTest_adr53, HashMapTest_adr54, HashMapTest_adr55, HashMapTest_adr56, HashMapTest_adr57, HashMapTest_adr58, HashMapTest_adr59, HashMapTest_adr60;

export ADDRESS *HashMapTest_HKeyDesc__typ;
export ADDRESS *HashMapTest_HValueDesc__typ;



static void EnumPtrs(void (*P)(void*))
{
	P(HashMapTest_hTable1);
	P(HashMapTest_hTable2);
	P(HashMapTest_hTable3);
	P(HashMapTest_aNode1);
	P(HashMapTest_aNode2);
	P(HashMapTest_aNode3);
	P(HashMapTest_node1);
	P(HashMapTest_node2);
	P(HashMapTest_node3);
	P(HashMapTest_entry1);
	P(HashMapTest_entry2);
	P(HashMapTest_entry3);
	P(HashMapTest_key1);
	P(HashMapTest_key2);
	P(HashMapTest_key3);
	P(HashMapTest_key4);
	P(HashMapTest_key5);
	P(HashMapTest_key6);
	P(HashMapTest_key7);
	P(HashMapTest_key8);
	P(HashMapTest_key9);
	P(HashMapTest_key10);
	P(HashMapTest_key11);
	P(HashMapTest_key12);
	P(HashMapTest_key13);
	P(HashMapTest_key14);
	P(HashMapTest_key15);
	P(HashMapTest_key16);
	P(HashMapTest_key17);
	P(HashMapTest_key18);
	P(HashMapTest_key19);
	P(HashMapTest_key20);
	P(HashMapTest_key21);
	P(HashMapTest_key22);
	P(HashMapTest_key23);
	P(HashMapTest_key24);
	P(HashMapTest_key25);
	P(HashMapTest_key26);
	P(HashMapTest_key27);
	P(HashMapTest_key28);
	P(HashMapTest_key29);
	P(HashMapTest_key30);
	P(HashMapTest_key31);
	P(HashMapTest_key32);
	P(HashMapTest_key33);
	P(HashMapTest_key34);
	P(HashMapTest_key35);
	P(HashMapTest_key36);
	P(HashMapTest_key37);
	P(HashMapTest_key38);
	P(HashMapTest_key39);
	P(HashMapTest_key40);
	P(HashMapTest_key41);
	P(HashMapTest_key42);
	P(HashMapTest_key43);
	P(HashMapTest_key44);
	P(HashMapTest_key45);
	P(HashMapTest_key46);
	P(HashMapTest_key47);
	P(HashMapTest_key48);
	P(HashMapTest_key49);
	P(HashMapTest_key50);
	P(HashMapTest_key51);
	P(HashMapTest_key52);
	P(HashMapTest_key53);
	P(HashMapTest_key54);
	P(HashMapTest_key55);
	P(HashMapTest_key56);
	P(HashMapTest_key57);
	P(HashMapTest_key58);
	P(HashMapTest_key59);
	P(HashMapTest_key60);
	P(HashMapTest_value1);
	P(HashMapTest_value2);
	P(HashMapTest_value3);
	P(HashMapTest_value4);
	P(HashMapTest_value5);
	P(HashMapTest_value6);
	P(HashMapTest_value7);
	P(HashMapTest_value8);
	P(HashMapTest_value9);
	P(HashMapTest_value10);
	P(HashMapTest_value11);
	P(HashMapTest_value12);
	P(HashMapTest_value13);
	P(HashMapTest_value14);
	P(HashMapTest_value15);
	P(HashMapTest_value16);
	P(HashMapTest_value17);
	P(HashMapTest_value18);
	P(HashMapTest_value19);
	P(HashMapTest_value20);
	P(HashMapTest_value21);
	P(HashMapTest_value22);
	P(HashMapTest_value23);
	P(HashMapTest_value24);
	P(HashMapTest_value25);
	P(HashMapTest_value26);
	P(HashMapTest_value27);
	P(HashMapTest_value28);
	P(HashMapTest_value29);
	P(HashMapTest_value30);
	P(HashMapTest_value31);
	P(HashMapTest_value32);
	P(HashMapTest_value33);
	P(HashMapTest_value34);
	P(HashMapTest_value35);
	P(HashMapTest_value36);
	P(HashMapTest_value37);
	P(HashMapTest_value38);
	P(HashMapTest_value39);
	P(HashMapTest_value40);
	P(HashMapTest_value41);
	P(HashMapTest_value42);
	P(HashMapTest_value43);
	P(HashMapTest_value44);
	P(HashMapTest_value45);
	P(HashMapTest_value46);
	P(HashMapTest_value47);
	P(HashMapTest_value48);
	P(HashMapTest_value49);
	P(HashMapTest_value50);
	P(HashMapTest_value51);
	P(HashMapTest_value52);
	P(HashMapTest_value53);
	P(HashMapTest_value54);
	P(HashMapTest_value55);
	P(HashMapTest_value56);
	P(HashMapTest_value57);
	P(HashMapTest_value58);
	P(HashMapTest_value59);
	P(HashMapTest_value60);
	P(HashMapTest_vobj1);
	P(HashMapTest_vobj2);
	P(HashMapTest_vobj3);
	P(HashMapTest_keysContainer);
	P(HashMapTest_valuesContainer);
}

__TDESC(HashMapTest_HKeyDesc, 1, 0) = {__TDFLDS("HKeyDesc", 2), {-8}};
__TDESC(HashMapTest_HValueDesc, 1, 0) = {__TDFLDS("HValueDesc", 2), {-8}};

export int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__MODULE_IMPORT(HashMap);
	__MODULE_IMPORT(Math);
	__MODULE_IMPORT(Out);
	__REGMAIN("HashMapTest", EnumPtrs);
	__INITYP(HashMapTest_HKeyDesc, HashMap_KObjectDesc, 2);
	__INITYP(HashMapTest_HValueDesc, HashMap_VObjectDesc, 2);
/* BEGIN */
	HashMapTest_hashValues[0] = HashMapTest_hash1;
	HashMapTest_hashValues[1] = HashMapTest_hash2;
	HashMapTest_hashValues[2] = HashMapTest_hash3;
	HashMapTest_hashValues[3] = HashMapTest_hash4;
	HashMapTest_hashValues[4] = HashMapTest_hash5;
	HashMapTest_hashValues[5] = HashMapTest_hash6;
	HashMapTest_hashValues[6] = HashMapTest_hash7;
	HashMapTest_hashValues[7] = HashMapTest_hash8;
	HashMapTest_hashValues[8] = HashMapTest_hash9;
	HashMapTest_hashValues[9] = HashMapTest_hash10;
	HashMapTest_hashValues[10] = HashMapTest_hash11;
	HashMapTest_hashValues[11] = HashMapTest_hash12;
	HashMapTest_hashValues[12] = HashMapTest_hash13;
	HashMapTest_hashValues[13] = HashMapTest_hash14;
	HashMapTest_hashValues[14] = HashMapTest_hash15;
	HashMapTest_hashValues[15] = HashMapTest_hash16;
	HashMapTest_hashValues[16] = HashMapTest_hash17;
	HashMapTest_hashValues[17] = HashMapTest_hash18;
	HashMapTest_hashValues[18] = HashMapTest_hash19;
	HashMapTest_hashValues[19] = HashMapTest_hash20;
	HashMapTest_hashValues[20] = HashMapTest_hash21;
	HashMapTest_hashValues[21] = HashMapTest_hash22;
	HashMapTest_hashValues[22] = HashMapTest_hash23;
	HashMapTest_hashValues[23] = HashMapTest_hash24;
	HashMapTest_hashValues[24] = HashMapTest_hash25;
	HashMapTest_hashValues[25] = HashMapTest_hash26;
	HashMapTest_hashValues[26] = HashMapTest_hash27;
	HashMapTest_hashValues[27] = HashMapTest_hash28;
	HashMapTest_hashValues[28] = HashMapTest_hash29;
	HashMapTest_hashValues[29] = HashMapTest_hash30;
	HashMapTest_hashValues[30] = HashMapTest_hash31;
	HashMapTest_hashValues[31] = HashMapTest_hash32;
	HashMapTest_hashValues[32] = HashMapTest_hash33;
	HashMapTest_hashValues[33] = HashMapTest_hash34;
	HashMapTest_hashValues[34] = HashMapTest_hash35;
	HashMapTest_hashValues[35] = HashMapTest_hash36;
	HashMapTest_hashValues[36] = HashMapTest_hash37;
	HashMapTest_hashValues[37] = HashMapTest_hash38;
	HashMapTest_hashValues[38] = HashMapTest_hash39;
	HashMapTest_hashValues[39] = HashMapTest_hash40;
	HashMapTest_hashValues[40] = HashMapTest_hash41;
	HashMapTest_hashValues[41] = HashMapTest_hash42;
	HashMapTest_hashValues[42] = HashMapTest_hash43;
	HashMapTest_hashValues[43] = HashMapTest_hash44;
	HashMapTest_hashValues[44] = HashMapTest_hash45;
	HashMapTest_hashValues[45] = HashMapTest_hash46;
	HashMapTest_hashValues[46] = HashMapTest_hash47;
	HashMapTest_hashValues[47] = HashMapTest_hash48;
	HashMapTest_hashValues[48] = HashMapTest_hash49;
	HashMapTest_hashValues[49] = HashMapTest_hash50;
	HashMapTest_hashValues[50] = HashMapTest_hash51;
	HashMapTest_hashValues[51] = HashMapTest_hash52;
	HashMapTest_hashValues[52] = HashMapTest_hash53;
	HashMapTest_hashValues[53] = HashMapTest_hash54;
	HashMapTest_hashValues[54] = HashMapTest_hash55;
	HashMapTest_hashValues[55] = HashMapTest_hash56;
	HashMapTest_hashValues[56] = HashMapTest_hash57;
	HashMapTest_hashValues[57] = HashMapTest_hash58;
	HashMapTest_hashValues[58] = HashMapTest_hash59;
	HashMapTest_hashValues[59] = HashMapTest_hash60;
	Out_String((CHAR*)"Creating HashTable with capacity 100", 37);
	Out_Ln();
	HashMapTest_hTable1 = HashMap_Create(100);
	__NEW(HashMapTest_key1, HashMapTest_HKeyDesc);
	HashMapTest_key1->key = 1;
	HashMapTest_adr1 = (INT64)(ADDRESS)HashMapTest_key1;
	HashMapTest_hash1 = HashMap_HashFunction((void*)HashMapTest_key1, 100);
	__NEW(HashMapTest_key2, HashMapTest_HKeyDesc);
	HashMapTest_key2->key = 2;
	HashMapTest_adr2 = (INT64)(ADDRESS)HashMapTest_key2;
	HashMapTest_hash2 = HashMap_HashFunction((void*)HashMapTest_key2, 100);
	__NEW(HashMapTest_key3, HashMapTest_HKeyDesc);
	HashMapTest_key3->key = 3;
	HashMapTest_adr3 = (INT64)(ADDRESS)HashMapTest_key3;
	HashMapTest_hash3 = HashMap_HashFunction((void*)HashMapTest_key3, 100);
	__NEW(HashMapTest_key4, HashMapTest_HKeyDesc);
	HashMapTest_key4->key = 4;
	HashMapTest_adr4 = (INT64)(ADDRESS)HashMapTest_key4;
	HashMapTest_hash4 = HashMap_HashFunction((void*)HashMapTest_key4, 100);
	__NEW(HashMapTest_key5, HashMapTest_HKeyDesc);
	HashMapTest_key5->key = 5;
	HashMapTest_adr5 = (INT64)(ADDRESS)HashMapTest_key5;
	HashMapTest_hash5 = HashMap_HashFunction((void*)HashMapTest_key5, 100);
	__NEW(HashMapTest_key6, HashMapTest_HKeyDesc);
	HashMapTest_key6->key = 6;
	HashMapTest_adr6 = (INT64)(ADDRESS)HashMapTest_key6;
	HashMapTest_hash6 = HashMap_HashFunction((void*)HashMapTest_key6, 100);
	__NEW(HashMapTest_key7, HashMapTest_HKeyDesc);
	HashMapTest_key7->key = 7;
	HashMapTest_adr7 = (INT64)(ADDRESS)HashMapTest_key7;
	HashMapTest_hash7 = HashMap_HashFunction((void*)HashMapTest_key7, 100);
	__NEW(HashMapTest_key8, HashMapTest_HKeyDesc);
	HashMapTest_key8->key = 8;
	HashMapTest_adr8 = (INT64)(ADDRESS)HashMapTest_key8;
	HashMapTest_hash8 = HashMap_HashFunction((void*)HashMapTest_key8, 100);
	__NEW(HashMapTest_key9, HashMapTest_HKeyDesc);
	HashMapTest_key9->key = 9;
	HashMapTest_adr9 = (INT64)(ADDRESS)HashMapTest_key9;
	HashMapTest_hash9 = HashMap_HashFunction((void*)HashMapTest_key9, 100);
	__NEW(HashMapTest_key10, HashMapTest_HKeyDesc);
	HashMapTest_key10->key = 10;
	HashMapTest_adr10 = (INT64)(ADDRESS)HashMapTest_key10;
	HashMapTest_hash10 = HashMap_HashFunction((void*)HashMapTest_key10, 100);
	__NEW(HashMapTest_key11, HashMapTest_HKeyDesc);
	HashMapTest_key11->key = 11;
	HashMapTest_adr11 = (INT64)(ADDRESS)HashMapTest_key11;
	HashMapTest_hash11 = HashMap_HashFunction((void*)HashMapTest_key11, 100);
	__NEW(HashMapTest_key12, HashMapTest_HKeyDesc);
	HashMapTest_key12->key = 12;
	HashMapTest_adr12 = (INT64)(ADDRESS)HashMapTest_key12;
	HashMapTest_hash12 = HashMap_HashFunction((void*)HashMapTest_key12, 100);
	__NEW(HashMapTest_key13, HashMapTest_HKeyDesc);
	HashMapTest_key13->key = 13;
	HashMapTest_adr13 = (INT64)(ADDRESS)HashMapTest_key13;
	HashMapTest_hash13 = HashMap_HashFunction((void*)HashMapTest_key13, 100);
	__NEW(HashMapTest_key14, HashMapTest_HKeyDesc);
	HashMapTest_key14->key = 14;
	HashMapTest_adr14 = (INT64)(ADDRESS)HashMapTest_key14;
	HashMapTest_hash14 = HashMap_HashFunction((void*)HashMapTest_key14, 100);
	__NEW(HashMapTest_key15, HashMapTest_HKeyDesc);
	HashMapTest_key15->key = 15;
	HashMapTest_adr15 = (INT64)(ADDRESS)HashMapTest_key15;
	HashMapTest_hash15 = HashMap_HashFunction((void*)HashMapTest_key15, 100);
	__NEW(HashMapTest_key16, HashMapTest_HKeyDesc);
	HashMapTest_key16->key = 16;
	HashMapTest_adr16 = (INT64)(ADDRESS)HashMapTest_key16;
	HashMapTest_hash16 = HashMap_HashFunction((void*)HashMapTest_key16, 100);
	__NEW(HashMapTest_key17, HashMapTest_HKeyDesc);
	HashMapTest_key17->key = 17;
	HashMapTest_adr17 = (INT64)(ADDRESS)HashMapTest_key17;
	HashMapTest_hash17 = HashMap_HashFunction((void*)HashMapTest_key17, 100);
	__NEW(HashMapTest_key18, HashMapTest_HKeyDesc);
	HashMapTest_key18->key = 18;
	HashMapTest_adr18 = (INT64)(ADDRESS)HashMapTest_key18;
	HashMapTest_hash18 = HashMap_HashFunction((void*)HashMapTest_key18, 100);
	__NEW(HashMapTest_key19, HashMapTest_HKeyDesc);
	HashMapTest_key19->key = 19;
	HashMapTest_adr19 = (INT64)(ADDRESS)HashMapTest_key19;
	HashMapTest_hash19 = HashMap_HashFunction((void*)HashMapTest_key19, 100);
	__NEW(HashMapTest_key20, HashMapTest_HKeyDesc);
	HashMapTest_key20->key = 20;
	HashMapTest_adr20 = (INT64)(ADDRESS)HashMapTest_key20;
	HashMapTest_hash20 = HashMap_HashFunction((void*)HashMapTest_key20, 100);
	__NEW(HashMapTest_key21, HashMapTest_HKeyDesc);
	HashMapTest_key21->key = 21;
	HashMapTest_adr21 = (INT64)(ADDRESS)HashMapTest_key21;
	HashMapTest_hash21 = HashMap_HashFunction((void*)HashMapTest_key21, 100);
	__NEW(HashMapTest_key22, HashMapTest_HKeyDesc);
	HashMapTest_key22->key = 22;
	HashMapTest_adr22 = (INT64)(ADDRESS)HashMapTest_key22;
	HashMapTest_hash22 = HashMap_HashFunction((void*)HashMapTest_key22, 100);
	__NEW(HashMapTest_key23, HashMapTest_HKeyDesc);
	HashMapTest_key23->key = 23;
	HashMapTest_adr23 = (INT64)(ADDRESS)HashMapTest_key23;
	HashMapTest_hash23 = HashMap_HashFunction((void*)HashMapTest_key23, 100);
	__NEW(HashMapTest_key24, HashMapTest_HKeyDesc);
	HashMapTest_key24->key = 24;
	HashMapTest_adr24 = (INT64)(ADDRESS)HashMapTest_key24;
	HashMapTest_hash24 = HashMap_HashFunction((void*)HashMapTest_key24, 100);
	__NEW(HashMapTest_key25, HashMapTest_HKeyDesc);
	HashMapTest_key25->key = 25;
	HashMapTest_adr25 = (INT64)(ADDRESS)HashMapTest_key25;
	HashMapTest_hash25 = HashMap_HashFunction((void*)HashMapTest_key25, 100);
	__NEW(HashMapTest_key26, HashMapTest_HKeyDesc);
	HashMapTest_key26->key = 26;
	HashMapTest_adr26 = (INT64)(ADDRESS)HashMapTest_key26;
	HashMapTest_hash26 = HashMap_HashFunction((void*)HashMapTest_key26, 100);
	__NEW(HashMapTest_key27, HashMapTest_HKeyDesc);
	HashMapTest_key27->key = 27;
	HashMapTest_adr27 = (INT64)(ADDRESS)HashMapTest_key27;
	HashMapTest_hash27 = HashMap_HashFunction((void*)HashMapTest_key27, 100);
	__NEW(HashMapTest_key28, HashMapTest_HKeyDesc);
	HashMapTest_key28->key = 28;
	HashMapTest_adr28 = (INT64)(ADDRESS)HashMapTest_key28;
	HashMapTest_hash28 = HashMap_HashFunction((void*)HashMapTest_key28, 100);
	__NEW(HashMapTest_key29, HashMapTest_HKeyDesc);
	HashMapTest_key29->key = 29;
	HashMapTest_adr29 = (INT64)(ADDRESS)HashMapTest_key29;
	HashMapTest_hash29 = HashMap_HashFunction((void*)HashMapTest_key29, 100);
	HashMapTest_hashValues[0] = HashMapTest_hash1;
	HashMapTest_hashValues[1] = HashMapTest_hash2;
	HashMapTest_hashValues[2] = HashMapTest_hash3;
	HashMapTest_hashValues[3] = HashMapTest_hash4;
	HashMapTest_hashValues[4] = HashMapTest_hash5;
	HashMapTest_hashValues[5] = HashMapTest_hash6;
	HashMapTest_hashValues[6] = HashMapTest_hash7;
	HashMapTest_hashValues[7] = HashMapTest_hash8;
	HashMapTest_hashValues[8] = HashMapTest_hash9;
	HashMapTest_hashValues[9] = HashMapTest_hash10;
	HashMapTest_hashValues[10] = HashMapTest_hash11;
	HashMapTest_hashValues[11] = HashMapTest_hash12;
	HashMapTest_hashValues[12] = HashMapTest_hash13;
	HashMapTest_hashValues[13] = HashMapTest_hash14;
	HashMapTest_hashValues[14] = HashMapTest_hash15;
	HashMapTest_hashValues[15] = HashMapTest_hash16;
	HashMapTest_hashValues[16] = HashMapTest_hash17;
	HashMapTest_hashValues[17] = HashMapTest_hash18;
	HashMapTest_hashValues[18] = HashMapTest_hash19;
	HashMapTest_hashValues[19] = HashMapTest_hash20;
	HashMapTest_hashValues[20] = HashMapTest_hash21;
	HashMapTest_hashValues[21] = HashMapTest_hash22;
	HashMapTest_hashValues[22] = HashMapTest_hash23;
	HashMapTest_hashValues[23] = HashMapTest_hash24;
	HashMapTest_hashValues[24] = HashMapTest_hash25;
	HashMapTest_hashValues[25] = HashMapTest_hash26;
	HashMapTest_hashValues[26] = HashMapTest_hash27;
	HashMapTest_hashValues[27] = HashMapTest_hash28;
	HashMapTest_hashValues[28] = HashMapTest_hash29;
	HashMapTest_hashValues[29] = HashMapTest_hash30;
	HashMapTest_i = 0;
	while (HashMapTest_i <= 29) {
		HashMapTest_j = HashMapTest_i;
		while (HashMapTest_j <= 29) {
			if (HashMapTest_i != HashMapTest_j) {
				if (HashMapTest_hashValues[__X(HashMapTest_i, 100)] == HashMapTest_hashValues[__X(HashMapTest_j, 100)]) {
					Out_String((CHAR*)"hash", 5);
					Out_Int(HashMapTest_i + 1, 0);
					Out_String((CHAR*)" is equal to hash", 18);
					Out_Int(HashMapTest_j + 1, 0);
					Out_Ln();
				}
			}
			HashMapTest_j += 1;
		}
		HashMapTest_i += 1;
	}
	__FINI;
}
