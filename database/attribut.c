#include "database.h"
#include "../datastruct/datastruct.h"
/*
Gibt einen Zeiger auf ein Tupel (/Eine Liste von Tupeln bei nicht UNIQUE-Attributen?) zurück, das innerhalb dieses Attributs indiziert ist.
key wird je nach Datentyp des Attributs als int, byte oder char* behandelt.
*/
int* attr_get_tupel(struct attribut* attr, int key){
	//Integer
	if((*attr).datatype == ATTR_INT_UNIQUE){
		int returnVal = 0;
		int returnPtr = tree_int_get(key, (*attr).index_struct, &returnVal);
		if(returnVal!=DATASTRUCT_SUCCESS){
			return 0;
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
