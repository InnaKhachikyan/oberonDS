/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#ifndef Map__h
#define Map__h

#include "SYSTEM.h"
#include "DynamicArray.h"

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



import ADDRESS *Map_KObjectDesc__typ;
import ADDRESS *Map_VObjectDesc__typ;
import ADDRESS *Map_MapEntryDesc__typ;
import ADDRESS *Map_NodeDesc__typ;
import ADDRESS *Map_MapDesc__typ;

import void Map_AddOrReplace (Map_Map h, Map_KObject key, Map_VObject value);
import Map_Map Map_Create (INT16 capacity);
import Map_VObject Map_Get (Map_Map h, Map_KObject key);
import BOOLEAN Map_IsEmpty (Map_Map h);
import INT16 Map_NumberOfElements (Map_Map h);
import Map_VObject Map_Remove (Map_Map h, Map_KObject key);
import void *Map__init(void);


#endif // Map
