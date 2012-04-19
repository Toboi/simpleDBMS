#include "database.h"
#include "../datastruct/datastruct.h"
#include <malloc.h>



/*
Gibt einen Zeiger auf den Anfang eines Tupels zurück.
(Das Tupel, das den Wert value in dem Attribut hat)
*/

int* tbl_get_tupel(tbl_header* tbl_head, char attr_name[ ], int value, int* returnVal){
	int tmp;
	attribut *attr = tbl_get_attr(tbl_head, attr_name, &tmp);
	if(tmp != DATABASE_SUCCESS){
		if(returnVal != 0)
			*returnVal = tmp;
		return 0;
	}
	int* tupel_ptr = attr_get_tupel(attr, value, &tmp);
	if(tmp == DATABASE_SUCCESS){
		if(returnVal != 0)
			*returnVal = DATABASE_SUCCESS;
		return tupel_ptr;
	}else{
		if(returnVal != 0)
			*returnVal = tmp;
		return 0;
	}
}

int free_tbl(tbl_header* tbl_head){
	list_int_void_each(tbl_head->attr_list_head,(void (*)(int))free_attr);
	list_int_void_each(tbl_head->tupel_list_head,(void (*)(int))free);
	free(tbl_head);
}
