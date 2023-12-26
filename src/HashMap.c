/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "DynamicArray.h"
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
	struct {
		ADDRESS len[1];
		HashMap_KObject data[1];
	} *HashMap_kObjectArray;

typedef
	struct {
		ADDRESS len[1];
		HashMap_VObject data[1];
	} *HashMap_vObjectArray;

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
		HashMap_MapEntry entry;
		HashMap_Node next;
	} HashMap_NodeDesc;

typedef
	struct HashMap_VObjectDesc { /* HashMap_NObjectDesc */
		char _prvt0[1];
	} HashMap_VObjectDesc;



export ADDRESS *HashMap_NObjectDesc__typ;
export ADDRESS *HashMap_KObjectDesc__typ;
export ADDRESS *HashMap_VObjectDesc__typ;
export ADDRESS *HashMap_MapEntryDesc__typ;
export ADDRESS *HashMap_NodeDesc__typ;
export ADDRESS *HashMap_HashTableDesc__typ;

export void HashMap_AddOrReplace (HashMap_HashTable h, HashMap_KObject key, HashMap_VObject value);
static INT16 HashMap_CompressHash (INT64 hash, INT16 range);
export HashMap_HashTable HashMap_Create (INT16 size);
export HashMap_VObject HashMap_Get (HashMap_HashTable h, HashMap_KObject key);
static INT64 HashMap_HashCode (HashMap_KObject key);
static INT16 HashMap_HashFunction (HashMap_KObject key, INT16 range);
export BOOLEAN HashMap_IsEmpty (HashMap_HashTable h);
static BOOLEAN HashMap_IsPrime (INT16 n);
export HashMap_kObjectArray HashMap_Keys (HashMap_HashTable h);
static INT16 HashMap_NextPrime (INT16 n);
export INT16 HashMap_NumberOfElements (HashMap_HashTable h);
static INT64 HashMap_Power (INT16 base, INT16 exponent);
export HashMap_VObject HashMap_Remove (HashMap_HashTable h, HashMap_KObject key);
static void HashMap_Resize (HashMap_HashTable h);
export HashMap_vObjectArray HashMap_Values (HashMap_HashTable h);


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
	INT64 a, b, prime, result;
	INT16 returnVal;
	a = 11;
	b = 17;
	prime = HashMap_NextPrime(range);
	result = a * hash + b;
	result = __MOD(result, prime);
	returnVal = __VAL(INT16, result);
	return returnVal;
}

static INT16 HashMap_HashFunction (HashMap_KObject key, INT16 range)
{
	INT64 hash;
	INT16 returnVal;
	hash = HashMap_HashCode(key);
	returnVal = HashMap_CompressHash(hash, range);
	return returnVal;
}

HashMap_VObject HashMap_Get (HashMap_HashTable h, HashMap_KObject key)
{
	INT16 index;
	HashMap_NObject node = NIL;
	HashMap_MapEntry entry = NIL;
	HashMap_Node aNode = NIL;
	index = HashMap_HashFunction(key, h->capacity);
	node = (h->container->data)[__X(index, h->container->len[0])];
	while (node != NIL) {
		aNode = __GUARDP(node, HashMap_NodeDesc, 1);
		entry = aNode->entry;
		if (entry->key == key) {
			return entry->value;
		}
		node = (HashMap_NObject)aNode->next;
	}
	return NIL;
}

static void HashMap_Resize (HashMap_HashTable h)
{
	INT16 newSize;
	HashMap_hcontainer newContainer = NIL;
	INT16 i;
	HashMap_NObject node = NIL;
	HashMap_Node aNode = NIL;
	HashMap_MapEntry entry = NIL;
	INT16 newIndex, _for__17;
	newSize = HashMap_NextPrime(__ASHL(h->capacity, 1));
	newContainer = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(newSize)));
	_for__17 = h->capacity;
	i = 0;
	while (i <= _for__17) {
		node = (h->container->data)[__X(i, h->container->len[0])];
		aNode = __GUARDP(node, HashMap_NodeDesc, 1);
		while (aNode != NIL) {
			entry = aNode->entry;
			newIndex = HashMap_HashFunction(entry->key, newSize);
			if ((newContainer->data)[__X(newIndex, newContainer->len[0])] == NIL) {
				(newContainer->data)[__X(newIndex, newContainer->len[0])] = (HashMap_NObject)aNode;
			} else {
				node = (newContainer->data)[__X(newIndex, newContainer->len[0])];
				aNode->next = __GUARDP(node, HashMap_NodeDesc, 1);
				(newContainer->data)[__X(newIndex, newContainer->len[0])] = (HashMap_NObject)aNode;
			}
			aNode = aNode->next;
		}
		i += 1;
	}
	h->container = newContainer;
	h->capacity = newSize;
}

