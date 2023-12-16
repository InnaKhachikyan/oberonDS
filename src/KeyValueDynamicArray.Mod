MODULE KeyValueMap;
IMPORT DynamicArray;

TYPE
	AObject* = DynamicArray.AObject;
	AObjectDesc* = DynamicArray.AObjectDesc;

	TObject* = POINTER TO TObjectDesc;
	TObjectDesc* = RECORD;

	DArray* = DynamicArray.DArray;
	DArrayDesc* = DynamicArray.DArrayDesc;

	Node* = POINTER TO NodeDesc;
	Nodedesc* = RECORD(AObjectDesc);
	key* : AObject;
	value : AObject;
	next* : Node;
	END;

	KeyValueMap* = POINTER TO TkeyValueMapDesc;
	KeyValueMapDesc* = RECORD;
	container* = DynamicArray.DArray;
	size* : INTEGER;
	Create* : PROCEDURE() : KeyValueMap;
	
	
	

	
