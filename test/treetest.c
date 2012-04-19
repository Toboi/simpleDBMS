#include <stdio.h>
#include "../datastruct/datastruct.h"
int *rootNode = 0;
void main(void){
tree_int_insert(1,1, &rootNode);
tree_int_insert(4,4, &rootNode);
tree_int_insert(2,2, &rootNode);
tree_int_insert(5,5, &rootNode);
tree_int_insert(3,3, &rootNode);
tree_int_insert(6,6, &rootNode);
int i = 6;
printf("Out %i: %i\n",i, tree_int_remove(i, &rootNode));
printf("Out %i: %i\n",i, tree_int_get(i, rootNode, 0));
printf("Size: %i\n", tree_int_get_height(rootNode));









































/*	
/* 
Pre-Order
*
{
printf("Pre-Order:\n");
	int retVal = 0;
	int index = 0;
	int* head = tree_int_pre_order_list(rootNode);
	int val = list_int_get(index, head,&retVal);
	while(retVal > 0){
		printf("%i\n", val);
		index++;
		val = list_int_get(index, head,&retVal);
	}
}
/*
In-Order
*
{
printf("In-Order:\n");
	int retVal = 0;
	int index = 0;
	int* head = tree_int_in_order_list(rootNode);
	int val = list_int_get(index, head,&retVal);
	while(retVal > 0){
		printf("%i\n", val);
		index++;
		val = list_int_get(index, head,&retVal);
	}
}
/*
Post-Order
*
{
printf("Post-Order:\n");
	int retVal = 0;
	int index = 0;
	int* head = tree_int_post_order_list(rootNode);
	int val = list_int_get(index, head,&retVal);
	while(retVal > 0){
		printf("%i\n", val);
		index++;
		val = list_int_get(index, head,&retVal);
	}
}*/
}
