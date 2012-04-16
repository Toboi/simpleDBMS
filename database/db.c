#include "database.h"
#include "../datastruct/datastruct.h"
/*
!!!!!!!!
!!!!VIELLEICHT DIE STRUKTUR ANDERS: Eine list_int aus datastruct.h, mit Pointern auf die db_header.!!!!
!!!!!!!!
*/

/*db_header{
	tbl_header* tbl_list_head;
	char* db_name;
	db_header *db_list_next;
};*/

int db_list_add_db(int** list_head, db_header* db){
	return list_int_append((int)db, list_head);
}



int db_list_remove_db(int** list_head, db_header* db){
	return list_int_delete((int)db, list_head);
}

db_header* db_list_get_db(int* list_head, char db_name[ ]){
	int index = 0;
	db_header* list_ptr = (db_header*)list_int_get(index, list_head, (int*) 0);
	while(list_ptr != 0){	//Laufe die Liste durch.
		list_ptr = (db_header*)list_int_get(++index, list_head, (int*) 0);
		if(strcmp(db_name,(*(list_ptr)).db_name)==0){ //Wenn die Namen übereinstimmen
			return list_ptr;
		}
	}
}

tbl_header* db_get_tbl(db_header* db, char tbl_name[ ]){
	int* list_head = (*db).tbl_list_head;
	int index = 0;
	tbl_header* list_ptr = (tbl_header*)list_int_get(index, list_head, (int*) 0);
	while(list_ptr != 0){	//Laufe die Liste durch.
		list_ptr = (tbl_header*)list_int_get(++index, list_head, (int*) 0);
		if(strcmp(tbl_name,(*(list_ptr)).tbl_name)==0){ //Wenn die Namen übereinstimmen
			return list_ptr;
		}
	}
}
