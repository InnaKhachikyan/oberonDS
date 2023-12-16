/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtpam */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "DynamicArray.h"
#include "Map.h"
#include "Out.h"

typedef
	struct MapTest_AKeyDesc *MapTest_AKey;

typedef
	struct MapTest_AKeyDesc { /* Map_KObjectDesc */
		INT16 key;
	} MapTest_AKeyDesc;

typedef
	struct MapTest_AValueDesc *MapTest_AValue;

typedef
	struct MapTest_AValueDesc { /* Map_VObjectDesc */
		INT16 value;
	} MapTest_AValueDesc;


export Map_Map MapTest_h;
export INT16 MapTest_i;
export MapTest_AKey MapTest_k;
export MapTest_AValue MapTest_v;
export Map_MapEntry MapTest_entry;
export Map_Node MapTest_node;
export Map_VObject MapTest_returnVal;

export ADDRESS *MapTest_AKeyDesc__typ;
export ADDRESS *MapTest_AValueDesc__typ;



static void EnumPtrs(void (*P)(void*))
{
	P(MapTest_h);
	P(MapTest_k);
	P(MapTest_v);
	P(MapTest_entry);
	P(MapTest_node);
	P(MapTest_returnVal);
}

__TDESC(MapTest_AKeyDesc, 1, 0) = {__TDFLDS("AKeyDesc", 2), {-8}};
__TDESC(MapTest_AValueDesc, 1, 0) = {__TDFLDS("AValueDesc", 2), {-8}};

export int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__MODULE_IMPORT(DynamicArray);
	__MODULE_IMPORT(Map);
	__MODULE_IMPORT(Out);
	__REGMAIN("MapTest", EnumPtrs);
	__INITYP(MapTest_AKeyDesc, Map_KObjectDesc, 1);
	__INITYP(MapTest_AValueDesc, Map_VObjectDesc, 1);
/* BEGIN */
	Out_String((CHAR*)"Creating map with capacity 10", 30);
	Out_Ln();
	MapTest_h = Map_Create(10);
	__NEW(MapTest_k, MapTest_AKeyDesc);
	MapTest_k->key = 1;
	__NEW(MapTest_v, MapTest_AValueDesc);
	MapTest_v->value = 1;
	Out_String((CHAR*)"Adding key 1 with value 1", 26);
	Out_Ln();
	Out_Int(Map_NumberOfElements(MapTest_h), 0);
	Out_Ln();
	Map_AddOrReplace(MapTest_h, (void*)MapTest_k, (void*)MapTest_v);
	__FINI;
}
