#include "datastructs.h"
/*
Inserts an element to a binary tree.
TODO: Return values.
*/
int tree_int_insert(int key, int val, int **rootNode){
	int *ptr = *rootNode;
	int *newPtr = (int*) malloc(16);
	*newPtr = key;
	*(newPtr + 1) = 0;
	*(newPtr + 2) = 0;
	*(newPtr + 3) = val;
	if(ptr != 0){	//If tree isn't empty:
			//Find insert place.
		while( (*ptr < key && *(ptr + 2)) || (*ptr > key && *(ptr + 1)) ){
			if(*ptr < key){
				ptr = (int*) *(ptr+2);}
			else{
				ptr = (int*) *(ptr+1);}
		}	
		//Insert left or right.
		if(*ptr < key){
			*(ptr + 2) = (int) newPtr;
		}
		if(*ptr > key){
			*(ptr + 1) = (int) newPtr;
		}
		if(*ptr == key){
			return DATASTRUCT_ERROR_ELEMENT_EXISTS;
		}
		return DATASTRUCT_SUCCESS;
	}else{	//If tree was empty: Make a new rootNode.
		*rootNode = newPtr;
		return DATASTRUCT_SUCCESS_STRUCT_INITIALISED;
	}
}

/*
Get's the value for a key in a binary tree.
If the key isn't found, it returns 0.
If returnVal != 0, in *returnVal it saves the Return-Code, specified in datastructs.h
*/
int tree_int_get(int key, int *rootNode, int* returnVal){
	if(rootNode == 0){
		if(returnVal != 0)
			*returnVal = DATASTRUCT_ERROR_EMPTY_STRUCT;
		return 0;
	}
	int *ptr = rootNode;
	while(ptr != 0){//Find element.
		if(*ptr == key){
			break;
		}
		if(*ptr < key){
			ptr = (int*) *(ptr + 1);
		}else{
			ptr = (int*) *(ptr + 2);
		}
	}
	if(ptr != 0){ 	//Element found: return value.
		if(returnVal != 0)
			*returnVal = DATASTRUCT_SUCCESS;
		return *(ptr+3);
	}else{		//Element not found: return 0.
		if(returnVal != 0)
			*returnVal = DATASTRUCT_ERROR_ELEMENT_NOT_FOUND;
		return 0;
	}
}

/*
Returns the height of the tree.
(Biggest distance between root-node and a leaf)
*/
int tree_int_get_height(int *ptr){
	if(ptr == 0){	//Finite statement
		return 0;
	}
	int sizeLeft = tree_int_get_height((int*)*(ptr + 1));
	int sizeRight = tree_int_get_height((int*)*(ptr + 2));
	if(sizeLeft > sizeRight){
		return sizeLeft + 1;
	}else{
		return sizeRight + 1;
	}
}

/*
Returns the sum of the elements in the tree.
*/
int tree_int_get_size(int *ptr){
	if(ptr != 0){
		return tree_int_get_size((int*)*(ptr+1)) + tree_int_get_size((int*)*(ptr+2)) + 1;
	}else{
		return 0;
	}
}

/*
Deletes the complete tree and frees the used memory.
*/
int tree_int_free_all(int **rootNode){
	int *ptr = *rootNode;
	tree_int_free_all_rec_step(ptr);
	*rootNode = 0;
	return DATASTRUCT_SUCCESS;
}

/*
Part of tree_int_free_all, should only be called internally.
*/
int tree_int_free_all_rec_step(int *ptr){
	if(ptr == 0){
		return;
	}
	tree_int_free_all_rec_step((int*)*(ptr+1));
	tree_int_free_all_rec_step((int*)*(ptr+2));
	free(ptr);
}

/*
Should only be called internally.
*/
void tree_int_pre_order_list_rec_step(int* treePtr, int* listPtr){
	if(treePtr == 0){
		return;
	}
	list_int_append(*(treePtr+3), &listPtr);
	tree_int_pre_order_list_rec_step((int*) *(treePtr+1), listPtr);
	tree_int_pre_order_list_rec_step((int*) *(treePtr+2), listPtr);
}

/*
Returns the pointer to a list_int with the values of the elements of the tree sorted in pre-order-algorithm.
*/
int* tree_int_pre_order_list(int* ptr){
	if(ptr == 0){
		return 0;
	}
	int* listPtr = 0;	
	list_int_append(*(ptr+3), &listPtr);
	tree_int_pre_order_list_rec_step((int*) *(ptr+1), listPtr);
	tree_int_pre_order_list_rec_step((int*) *(ptr+2), listPtr);
	return listPtr;
}

/*
Should only be called internally.
*/
void tree_int_in_order_list_rec_step(int* treePtr, int** listPtr){
	if(treePtr == 0){
		return;
	}
	tree_int_in_order_list_rec_step((int*) *(treePtr+1), listPtr);
	list_int_append(*(treePtr+3), listPtr);
	tree_int_in_order_list_rec_step((int*) *(treePtr+2), listPtr);
}

/*
Returns the pointer to a list_int with the values of the elements of the tree sorted in in-order-algorithm.
*/
int* tree_int_in_order_list(int* ptr){
	if(ptr == 0){
		return 0;
	}
	int* listPtr = 0;
	tree_int_in_order_list_rec_step((int*) *(ptr+1), &listPtr);
	list_int_append(*(ptr+3), &listPtr);
	tree_int_in_order_list_rec_step((int*) *(ptr+2), &listPtr);
	return listPtr;
}

/*
Should only be called internally.
*/
void tree_int_post_order_list_rec_step(int* treePtr, int** listPtr){
	if(treePtr == 0){
		return;
	}
	tree_int_post_order_list_rec_step((int*) *(treePtr+1), listPtr);
	tree_int_post_order_list_rec_step((int*) *(treePtr+2), listPtr);
	list_int_append(*(treePtr+3), listPtr);
}

/*
Returns the pointer to a list_int with the values of the elements of the tree sorted in post-order-algorithm.
*/
int* tree_int_post_order_list(int* ptr){
	if(ptr == 0){
		return 0;
	}
	int* listPtr = 0;
	tree_int_post_order_list_rec_step((int*) *(ptr+1), &listPtr);
	tree_int_post_order_list_rec_step((int*) *(ptr+2), &listPtr);
	list_int_append(*(ptr+3), &listPtr);
	return listPtr;
}
//Should work, but other one is simpler. (faster too?)
/*
int tree_int_get_height_rec(int *ptr){
	int *ptrLeft = *(ptr + 1);
	int *ptrRight = *(ptr + 2);
	if(ptrLeft == 0 && ptrRight == 0){
		return 1;
	}

	int sizeLeft = 0;
	if(ptrLeft != 0){
		sizeLeft = tree_int_get_height_rec(ptrLeft);
	}
	int sizeRight = 0;
	if(ptrRight != 0){
		sizeRight = tree_int_get_height_rec(ptrRight);
	}
	if(sizeLeft > sizeRight){
		return sizeLeft + 1;
	}else{
		return sizeRight + 1;
	}
}
*/
