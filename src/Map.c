/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "DynamicArray.h"
#include "Out.h"

typedef
	struct Map_KObjectDesc *Map_KObject;

typedef
	struct Map_KObjectDesc {
		char _prvt0[1];
	} Map_KObjectDesc;

typedef
	struct Map_MapDesc *Map_Map;

typedef
	struct Map_VObjectDesc *Map_VObject;

typedef
	struct Map_MapDesc {
		DynamicArray_DArray container;
		Map_Map (*Create)(INT16);
		INT16 (*NumberOfElements)(Map_Map);
		BOOLEAN (*IsEmpty)(Map_Map);
		Map_VObject (*Get)(Map_Map, Map_KObject);
		void (*AddOrReplace)(Map_Map, Map_KObject, Map_VObject);
		Map_VObject (*Remove)(Map_Map, Map_KObject);
	} Map_MapDesc;

typedef
	struct Map_MapEntryDesc *Map_MapEntry;

typedef
	struct Map_MapEntryDesc {
		Map_KObject key;
		Map_VObject value;
	} Map_MapEntryDesc;

typedef
	struct Map_NodeDesc *Map_Node;

typedef
	struct Map_NodeDesc { /* DynamicArray_AObjectDesc */
		Map_MapEntry entry;
		Map_Node next;
	} Map_NodeDesc;

typedef
	struct Map_VObjectDesc {
		char _prvt0[1];
	} Map_VObjectDesc;



export ADDRESS *Map_KObjectDesc__typ;
export ADDRESS *Map_VObjectDesc__typ;
export ADDRESS *Map_MapEntryDesc__typ;
export ADDRESS *Map_NodeDesc__typ;
export ADDRESS *Map_MapDesc__typ;

export void Map_AddOrReplace (Map_Map h, Map_KObject key, Map_VObject value);
export Map_Map Map_Create (INT16 capacity);
export Map_VObject Map_Get (Map_Map h, Map_KObject key);
export BOOLEAN Map_IsEmpty (Map_Map h);
export INT16 Map_NumberOfElements (Map_Map h);
export Map_VObject Map_Remove (Map_Map h, Map_KObject key);


Map_Map Map_Create (INT16 capacity)
{
	Map_Map h = NIL;
	__NEW(h, Map_MapDesc);
	h->container = DynamicArray_Create(capacity);
	return h;
}

INT16 Map_NumberOfElements (Map_Map h)
{
	return h->container->numberOfElements;
}

BOOLEAN Map_IsEmpty (Map_Map h)
{
	return h->container->numberOfElements == 0;
}

Map_VObject Map_Get (Map_Map h, Map_KObject key)
{
	INT16 i;
	DynamicArray_AObject node = NIL;
	Map_MapEntry entry = NIL;
	INT16 _for__4;
	_for__4 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__4) {
		node = DynamicArray_Get(h->container, i);
		entry = __GUARDP(node, Map_NodeDesc, 1)->entry;
		if (entry->key == key) {
			return entry->value;
		}
		i += 1;
	}
	return NIL;
}

void Map_AddOrReplace (Map_Map h, Map_KObject key, Map_VObject value)
{
	INT16 i;
	DynamicArray_AObject node = NIL;
	Map_MapEntry entry = NIL;
	__NEW(node, DynamicArray_AObjectDesc);
	__NEW(entry, Map_MapEntryDesc);
	entry->key = key;
	entry->value = value;
	__GUARDP(node, Map_NodeDesc, 1)->entry = entry;
	DynamicArray_Add(h->container, node);
}

Map_VObject Map_Remove (Map_Map h, Map_KObject key)
{
	INT16 i;
	DynamicArray_AObject node = NIL;
	Map_MapEntry entry = NIL;
	INT16 _for__8;
	_for__8 = h->container->numberOfElements - 1;
	i = 0;
	while (i <= _for__8) {
		node = DynamicArray_Get(h->container, i);
		entry = __GUARDP(node, Map_NodeDesc, 1)->entry;
		if (entry->key == key) {
			node = DynamicArray_Delete(h->container, i);
			return entry->value;
		}
		i += 1;
	}
	return NIL;
}

__TDESC(Map_KObjectDesc, 1, 0) = {__TDFLDS("KObjectDesc", 1), {-8}};
__TDESC(Map_VObjectDesc, 1, 0) = {__TDFLDS("VObjectDesc", 1), {-8}};
__TDESC(Map_MapEntryDesc, 1, 2) = {__TDFLDS("MapEntryDesc", 16), {0, 8, -24}};
__TDESC(Map_NodeDesc, 1, 2) = {__TDFLDS("NodeDesc", 16), {0, 8, -24}};
__TDESC(Map_MapDesc, 1, 1) = {__TDFLDS("MapDesc", 56), {0, -16}};

export void *Map__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(DynamicArray);
	__MODULE_IMPORT(Out);
	__REGMOD("Map", 0);
	__INITYP(Map_KObjectDesc, Map_KObjectDesc, 0);
	__INITYP(Map_VObjectDesc, Map_VObjectDesc, 0);
	__INITYP(Map_MapEntryDesc, Map_MapEntryDesc, 0);
	__INITYP(Map_NodeDesc, DynamicArray_AObjectDesc, 1);
	__INITYP(Map_MapDesc, Map_MapDesc, 0);
/* BEGIN */
	__ENDMOD;
}
