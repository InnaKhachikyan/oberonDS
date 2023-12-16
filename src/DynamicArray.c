/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "Out.h"

typedef
	struct DynamicArray_AObjectDesc *DynamicArray_AObject;

typedef
	struct DynamicArray_AObjectDesc {
		char _prvt0[1];
	} DynamicArray_AObjectDesc;

typedef
	struct DynamicArray_DArrayDesc *DynamicArray_DArray;

typedef
	struct {
		ADDRESS len[1];
		DynamicArray_AObject data[1];
	} *DynamicArray_pcontainer;

typedef
	struct DynamicArray_DArrayDesc {
		DynamicArray_DArray (*CreateDefault)(void);
		DynamicArray_DArray (*Create)(void);
		DynamicArray_AObject (*Get)(DynamicArray_DArray, INT16);
		void (*Add)(DynamicArray_DArray, DynamicArray_AObject);
		void (*Insert)(DynamicArray_DArray, INT16, DynamicArray_AObject);
		DynamicArray_AObject (*SetAt)(DynamicArray_DArray, INT16, DynamicArray_AObject);
		DynamicArray_AObject (*Delete)(DynamicArray_DArray, INT16);
		void (*Resize)(DynamicArray_DArray);
		DynamicArray_pcontainer container;
		INT16 capacity, numberOfElements;
	} DynamicArray_DArrayDesc;



export ADDRESS *DynamicArray_AObjectDesc__typ;
export ADDRESS *DynamicArray_DArrayDesc__typ;

export void DynamicArray_Add (DynamicArray_DArray l, DynamicArray_AObject newElement);
export DynamicArray_DArray DynamicArray_Create (INT16 Capacity);
export DynamicArray_AObject DynamicArray_Delete (DynamicArray_DArray l, INT16 index);
export DynamicArray_AObject DynamicArray_Get (DynamicArray_DArray l, INT16 index);
export void DynamicArray_Insert (DynamicArray_DArray l, INT16 index, DynamicArray_AObject newElement);
export void DynamicArray_Resize (DynamicArray_DArray l);
export DynamicArray_AObject DynamicArray_SetAt (DynamicArray_DArray l, INT16 index, DynamicArray_AObject newElement);


DynamicArray_DArray DynamicArray_Create (INT16 Capacity)
{
	DynamicArray_DArray l = NIL;
	INT16 i;
	__NEW(l, DynamicArray_DArrayDesc);
	l->capacity = Capacity;
	l->numberOfElements = 0;
	l->container = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(l->capacity)));
	return l;
}

void DynamicArray_Resize (DynamicArray_DArray l)
{
	INT16 newSize;
	DynamicArray_pcontainer newContainer = NIL;
	INT16 i, _for__9;
	newSize = __ASHL(l->capacity, 1);
	newContainer = __NEWARR(POINTER__typ, 8, 8, 1, 1, ((ADDRESS)(newSize)));
	_for__9 = l->numberOfElements - 1;
	i = 0;
	while (i <= _for__9) {
		(newContainer->data)[__X(i, newContainer->len[0])] = (l->container->data)[__X(i, l->container->len[0])];
		i += 1;
	}
	l->container = newContainer;
	l->capacity = newSize;
}

DynamicArray_AObject DynamicArray_Get (DynamicArray_DArray l, INT16 index)
{
	return (l->container->data)[__X(index, l->container->len[0])];
}

void DynamicArray_Add (DynamicArray_DArray l, DynamicArray_AObject newElement)
{
	if (l->numberOfElements == l->capacity) {
		(*l->Resize)(l);
	}
	(l->container->data)[__X(l->numberOfElements, l->container->len[0])] = newElement;
	l->numberOfElements += 1;
}

void DynamicArray_Insert (DynamicArray_DArray l, INT16 index, DynamicArray_AObject newElement)
{
	INT16 i, _for__7;
	if (index > l->numberOfElements) {
		(l->container->data)[__X(l->capacity + 1, l->container->len[0])] = newElement;
	}
	if (l->numberOfElements == l->capacity) {
		(*l->Resize)(l);
	}
	_for__7 = index + 1;
	i = l->numberOfElements;
	while (i >= _for__7) {
		(l->container->data)[__X(i, l->container->len[0])] = (l->container->data)[__X(i - 1, l->container->len[0])];
		i += -1;
	}
	(l->container->data)[__X(index, l->container->len[0])] = newElement;
	l->numberOfElements += 1;
}

DynamicArray_AObject DynamicArray_SetAt (DynamicArray_DArray l, INT16 index, DynamicArray_AObject newElement)
{
	DynamicArray_AObject oldElement = NIL;
	oldElement = (l->container->data)[__X(index, l->container->len[0])];
	(l->container->data)[__X(index, l->container->len[0])] = newElement;
	return oldElement;
}

DynamicArray_AObject DynamicArray_Delete (DynamicArray_DArray l, INT16 index)
{
	DynamicArray_AObject oldObject = NIL;
	INT16 i, _for__4;
	oldObject = (l->container->data)[__X(index, l->container->len[0])];
	_for__4 = l->numberOfElements - 1;
	i = index;
	while (i <= _for__4) {
		(l->container->data)[__X(i, l->container->len[0])] = (l->container->data)[__X(i + 1, l->container->len[0])];
		i += 1;
	}
	(l->container->data)[__X(l->numberOfElements - 1, l->container->len[0])] = NIL;
	return oldObject;
}

__TDESC(DynamicArray_AObjectDesc, 1, 0) = {__TDFLDS("AObjectDesc", 1), {-8}};
__TDESC(DynamicArray_DArrayDesc, 1, 1) = {__TDFLDS("DArrayDesc", 80), {64, -16}};

export void *DynamicArray__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(Out);
	__REGMOD("DynamicArray", 0);
	__INITYP(DynamicArray_AObjectDesc, DynamicArray_AObjectDesc, 0);
	__INITYP(DynamicArray_DArrayDesc, DynamicArray_DArrayDesc, 0);
/* BEGIN */
	__ENDMOD;
}
