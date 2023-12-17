MODULE DynamicArray;
IMPORT Out;

TYPE AObject* = POINTER TO AObjectDesc;
 AObjectDesc* = RECORD
END;
pcontainer = POINTER TO ARRAY OF AObject;

               DArray* = POINTER TO DArrayDesc;
           DArrayDesc* = RECORD
        CreateDefault* : PROCEDURE () : DArray;
               Create* : PROCEDURE()  : DArray;
                  Get* : PROCEDURE (l : DArray; index : INTEGER) : AObject;
                  Add* : PROCEDURE (l : DArray; newElement : AObject);
               Insert* : PROCEDURE (l : DArray; index : INTEGER; newElement : AObject);
                SetAt* : PROCEDURE (l : DArray; index : INTEGER; newElement : AObject) : AObject;
               Delete* : PROCEDURE (l : DArray; index : INTEGER) : AObject;
                Resize : PROCEDURE (l : DArray);
            container* : pcontainer;
             capacity* : INTEGER;
     numberOfElements- : INTEGER;
        END;

    PROCEDURE Create* (Capacity : INTEGER) : DArray;
    VAR l : DArray;
        i : INTEGER;
    BEGIN
        NEW(l);
        l.capacity := Capacity;
        l.numberOfElements := 0;
        NEW(l.container, l.capacity);
        RETURN l;
    END Create;

    PROCEDURE Resize (l : DArray);
    VAR      newSize : INTEGER;
        newContainer : pcontainer;
                   i : INTEGER;
    BEGIN
        newSize := l.capacity * 2;
        NEW(newContainer, newSize);
        FOR i := 0 TO l.numberOfElements - 1 BY 1 DO
            newContainer[i] := l.container[i];
        END;
        l.container := newContainer;
        l.capacity := newSize;
    END Resize;

    PROCEDURE Get* (l : DArray; index : INTEGER) : AObject;
    BEGIN
        RETURN l.container[index];
    END Get;

    PROCEDURE Add* (l : DArray; newElement : AObject);
    BEGIN
        IF l.numberOfElements = l.capacity THEN
          Resize(l);
        END;
        l.container[l.numberOfElements] := newElement;
        INC(l.numberOfElements);
    END Add;

    PROCEDURE Insert* (l : DArray; index : INTEGER; newElement : AObject);
    VAR i : INTEGER;
    BEGIN
		IF index > l.numberOfElements THEN
		  l.container[l.capacity+1] := newElement;
		END;
        IF l.numberOfElements = l.capacity THEN
          l.Resize(l);
        END;
        FOR i := l.numberOfElements TO index+1 BY -1 DO
          l.container[i] := l.container[i-1];
        END;
        l.container[index] := newElement;
        INC(l.numberOfElements);
    END Insert;

    PROCEDURE SetAt* (l : DArray; index : INTEGER; newElement : AObject) : AObject;
    VAR oldElement : AObject;
    BEGIN
        oldElement := l.container[index];
        l.container[index] := newElement;
        RETURN oldElement;
    END SetAt;

    PROCEDURE Delete* (l : DArray; index : INTEGER) : AObject;
    VAR oldObject : AObject;
                i : INTEGER;
    BEGIN
        oldObject := l.container[index];
        FOR i := index TO l.numberOfElements-2 BY 1 DO
            l.container[i] := l.container[i+1];
        END;
        l.container[l.numberOfElements-1] := NIL;
		DEC(l.numberOfElements);
		RETURN oldObject;
    END Delete;

END DynamicArray.

    