void HashMap_AddOrReplace (HashMap_HashTable h, HashMap_KObject key, HashMap_VObject value)
{
	INT16 index;
	HashMap_NObject node = NIL;
	HashMap_MapEntry entry = NIL;
	HashMap_Node aNode = NIL;
	if (h->numberOfElements == __ASHR(h->capacity, 1)) {
		HashMap_Resize(h);
	}
	index = HashMap_HashFunction(key, h->capacity);
	node = (h->container->data)[__X(index, h->container->len[0])];
	if (node == NIL) {
		__NEW(aNode, HashMap_NodeDesc);
		__NEW(entry, HashMap_MapEntryDesc);
		entry->key = key;
		entry->value = value;
		aNode->entry = entry;
		aNode->next = NIL;
		(h->container->data)[__X(index, h->container->len[0])] = (HashMap_NObject)aNode;
		h->numberOfElements += 1;
		return;
	} else {
		while (node != NIL) {
			aNode = __GUARDP(node, HashMap_NodeDesc, 1);
			entry = aNode->entry;
			if (entry->key == key) {
				entry->value = value;
				return;
			}
			node = (HashMap_NObject)aNode->next;
		}
		__NEW(aNode, HashMap_NodeDesc);
		__NEW(entry, HashMap_MapEntryDesc);
		entry->key = key;
		entry->value = value;
		aNode->entry = entry;
		node = (h->container->data)[__X(index, h->container->len[0])];
		aNode->next = __GUARDP(node, HashMap_NodeDesc, 1);
		(h->container->data)[__X(index, h->container->len[0])] = (HashMap_NObject)aNode;
		h->numberOfElements += 1;
	}
}

HashMap_VObject HashMap_Remove (HashMap_HashTable h, HashMap_KObject key)
{
	INT16 index;
	HashMap_NObject node = NIL;
	HashMap_MapEntry entry = NIL;
	HashMap_Node aNode = NIL;
	index = HashMap_HashFunction(key, h->capacity);
	node = (h->container->data)[__X(index, h->container->len[0])];
	if (node == NIL) {
		return NIL;
	} else {
		while (node != NIL) {
			aNode = __GUARDP(node, HashMap_NodeDesc, 1);
			entry = aNode->entry;
			if (entry->key == key) {
				(h->container->data)[__X(index, h->container->len[0])] = (HashMap_NObject)aNode->next;
				h->numberOfElements -= 1;
				return entry->value;
			}
			node = (HashMap_NObject)aNode->next;
		}
		return NIL;
	}
	__RETCHK;
}

HashMap_kObjectArray HashMap_Keys (HashMap_HashTable h)
{
	HashMap_kObjectArray keys = NIL;
	INT16 i, j;
	HashMap_NObject node = NIL;
	HashMap_Node aNode = NIL;
	HashMap_MapEntry entry = NIL;
	INT16 _for__10;
	keys = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(h->numberOfElements)));
	j = 0;
	_for__10 = h->capacity - 1;
	i = 0;
	while (i <= _for__10) {
		node = (h->container->data)[__X(i, h->container->len[0])];
		while (node != NIL) {
			aNode = __GUARDP(node, HashMap_NodeDesc, 1);
			entry = aNode->entry;
			(keys->data)[__X(j, keys->len[0])] = entry->key;
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
	INT16 _for__19;
	values = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(h->numberOfElements)));
	j = 0;
	_for__19 = h->capacity - 1;
	i = 0;
	while (i <= _for__19) {
		node = (h->container->data)[__X(i, h->container->len[0])];
		while (node != NIL) {
			aNode = __GUARDP(node, HashMap_NodeDesc, 1);
			entry = aNode->entry;
			(values->data)[__X(j, values->len[0])] = entry->value;
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
__TDESC(HashMap_NodeDesc, 1, 2) = {__TDFLDS("NodeDesc", 16), {0, 8, -24}};
__TDESC(HashMap_HashTableDesc, 1, 1) = {__TDFLDS("HashTableDesc", 136), {0, -16}};

export void *HashMap__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(DynamicArray);
	__MODULE_IMPORT(Math);
	__MODULE_IMPORT(Out);
	__REGMOD("HashMap", 0);
	__INITYP(HashMap_NObjectDesc, HashMap_NObjectDesc, 0);
	__INITYP(HashMap_KObjectDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_VObjectDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_MapEntryDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_NodeDesc, HashMap_NObjectDesc, 1);
	__INITYP(HashMap_HashTableDesc, HashMap_HashTableDesc, 0);
/* BEGIN */
	__ENDMOD;
}
