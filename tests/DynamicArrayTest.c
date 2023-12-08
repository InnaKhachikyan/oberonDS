/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtpam */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "DynamicArray.h"
#include "Out.h"

typedef
	struct DynamicArrayTest_AIntDesc *DynamicArrayTest_AInt;

typedef
	struct DynamicArrayTest_AIntDesc { /* DynamicArray_AObjectDesc */
		INT16 obj;
	} DynamicArrayTest_AIntDesc;


export DynamicArray_DArray DynamicArrayTest_arr1, DynamicArrayTest_arr2, DynamicArrayTest_arr3;
export INT16 DynamicArrayTest_i;
export DynamicArrayTest_AInt DynamicArrayTest_element1, DynamicArrayTest_element2, DynamicArrayTest_element3, DynamicArrayTest_element4, DynamicArrayTest_element5, DynamicArrayTest_element6, DynamicArrayTest_element7, DynamicArrayTest_element8, DynamicArrayTest_element9, DynamicArrayTest_element10;
export DynamicArray_AObject DynamicArrayTest_parentA1, DynamicArrayTest_parentA2, DynamicArrayTest_parentA3;
static INT16 DynamicArrayTest__for__1;

export ADDRESS *DynamicArrayTest_AIntDesc__typ;



static void EnumPtrs(void (*P)(void*))
{
	P(DynamicArrayTest_arr1);
	P(DynamicArrayTest_arr2);
	P(DynamicArrayTest_arr3);
	P(DynamicArrayTest_element1);
	P(DynamicArrayTest_element2);
	P(DynamicArrayTest_element3);
	P(DynamicArrayTest_element4);
	P(DynamicArrayTest_element5);
	P(DynamicArrayTest_element6);
	P(DynamicArrayTest_element7);
	P(DynamicArrayTest_element8);
	P(DynamicArrayTest_element9);
	P(DynamicArrayTest_element10);
	P(DynamicArrayTest_parentA1);
	P(DynamicArrayTest_parentA2);
	P(DynamicArrayTest_parentA3);
}

__TDESC(DynamicArrayTest_AIntDesc, 1, 0) = {__TDFLDS("AIntDesc", 2), {-8}};

export int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__MODULE_IMPORT(DynamicArray);
	__MODULE_IMPORT(Out);
	__REGMAIN("DynamicArrayTest", EnumPtrs);
	__INITYP(DynamicArrayTest_AIntDesc, DynamicArray_AObjectDesc, 1);
