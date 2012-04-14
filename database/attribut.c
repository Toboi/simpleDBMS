#include "database.h"
#include "../datastruct/datastruct.h"

/*
Gibt einen Zeiger auf ein Tupel (/Eine Liste von Tupeln bei nicht UNIQUE-Attributen?) zurück, das innerhalb dieses Attributs indiziert ist.
key wird je nach Datentyp des Attributs als int, byte oder char* behandelt.
In *returnVal wird, falls returnVal != 0, der Return-Wert geschrieben.
*/
int* attr_get_tupel(struct attribut* attr, int key, int* returnVal){
	//Integer
	if((*attr).datatype == ATTR_INT_UNIQUE){
		int retVal = 0;
		int returnPtr = tree_int_get(key, (*attr).index_struct, &retVal);
		if(retVal!=DATASTRUCT_SUCCESS){
			if(returnVal != 0)
				*returnVal = ATTR_TUPEL_NOT_FOUND;
		}else{
			if(returnVal != 0)
				*returnVal = DATABASE_SUCCESS;
			return (int*)returnPtr;
		}
	}
}

/*
Fügt ein Tupel in die Index-Struktur dieses Attributs ein, falls indiziert. key ist hier der Attribut-Wert des Tupels.
*/
int attr_insert_tupel(struct attribut* attr, int* tupel, int key){
	//Integer
	if((*attr).datatype == ATTR_INT_UNIQUE){
		return tree_int_insert(key, (int) tupel, &((*attr).index_struct));
	}
}

/*
Entfernt ein Tupel aus der Index-Struktur dieses Attributs, falls indiziert. key ist hier der Attribut-Wert des Tupels.
*/
int attr_remove_tupel(struct attribut* attr, int value){
	if((*attr).datatype == ATTR_INT_UNIQUE){
		return tree_int_remove(value, &((*attr).index_struct));
	}
}
