/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#ifndef Map__h
#define Map__h

#include "SYSTEM.h"
#include "DynamicArray.h"

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



import ADDRESS *Map_KObjectDesc__typ;
import ADDRESS *Map_VObjectDesc__typ;
import ADDRESS *Map_MapEntryDesc__typ;
import ADDRESS *Map_KVMapDesc__typ;

import void Map_AddOrReplace (Map_KVMap h, Map_KObject key, Map_VObject value);
import Map_KVMap Map_Create (INT16 capacity);
import Map_VObject Map_Get (Map_KVMap h, Map_KObject key);
import BOOLEAN Map_IsEmpty (Map_KVMap h);
import DynamicArray_DArray Map_Keys (Map_KVMap h);
import INT16 Map_NumberOfElements (Map_KVMap h);
import Map_VObject Map_Remove (Map_KVMap h, Map_KObject key);
import DynamicArray_DArray Map_Values (Map_KVMap h);
import void *Map__init(void);


#endif // Map
