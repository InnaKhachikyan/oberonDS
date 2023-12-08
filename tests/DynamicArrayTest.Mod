MODULE DynamicArrayTest;

IMPORT DynamicArray, Out;

TYPE
	    AObject* = DynamicArray.AObject;
    AObjectDesc* = DynamicArray.AObjectDesc;

        AInt* = POINTER TO AIntDesc;
    AIntDesc* = RECORD (DynamicArray.AObjectDesc);
         obj* : INTEGER; 
    END;

VAR
    arr1* : DynamicArray.DArray;
    arr2* : DynamicArray.DArray;
    arr3* : DynamicArray.DArray;

    i* : INTEGER;

     element1* : AInt;
     element2* : AInt;
     element3* : AInt;
     element4* : AInt;
     element5* : AInt;
     element6* : AInt;
     element7* : AInt;
     element8* : AInt;
     element9* : AInt;
    element10* : AInt;

	 parentA1* : AObject;
	 parentA2* : AObject;
	 parentA3* : AObject; 

BEGIN
    NEW(element1);
    element1.obj := 1;

    NEW(element2);
    element2.obj := 2;

    NEW(element3);
    element3.obj := 3;

    NEW(element4);
    element4.obj := 4;

    NEW(element5);
    element5.obj := 5;

    NEW(element6);
    element6.obj := 6;

    NEW(element7);
    element7.obj := 7;

    NEW(element8);
    element8.obj := 8;

    NEW(element9);
    element9.obj := 9;

    NEW(element10);
    element10.obj := 10;

    arr1 := DynamicArray.Create(5);
    arr2 := DynamicArray.Create(10);
	arr3 := DynamicArray.Create(20);

    DynamicArray.Add(arr1, element1);
    DynamicArray.Add(arr1, element2);
    DynamicArray.Add(arr1, element3);
    DynamicArray.Add(arr1, element4);
    DynamicArray.Add(arr1, element5);

    DynamicArray.Add(arr2, element6);
    DynamicArray.Add(arr2, element7);
    DynamicArray.Add(arr2, element8);
    DynamicArray.Add(arr2, element9);
    DynamicArray.Add(arr2, element10);

    Out.String("printing arr1 after addition of 5 elements"); Out.Ln;
    Out.Int(arr1.container[0](AInt).obj, 0); Out.Ln;
    Out.Int(arr1.container[1](AInt).obj, 0); Out.Ln;
    Out.Int(arr1.container[2](AInt).obj, 0); Out.Ln;
    Out.Int(arr1.container[3](AInt).obj, 0); Out.Ln;
    Out.Int(arr1.container[4](AInt).obj, 0); Out.Ln;

    Out.String("printing arr2 after addition of 5 elements"); Out.Ln;
    Out.Int(arr2.container[0](AInt).obj, 0); Out.Ln;
    Out.Int(arr2.container[1](AInt).obj, 0); Out.Ln;
    Out.Int(arr2.container[2](AInt).obj, 0); Out.Ln;
    Out.Int(arr2.container[3](AInt).obj, 0); Out.Ln;
    Out.Int(arr2.container[4](AInt).obj, 0); Out.Ln;

	Out.String("-------Test for Insert procedure-------"); Out.Ln;
	DynamicArray.Insert(arr2,0,element5);
	DynamicArray.Insert(arr2,0,element4);
	DynamicArray.Insert(arr2,0,element3);
	DynamicArray.Insert(arr2,0,element2);
	DynamicArray.Insert(arr2,0,element1);

	Out.String("_____Printing all elements after insert______"); Out.Ln;
	Out.Int(arr2.container[0](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[1](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[2](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[3](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[4](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[5](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[6](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[7](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[8](AInt).obj,0); Out.Ln;
	Out.Int(arr2.container[9](AInt).obj,0); Out.Ln;
   
	Out.String("------Testing Delete procedure------"); Out.Ln;
	parentA1 := DynamicArray.Delete(arr1,0);
	Out.String("Element at index 0 was removed from arr1: "); Out.Int(parentA1(AInt).obj,0); Out.Ln;
    
	parentA2 := DynamicArray.Delete(arr1,0);
	Out.String("Element at index 0 was removed from arr1: "); Out.Int(parentA2(AInt).obj,0); Out.Ln;

	Out.String("-----Testing SetAt procedure-----"); Out.Ln;
	parentA1 := DynamicArray.SetAt(arr2,0,element10);
	parentA2 := DynamicArray.SetAt(arr2,0,element9);

	Out.String("First old element is element1: "); Out.Int(parentA1(AInt).obj,0); Out.Ln;
	Out.String("Second old element is element10: "); Out.Int(parentA2(AInt).obj,0); Out.Ln;

	Out.String("---Printing the resulting arr2 after 2 SetAt procedures---"); Out.Ln;
	Out.Int(arr2.container[0](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[1](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[2](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[3](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[4](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[5](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[6](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[7](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[8](AInt).obj,0); Out.Ln; 
	Out.Int(arr2.container[9](AInt).obj,0); Out.Ln; 
	
	Out.String("number of elements of arr2: "); Out.Int(arr2.numberOfElements, 0); Out.Ln;
	Out.String("-----Testing the Resize method: arr2 was created with 10, has 10 elements, add 11th-----"); Out.Ln;
	DynamicArray.Add(arr2,element8);

	FOR i := 0 TO arr2.numberOfElements-1 BY 1 DO
		Out.Int(arr2.container[i](AInt).obj,0);Out.Ln;
	END;

END DynamicArrayTest.
