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

/*
Gibt den Attribut-Wert des Tupels zurück.
TODO: Geht nur von 4 Byte langen Attributwerten aus!!!
*/
int* tbl_get_tupel_val(tbl_header* tbl_head, int* tupel_ptr, char* attr_name){
	int* attr_list_head = tbl_head->attr_list_head;
	while(attr_list_head != 0){
		if(strcmp(attr_name, ((attribut*)(list_int_get(0, attr_list_head,0)))->attr_name) == 0){
			return tupel_ptr;
		}
		list_int_next(&attr_list_head);
		tupel_ptr = (tupel_ptr + 1);
	}
}

/*
Gibt den gesamten Speicher frei.
*/
int free_tbl(tbl_header* tbl_head){
	list_int_void_each(tbl_head->attr_list_head,(void (*)(int))free_attr);
	list_int_void_each(tbl_head->tupel_list_head,(void (*)(int))free);
	free(tbl_head);
}

/*
typedef struct{
	char tbl_name[TABLE_NAME_LENGTH];
	int* attr_list_head; //Liste mit Zeigern auf jedes Attribut
	int tupel_size; //Errechnet sich aus der Attribut-Liste
	int* tupel_list_head; //Liste mit Zeigern auf jedes einzelne Tupel
	int tupel_number; //Anzahl der Tupel, TODO: Entscheiden ob nötig.
} tbl_header;
*/
