/*
Header für table.c
Hier werden einzelne Tabellen(/Relationen), den Umgang mit ihren Attributen und teilweise der Umgang mit den Tupeln bereitgestellt.
*/

#define TABLE_NAME_LENGTH 128


typedef struct{
	char tbl_name[TABLE_NAME_LENGTH];
	int* attr_list_head; //Liste mit Zeigern auf jedes Attribut
	int tupel_size; //Errechnet sich aus der Attribut-Liste
	int* tupel_list_head; //Liste mit Zeigern auf jedes einzelne Tupel
	int tupel_number; //Anzahl der Tupel
} tbl_header;




  /*-------------------------------------------*/
 /*-------  Attribut-List-Funktionen  --------*/
/*-------------------------------------------*/

/*
Gibt einen Zeiger auf das Attribut mit dem Namen attr_name zurück.
Nach *returnVal wird der Rückgabewert geschrieben, falls returnVal != 0 ist.
*/
attribut* tbl_get_attr(tbl_header* table, char attr_name[ ], int* returnVal);

/*
Gibt einen Zeiger auf den Attribut-Wert zum Attribut attr_name vom tupel zurück.
*/
int* tbl_get_attrval_from_tupel(tbl_header table, int* tupel, char attr_name[ ]);

  /*-----------------------------------*/
 /*-------  Tupel-Funktionen  --------*/
/*-----------------------------------*/

/*
Fügt ein Tupel in die Tabelle ein.
*/
int tbl_insert_tupel(tbl_header* tbl_head, int* tupel_ptr);

/*
Löscht ein Tupel aus der Tabelle
*/
int tbl_remove_tupel(tbl_header* tbl_head, int* tupel_ptr);

/*
IMPLEMENTIERT. TODO: Überprüfen, ob komplett
Gibt einen Zeiger auf den Anfang eines Tupels zurück.
(Das Tupel, das den Wert value in dem Attribut hat)
Nach *returnVal wird der Rückgabewert geschrieben, falls returnVal != 0 ist.
*/
int* tbl_get_tupel(tbl_header* tbl_head, char attr_name[ ], int value, int* returnVal);

  /*--------------------------------------*/
 /*-------  Tabellen-Funktionen  --------*/
/*--------------------------------------*/

/*
Gibt den Speicher, den eine Tabelle mit Attributen, Tupeln und tbl_header belegt, frei.
Rückgabewert ist in database.h definiert.
*/
int free_tbl(tbl_header* tbl_head);
