/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "Math.h"
#include "Out.h"

typedef
	struct HashMap_HashTableDesc *HashMap_HashTable;

typedef
	struct HashMap_NObjectDesc *HashMap_NObject;

typedef
	struct {
		ADDRESS len[1];
		HashMap_NObject data[1];
	} *HashMap_hcontainer;

typedef
	struct HashMap_KObjectDesc *HashMap_KObject;

typedef
	struct HashMap_VObjectDesc *HashMap_VObject;

typedef
	struct HashMap_kObjectArrayDesc *HashMap_kObjectArray;

typedef
	struct HashMap_vObjectArrayDesc *HashMap_vObjectArray;

typedef
	struct HashMap_HashTableDesc {
		HashMap_hcontainer container;
		HashMap_HashTable (*Create)(INT16);
		INT16 (*NumberOfElements)(HashMap_HashTable);
		BOOLEAN (*IsEmpty)(HashMap_HashTable);
		BOOLEAN (*IsPrime)(INT16);
		INT64 (*Power)(INT16, INT16);
		INT16 (*NextPrime)(INT16);
		INT64 (*HashCode)(HashMap_KObject);
		INT16 (*CompressHash)(INT64, INT16);
		INT16 (*HashFunction)(HashMap_KObject, INT16);
		HashMap_VObject (*Get)(HashMap_HashTable, HashMap_KObject);
		void (*AddOrReplace)(HashMap_HashTable, HashMap_KObject, HashMap_VObject);
		HashMap_VObject (*Remove)(HashMap_HashTable, HashMap_KObject);
		HashMap_kObjectArray (*Keys)(HashMap_HashTable);
		HashMap_vObjectArray (*Values)(HashMap_HashTable);
		void (*Resize)(HashMap_HashTable);
		INT16 numberOfElements, capacity;
	} HashMap_HashTableDesc;

typedef
	struct HashMap_NObjectDesc {
		char _prvt0[1];
	} HashMap_NObjectDesc;

typedef
	struct HashMap_KObjectDesc { /* HashMap_NObjectDesc */
		char _prvt0[1];
	} HashMap_KObjectDesc;

typedef
	struct HashMap_MapEntryDesc *HashMap_MapEntry;

typedef
	struct HashMap_MapEntryDesc { /* HashMap_NObjectDesc */
		HashMap_KObject key;
		HashMap_VObject value;
	} HashMap_MapEntryDesc;

typedef
	struct HashMap_NodeDesc *HashMap_Node;

typedef
	struct HashMap_NodeDesc { /* HashMap_NObjectDesc */
		HashMap_Node (*CreateNode)(HashMap_MapEntry);
		HashMap_MapEntry entry;
		HashMap_Node next;
	} HashMap_NodeDesc;

typedef
	struct HashMap_VObjectDesc { /* HashMap_NObjectDesc */
		char _prvt0[1];
	} HashMap_VObjectDesc;

typedef
	struct HashMap_kObjectArrayDesc {
		HashMap_kObjectArray (*CreateKObjectArray)(INT16);
		INT16 capacity;
		struct {
			ADDRESS len[1];
			HashMap_KObject data[1];
		} *container;
	} HashMap_kObjectArrayDesc;

typedef
	struct HashMap_vObjectArrayDesc {
		HashMap_vObjectArray (*CreateVObjectArray)(INT16);
		INT16 capacity;
		struct {
			ADDRESS len[1];
			HashMap_VObject data[1];
		} *container;
	} HashMap_vObjectArrayDesc;



export ADDRESS *HashMap_NObjectDesc__typ;
export ADDRESS *HashMap_KObjectDesc__typ;
export ADDRESS *HashMap_VObjectDesc__typ;
export ADDRESS *HashMap_MapEntryDesc__typ;
export ADDRESS *HashMap_NodeDesc__typ;
export ADDRESS *HashMap_kObjectArrayDesc__typ;
export ADDRESS *HashMap_vObjectArrayDesc__typ;
export ADDRESS *HashMap_HashTableDesc__typ;

