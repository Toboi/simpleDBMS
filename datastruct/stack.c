#include "datastructs.h"

/*
Pushs an element onto a stack.
*/
int stack_int_push(int val, int** head){
	int nxtPtr = (int) *head;
	*head = (int*) malloc(8);
	**head = val;
	*(*head+1) = nxtPtr;
	if(nxtPtr == 0)
		return DATASTRUCT_SUCCESS_STRUCT_INITIALISED;
	return DATASTRUCT_SUCCESS;
}

/*
Pops an element from a stack.
Returns 0 if stack is empty.
*/
int stack_int_pop(int** head){
	if(*head==0){	//Stack is empty.
		return 0;
	}else{
		int* oldHead = *head;
		int ret = **head;
		*head = (int*) *(*head + 1);
		free(oldHead);
		return ret;
	}
}

/*
Works like stack_int_pop, but without deleting the element.
*/
int stack_int_peek(int** head){
	if(*head==0){	//Stack is empty.
		return 0;
	}else{
		return **head;
	}
}

/*
Returns the number of elements in the stack.
*/
int stack_int_size(int* head){
	int* ptr = head;
	int size = 0;
	while(ptr != 0){
		size++;
		ptr = (int*) *(ptr + 1);
	}
	return size;
}

/*
Deletes the stack and frees the used memory.
*/
int stack_int_free_all(int** head){
	if(*head==0){
		return DATASTRUCT_ERROR_EMPTY_STRUCT;
	}else{
		while(head != 0){
			int* oldHead = *head;
			*head = (int*) *(*head + 1);
			free(oldHead);
		}
		return DATASTRUCT_SUCCESS;
	}
}
