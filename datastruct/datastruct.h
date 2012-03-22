#ifndef datastructs_h
#define datastructs_h

/*SUCCESS-RETURN-CODES*/
#define DATASTRUCT_SUCCESS 1			//Success
#define DATASTRUCT_SUCCESS_STRUCT_INITIALISED 2 //If the struct was empty at the beginning.

/*ERROR-RETURN-CODES*/
#define DATASTRUCT_ERROR_UNKNOWN -1		//Unknown error
#define DATASTRUCT_ERROR_ELEMENT_NOT_FOUND -2	//The requested element doesn't exist.
#define DATASTRUCT_ERROR_EMPTY_STRUCT -3	//The struct is empty.
#define DATASTRUCT_ERROR_ELEMENT_EXISTS -4 	//The element(/key) which should be inserted, already exists.
#define DATASTRUCT_ERROR_INDEX_TO_HIGH -5	//An index is higher than size of struct.
#define DATASTRUCT_ERROR_WRONG_PARAM -6		//A parameter isn't in its specified value range. (i.e. negative index)

#include <stdlib.h>
#include "stack.h"
#include "list.h"
#include "tree.h"

#endif
