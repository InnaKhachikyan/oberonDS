/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#ifndef DynamicArray__h
#define DynamicArray__h

#include "SYSTEM.h"

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
		char _prvt0[8];
		DynamicArray_pcontainer container;
		INT16 capacity, numberOfElements;
	} DynamicArray_DArrayDesc;



import ADDRESS *DynamicArray_AObjectDesc__typ;
import ADDRESS *DynamicArray_DArrayDesc__typ;

import void DynamicArray_Add (DynamicArray_DArray l, DynamicArray_AObject newElement);
import DynamicArray_DArray DynamicArray_Create (INT16 Capacity);
import DynamicArray_AObject DynamicArray_Delete (DynamicArray_DArray l, INT16 index);
import DynamicArray_AObject DynamicArray_Get (DynamicArray_DArray l, INT16 index);
import void DynamicArray_Insert (DynamicArray_DArray l, INT16 index, DynamicArray_AObject newElement);
import void DynamicArray_Resize (DynamicArray_DArray l);
import DynamicArray_AObject DynamicArray_SetAt (DynamicArray_DArray l, INT16 index, DynamicArray_AObject newElement);
import void *DynamicArray__init(void);


#endif // DynamicArray