static INT16 HashMap_CompressHash (INT64 hash, INT16 range);
export HashMap_HashTable HashMap_Create (INT16 size);
static HashMap_kObjectArray HashMap_CreateKObjectArray (INT16 size);
static HashMap_vObjectArray HashMap_CreateVObjectArray (INT16 size);
static INT64 HashMap_HashCode (HashMap_KObject key);
export INT16 HashMap_HashFunction (HashMap_KObject key, INT16 range);
export BOOLEAN HashMap_IsEmpty (HashMap_HashTable h);
static BOOLEAN HashMap_IsPrime (INT16 n);
export HashMap_kObjectArray HashMap_Keys (HashMap_HashTable h);
static INT16 HashMap_NextPrime (INT16 n);
export INT16 HashMap_NumberOfElements (HashMap_HashTable h);
static INT64 HashMap_Power (INT16 base, INT16 exponent);
export HashMap_vObjectArray HashMap_Values (HashMap_HashTable h);


static HashMap_kObjectArray HashMap_CreateKObjectArray (INT16 size)
{
	HashMap_kObjectArray k = NIL;
	__NEW(k, HashMap_kObjectArrayDesc);
	k->capacity = size;
	k->container = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(k->capacity)));
	return k;
}

static HashMap_vObjectArray HashMap_CreateVObjectArray (INT16 size)
{
	HashMap_vObjectArray v = NIL;
	__NEW(v, HashMap_vObjectArrayDesc);
	v->capacity = size;
	v->container = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(v->capacity)));
	return v;
}

HashMap_HashTable HashMap_Create (INT16 size)
{
	HashMap_HashTable h = NIL;
	__NEW(h, HashMap_HashTableDesc);
	h->numberOfElements = 0;
	h->capacity = size;
	h->container = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(size)));
	return h;
}

INT16 HashMap_NumberOfElements (HashMap_HashTable h)
{
	return h->numberOfElements;
}

BOOLEAN HashMap_IsEmpty (HashMap_HashTable h)
{
	return h->numberOfElements == 0;
}

static INT64 HashMap_Power (INT16 base, INT16 exponent)
{
	INT64 i, result, _for__14;
	result = 1;
	_for__14 = exponent - 1;
	i = 0;
	while (i <= _for__14) {
		result = result * (INT64)base;
		i += 1;
	}
	return result;
}

static BOOLEAN HashMap_IsPrime (INT16 n)
{
	INT16 i, upto;
	i = 2;
	upto = (INT16)Math_sqrt(n);
	while (i <= upto) {
		if ((int)__MOD(n, i) == 0) {
			return 0;
		}
		i = i + 1;
	}
	return 1;
}

static INT16 HashMap_NextPrime (INT16 n)
{
	INT16 i;
	BOOLEAN prime;
	i = n + 1;
	while (1) {
		prime = HashMap_IsPrime(i);
		if (prime) {
			return i;
		}
		i = i + 1;
	}
	__RETCHK;
}

static INT64 HashMap_HashCode (HashMap_KObject key)
{
	INT64 adr;
	INT16 coefficient, i;
	INT64 digit, hash;
	i = 0;
	coefficient = 37;
	hash = 0;
	adr = (INT64)((ADDRESS)&key);
	Out_Ln();
	Out_String((CHAR*)"adr: ", 6);
	Out_Int(adr, 0);
	Out_Ln();
	while (adr > 0) {
		digit = __MOD(adr, 10);
		adr = __DIV(adr, 10);
		hash = hash + digit * HashMap_Power(coefficient, i);
		i = i + 1;
	}
	return hash;
}

static INT16 HashMap_CompressHash (INT64 hash, INT16 range)
{
	INT64 a, b;
	INT16 temp;
	INT64 prime, result;
	INT16 returnVal;
	a = 7681;
	b = 6983;
	temp = (INT16)(((INT64)range * a) * b);
	prime = HashMap_NextPrime(temp);
	result = a * hash + b;
	result = __MOD(result, (INT64)range);
	returnVal = __VAL(INT16, result);
	return returnVal;
}

