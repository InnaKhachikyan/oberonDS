/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "DynamicArray.h"

typedef
	struct HashMap_HashMapDesc *HashMap_HashMap;

typedef
	struct HashMap_TObjectDesc *HashMap_TObject;

typedef
	struct HashMap_HashMapDesc {
		DynamicArray_DArray container;
		INT16 (*size)(HashMap_HashMap);
		BOOLEAN (*isEmpty)(HashMap_HashMap);
		BOOLEAN (*containsKey)(HashMap_HashMap, HashMap_TObject);
		HashMap_TObject (*get)(HashMap_HashMap, HashMap_TObject);
		HashMap_TObject (*put)(HashMap_HashMap, HashMap_TObject, HashMap_TObject);
		HashMap_TObject (*remove)(HashMap_HashMap, HashMap_TObject);
	} HashMap_HashMapDesc;

typedef
	struct HashMap_HashMapEntryDesc *HashMap_HashMapEntry;

typedef
	struct HashMap_HashMapEntryDesc {
		HashMap_TObject key, value;
	} HashMap_HashMapEntryDesc;

typedef
	struct HashMap_NodeDesc *HashMap_Node;

typedef
	struct HashMap_NodeDesc { /* DynamicArray_AObjectDesc */
		HashMap_HashMapEntry entry;
		HashMap_Node next;
	} HashMap_NodeDesc;

typedef
	struct HashMap_TObjectDesc { /* DynamicArray_AObjectDesc */
		char _prvt0[1];
	} HashMap_TObjectDesc;



export ADDRESS *HashMap_TObjectDesc__typ;
export ADDRESS *HashMap_HashMapEntryDesc__typ;
export ADDRESS *HashMap_NodeDesc__typ;
export ADDRESS *HashMap_HashMapDesc__typ;



__TDESC(HashMap_TObjectDesc, 1, 0) = {__TDFLDS("TObjectDesc", 1), {-8}};
__TDESC(HashMap_HashMapEntryDesc, 1, 2) = {__TDFLDS("HashMapEntryDesc", 16), {0, 8, -24}};
__TDESC(HashMap_NodeDesc, 1, 2) = {__TDFLDS("NodeDesc", 16), {0, 8, -24}};
__TDESC(HashMap_HashMapDesc, 1, 1) = {__TDFLDS("HashMapDesc", 56), {0, -16}};

export void *HashMap__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(DynamicArray);
	__REGMOD("HashMap", 0);
	__INITYP(HashMap_TObjectDesc, DynamicArray_AObjectDesc, 1);
	__INITYP(HashMap_HashMapEntryDesc, HashMap_HashMapEntryDesc, 0);
	__INITYP(HashMap_NodeDesc, DynamicArray_AObjectDesc, 1);
	__INITYP(HashMap_HashMapDesc, HashMap_HashMapDesc, 0);
/* BEGIN */
	__ENDMOD;
}
