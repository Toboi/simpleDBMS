#include "datastructs.h"

/*
Returns the value of the element at the specified index and writes the return-code (->datastructs.h) to *returnVal.
*/
int list_int_get(int index, int* head, int* returnVal){
	if(head == 0){
		if(returnVal != 0)
			*returnVal = DATASTRUCT_ERROR_EMPTY_STRUCT;
		return 0;
	}	
	int* ptr = head;
	while(index > 0 && ptr != 0){
		ptr = (int*) *(ptr+1);
		index--;
	}
	if(ptr == 0){
		if(returnVal != 0)
			*returnVal = DATASTRUCT_ERROR_ELEMENT_NOT_FOUND;
		return 0;
	}	
	if(returnVal != 0)
		*returnVal = DATASTRUCT_SUCCESS;
	return *ptr;
}

/*
Appends an element to the list and returns the return-code as specified in "datastructs.h"
*/
int list_int_append(int val, int** head){
	int* ptr = *head;
	int *newPtr = (int*) malloc(8);
	*newPtr = val;
	*(newPtr + 1) = 0;
	if(ptr == 0){
		*head = newPtr;
		return DATASTRUCT_SUCCESS_STRUCT_INITIALISED;	
	}
	while(*(ptr+1) != 0){
		ptr = (int*) *(ptr+1);
	}
	*(ptr+1) = (int) newPtr;
	return DATASTRUCT_SUCCESS;
}

/*
TODO: Finish it!
*/
int list_int_insert(int index, int val, int** head){
	if(index < 0)
		return DATASTRUCT_ERROR_WRONG_PARAM;

	int* ptr = *head;
	int* before = 0;
	int count = 0;
	while(ptr != 0 && count < index){
		before = ptr;
		ptr = (int*) *(ptr+1);
		count++;
	}
	if(count < index){
		return DATASTRUCT_ERROR_INDEX_TO_HIGH;
	}

	int *newPtr = (int*) malloc(8);
	*newPtr = val;
	*(newPtr + 1) = (int) ptr;
	if(before != 0){
		*(before+1) = (int) newPtr;
	}else{
		*head = newPtr;
	}
	return DATASTRUCT_SUCCESS;
}

/*
Removes a single element from the list.
*/
int list_int_delete(int index, int** head){
	if(index < 0)
		return DATASTRUCT_ERROR_WRONG_PARAM;
	int* ptr = *head;
	int* before = 0;
	int count = 0;
	while(ptr != 0 && count < index){
		before = ptr;
		ptr = (int*) *(ptr+1);
		count++;
	}
	if(ptr == 0){
		return DATASTRUCT_ERROR_INDEX_TO_HIGH;
	}

	if(before == 0){ //If the Index is 0, the head must be changed.
		*head = (int*) *(ptr+1);	
	}else{
		*(before+1) = *(ptr+1);
	}
	free(ptr);
	return DATASTRUCT_SUCCESS;
}

/*
Deletes the complete list and frees the used memory.
*/
int list_int_free_all(int** head){
	int* delStack = 0;
	int* ptr = *head;
	while(ptr != 0){
		stack_int_push((int)ptr, &delStack);
		ptr = (int*) *(ptr+1);
	}
	ptr = (int*) stack_int_pop(&delStack);
	while((int)ptr != 0){
		free(ptr);
		ptr = (int*) stack_int_pop(&delStack);
	}
	*head = 0;
	stack_int_free_all(&delStack);
	return DATASTRUCT_SUCCESS;
}