INT16 HashMap_HashFunction (HashMap_KObject key, INT16 range)
{
	INT64 hash;
	INT16 returnVal;
	hash = HashMap_HashCode(key);
	returnVal = HashMap_CompressHash(hash, range);
	Out_String((CHAR*)"------hash: ", 13);
	Out_Int(returnVal, 0);
	Out_Ln();
	return returnVal;
}

HashMap_kObjectArray HashMap_Keys (HashMap_HashTable h)
{
	HashMap_kObjectArray keys = NIL;
	INT16 i, j;
	HashMap_NObject node = NIL;
	HashMap_Node aNode = NIL;
	HashMap_MapEntry entry = NIL;
	INT16 _for__10;
	keys = HashMap_CreateKObjectArray(h->numberOfElements);
	j = 0;
	_for__10 = h->capacity - 1;
	i = 0;
	while (i <= _for__10) {
		node = (h->container->data)[__X(i, h->container->len[0])];
		while (node != NIL) {
			aNode = __GUARDP(node, HashMap_NodeDesc, 1);
			entry = aNode->entry;
			(keys->container->data)[__X(j, keys->container->len[0])] = entry->key;
			j = j + 1;
			node = (HashMap_NObject)aNode->next;
		}
		i += 1;
	}
	return keys;
}

HashMap_vObjectArray HashMap_Values (HashMap_HashTable h)
{
	HashMap_vObjectArray values = NIL;
	INT16 i, j;
	HashMap_NObject node = NIL;
	HashMap_Node aNode = NIL;
	HashMap_MapEntry entry = NIL;
	INT16 _for__16;
	values = HashMap_CreateVObjectArray(h->numberOfElements);
	j = 0;
	_for__16 = h->capacity - 1;
	i = 0;
	while (i <= _for__16) {
		node = (h->container->data)[__X(i, h->container->len[0])];
		while (node != NIL) {
			aNode = __GUARDP(node, HashMap_NodeDesc, 1);
			entry = aNode->entry;
			(values->container->data)[__X(j, values->container->len[0])] = entry->value;
			j = j + 1;
			node = (HashMap_NObject)aNode->next;
		}
		i += 1;
	}
	return values;
}

__TDESC(HashMap_NObjectDesc, 1, 0) = {__TDFLDS("NObjectDesc", 1), {-8}};
__TDESC(HashMap_KObjectDesc, 1, 0) = {__TDFLDS("KObjectDesc", 1), {-8}};
__TDESC(HashMap_VObjectDesc, 1, 0) = {__TDFLDS("VObjectDesc", 1), {-8}};
__TDESC(HashMap_MapEntryDesc, 1, 2) = {__TDFLDS("MapEntryDesc", 16), {0, 8, -24}};
__TDESC(HashMap_NodeDesc, 1, 2) = {__TDFLDS("NodeDesc", 24), {8, 16, -24}};
__TDESC(HashMap_kObjectArrayDesc, 1, 1) = {__TDFLDS("kObjectArrayDesc", 24), {16, -16}};
__TDESC(HashMap_vObjectArrayDesc, 1, 1) = {__TDFLDS("vObjectArrayDesc", 24), {16, -16}};
__TDESC(HashMap_HashTableDesc, 1, 1) = {__TDFLDS("HashTableDesc", 136), {0, -16}};

export void *HashMap__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(Math);
	__MODULE_IMPORT(Out);
	__REGMOD("HashMap", 0);
	__INITYP(HashMap_NObjectDesc, HashMap_NObjectDesc, 0);
	__INITYP(HashMap_KObjectDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_VObjectDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_MapEntryDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_NodeDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_kObjectArrayDesc, HashMap_kObjectArrayDesc, 0);
	__INITYP(HashMap_vObjectArrayDesc, HashMap_vObjectArrayDesc, 0);
	__INITYP(HashMap_HashTableDesc, HashMap_HashTableDesc, 0);
/* BEGIN */
	__ENDMOD;
}
