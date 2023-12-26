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
	struct Map_KObjectDesc *Map_KObject;

typedef
	struct Map_KObjectDesc { /* DynamicArray_AObjectDesc */
		char _prvt0[1];
	} Map_KObjectDesc;

typedef
	struct Map_KVMapDesc *Map_KVMap;

typedef
	struct Map_VObjectDesc *Map_VObject;

typedef
	struct Map_KVMapDesc {
		DynamicArray_DArray container;
		Map_KVMap (*Create)(INT16);
		INT16 (*NumberOfElements)(Map_KVMap);
		BOOLEAN (*IsEmpty)(Map_KVMap);
		Map_VObject (*Get)(Map_KVMap, Map_KObject);
		void (*AddOrReplace)(Map_KVMap, Map_KObject, Map_VObject);
		Map_VObject (*Remove)(Map_KVMap, Map_KObject);
		DynamicArray_DArray (*Keys)(Map_KVMap);
		DynamicArray_DArray (*Values)(Map_KVMap);
	} Map_KVMapDesc;

typedef
	struct Map_MapEntryDesc *Map_MapEntry;

typedef
	struct Map_MapEntryDesc { /* DynamicArray_AObjectDesc */
		Map_KObject key;
		Map_VObject value;
	} Map_MapEntryDesc;

typedef
	struct Map_VObjectDesc { /* DynamicArray_AObjectDesc */
		char _prvt0[1];
	} Map_VObjectDesc;



export ADDRESS *Map_KObjectDesc__typ;
export ADDRESS *Map_VObjectDesc__typ;
export ADDRESS *Map_MapEntryDesc__typ;
export ADDRESS *Map_KVMapDesc__typ;

export void Map_AddOrReplace (Map_KVMap h, Map_KObject key, Map_VObject value);
export Map_KVMap Map_Create (INT16 capacity);
export Map_VObject Map_Get (Map_KVMap h, Map_KObject key);
export BOOLEAN Map_IsEmpty (Map_KVMap h);
export DynamicArray_DArray Map_Keys (Map_KVMap h);
export INT16 Map_NumberOfElements (Map_KVMap h);
export Map_VObject Map_Remove (Map_KVMap h, Map_KObject key);
export DynamicArray_DArray Map_Values (Map_KVMap h);


Map_KVMap Map_Create (INT16 capacity)
{
	Map_KVMap h = NIL;
	__NEW(h, Map_KVMapDesc);
	h->container = DynamicArray_Create(capacity);
	return h;
}

INT16 Map_NumberOfElements (Map_KVMap h)
{
	return h->container->numberOfElements;
}

BOOLEAN Map_IsEmpty (Map_KVMap h)
{
	return h->container->numberOfElements == 0;
}

Map_VObject Map_Get (Map_KVMap h, Map_KObject key)
{
	INT16 i;
	DynamicArray_AObject entry = NIL;
	INT16 _for__5;
	_for__5 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__5) {
		entry = DynamicArray_Get(h->container, i);
		if (__GUARDP(entry, Map_MapEntryDesc, 1)->key == key) {
			return __GUARDP(entry, Map_MapEntryDesc, 1)->value;
		}
		i += 1;
	}
	return NIL;
}

void Map_AddOrReplace (Map_KVMap h, Map_KObject key, Map_VObject value)
{
	INT16 i;
	DynamicArray_AObject aEntry = NIL;
	Map_MapEntry entry = NIL;
	INT16 _for__2;
	_for__2 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__2) {
		aEntry = DynamicArray_Get(h->container, i);
		if (__GUARDP(aEntry, Map_MapEntryDesc, 1)->key == key) {
			entry->value = value;
			return;
		}
		i += 1;
	}
	__NEW(entry, Map_MapEntryDesc);
	entry->key = key;
	entry->value = value;
	DynamicArray_Add(h->container, (void*)entry);
}

Map_VObject Map_Remove (Map_KVMap h, Map_KObject key)
{
	INT16 i;
	DynamicArray_AObject aEntry = NIL;
	INT16 _for__11;
	_for__11 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__11) {
		aEntry = DynamicArray_Get(h->container, i);
		if (__GUARDP(aEntry, Map_MapEntryDesc, 1)->key == key) {
			aEntry = DynamicArray_Delete(h->container, i);
			return __GUARDP(aEntry, Map_MapEntryDesc, 1)->value;
		}
		i += 1;
	}
	return NIL;
}

DynamicArray_DArray Map_Keys (Map_KVMap h)
{
	INT16 i;
	DynamicArray_AObject entry = NIL;
	DynamicArray_DArray keys = NIL;
	INT16 _for__8;
	keys = DynamicArray_Create(h->container->numberOfElements);
	_for__8 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__8) {
		entry = DynamicArray_Get(h->container, i);
		DynamicArray_Add(keys, (void*)__GUARDP(entry, Map_MapEntryDesc, 1)->key);
		i += 1;
	}
	return keys;
}

DynamicArray_DArray Map_Values (Map_KVMap h)
{
	INT16 i;
	DynamicArray_AObject entry = NIL;
	DynamicArray_DArray values = NIL;
	INT16 _for__13;
	values = DynamicArray_Create(h->container->numberOfElements);
	_for__13 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__13) {
		entry = DynamicArray_Get(h->container, i);
		DynamicArray_Add(values, (void*)__GUARDP(entry, Map_MapEntryDesc, 1)->value);
		i += 1;
	}
	return values;
}

__TDESC(Map_KObjectDesc, 1, 0) = {__TDFLDS("KObjectDesc", 1), {-8}};
__TDESC(Map_VObjectDesc, 1, 0) = {__TDFLDS("VObjectDesc", 1), {-8}};
__TDESC(Map_MapEntryDesc, 1, 2) = {__TDFLDS("MapEntryDesc", 16), {0, 8, -24}};
__TDESC(Map_KVMapDesc, 1, 1) = {__TDFLDS("KVMapDesc", 72), {0, -16}};

export void *Map__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(DynamicArray);
	__MODULE_IMPORT(Math);
	__MODULE_IMPORT(Out);
	__REGMOD("Map", 0);
	__INITYP(Map_KObjectDesc, DynamicArray_AObjectDesc, 1);
	__INITYP(Map_VObjectDesc, DynamicArray_AObjectDesc, 1);
	__INITYP(Map_MapEntryDesc, DynamicArray_AObjectDesc, 1);
	__INITYP(Map_KVMapDesc, Map_KVMapDesc, 0);
/* BEGIN */
	__ENDMOD;
}