/* BEGIN */
	__NEW(DynamicArrayTest_element1, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element1->obj = 1;
	__NEW(DynamicArrayTest_element2, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element2->obj = 2;
	__NEW(DynamicArrayTest_element3, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element3->obj = 3;
	__NEW(DynamicArrayTest_element4, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element4->obj = 4;
	__NEW(DynamicArrayTest_element5, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element5->obj = 5;
	__NEW(DynamicArrayTest_element6, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element6->obj = 6;
	__NEW(DynamicArrayTest_element7, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element7->obj = 7;
	__NEW(DynamicArrayTest_element8, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element8->obj = 8;
	__NEW(DynamicArrayTest_element9, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element9->obj = 9;
	__NEW(DynamicArrayTest_element10, DynamicArrayTest_AIntDesc);
	DynamicArrayTest_element10->obj = 10;
	DynamicArrayTest_arr1 = DynamicArray_Create(5);
	DynamicArrayTest_arr2 = DynamicArray_Create(10);
	DynamicArrayTest_arr3 = DynamicArray_Create(20);
	DynamicArray_Add(DynamicArrayTest_arr1, (void*)DynamicArrayTest_element1);
	DynamicArray_Add(DynamicArrayTest_arr1, (void*)DynamicArrayTest_element2);
	DynamicArray_Add(DynamicArrayTest_arr1, (void*)DynamicArrayTest_element3);
	DynamicArray_Add(DynamicArrayTest_arr1, (void*)DynamicArrayTest_element4);
	DynamicArray_Add(DynamicArrayTest_arr1, (void*)DynamicArrayTest_element5);
	DynamicArray_Add(DynamicArrayTest_arr2, (void*)DynamicArrayTest_element6);
	DynamicArray_Add(DynamicArrayTest_arr2, (void*)DynamicArrayTest_element7);
	DynamicArray_Add(DynamicArrayTest_arr2, (void*)DynamicArrayTest_element8);
	DynamicArray_Add(DynamicArrayTest_arr2, (void*)DynamicArrayTest_element9);
	DynamicArray_Add(DynamicArrayTest_arr2, (void*)DynamicArrayTest_element10);
	Out_String((CHAR*)"printing arr1 after addition of 5 elements", 43);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr1->container->data)[0], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr1->container->data)[__X(1, DynamicArrayTest_arr1->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr1->container->data)[__X(2, DynamicArrayTest_arr1->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr1->container->data)[__X(3, DynamicArrayTest_arr1->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr1->container->data)[__X(4, DynamicArrayTest_arr1->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"printing arr2 after addition of 5 elements", 43);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[0], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(1, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(2, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(3, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(4, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"-------Test for Insert procedure-------", 40);
	Out_Ln();
	DynamicArray_Insert(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element5);
	DynamicArray_Insert(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element4);
	DynamicArray_Insert(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element3);
	DynamicArray_Insert(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element2);
	DynamicArray_Insert(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element1);
	Out_String((CHAR*)"_____Printing all elements after insert______", 46);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[0], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(1, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(2, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(3, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(4, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(5, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(6, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(7, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(8, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(9, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"------Testing Delete procedure------", 37);
	Out_Ln();
	DynamicArrayTest_parentA1 = DynamicArray_Delete(DynamicArrayTest_arr1, 0);
	Out_String((CHAR*)"Element at index 0 was removed from arr1: ", 43);
	Out_Int(__GUARDP(DynamicArrayTest_parentA1, DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	DynamicArrayTest_parentA2 = DynamicArray_Delete(DynamicArrayTest_arr1, 0);
	Out_String((CHAR*)"Element at index 0 was removed from arr1: ", 43);
	Out_Int(__GUARDP(DynamicArrayTest_parentA2, DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"-----Testing SetAt procedure-----", 34);
	Out_Ln();
	DynamicArrayTest_parentA1 = DynamicArray_SetAt(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element10);
	DynamicArrayTest_parentA2 = DynamicArray_SetAt(DynamicArrayTest_arr2, 0, (void*)DynamicArrayTest_element9);
	Out_String((CHAR*)"First old element is element1: ", 32);
	Out_Int(__GUARDP(DynamicArrayTest_parentA1, DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"Second old element is element10: ", 34);
	Out_Int(__GUARDP(DynamicArrayTest_parentA2, DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"---Printing the resulting arr2 after 2 SetAt procedures---", 59);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[0], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(1, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(2, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(3, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(4, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(5, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(6, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(7, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(8, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(9, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
	Out_Ln();
	Out_String((CHAR*)"number of elements of arr2: ", 29);
	Out_Int(DynamicArrayTest_arr2->numberOfElements, 0);
	Out_Ln();
	Out_String((CHAR*)"-----Testing the Resize method: arr2 was created with 10, has 10 elements, add 11th-----", 89);
	Out_Ln();
	DynamicArray_Add(DynamicArrayTest_arr2, (void*)DynamicArrayTest_element8);
	DynamicArrayTest__for__1 = DynamicArrayTest_arr2->numberOfElements - 1;
	DynamicArrayTest_i = 0;
	while (DynamicArrayTest_i <= DynamicArrayTest__for__1) {
		Out_Int(__GUARDP((DynamicArrayTest_arr2->container->data)[__X(DynamicArrayTest_i, DynamicArrayTest_arr2->container->len[0])], DynamicArrayTest_AIntDesc, 1)->obj, 0);
		Out_Ln();
		DynamicArrayTest_i += 1;
	}
	__FINI;
}
