#include "database.h"




/*
Gibt einen Zeiger auf den Anfang eines Tupels zurück.
(Das Tupel, das den Wert value in dem Attribut hat)
*/

int* tbl_get_tupel(struct tbl_header* tbl_head, char attr_name[ ], int value, int* returnVal){
	int tmp;
	struct attribut *attr = tbl_get_attr(tbl_head, attr_name, &tmp);
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
