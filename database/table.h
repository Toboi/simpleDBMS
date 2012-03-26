/*
Header für table.c
Hier werden einzelne Tabellen(/Relationen), den Umgang mit ihren Attributen und teilweise der Umgang mit den Tupeln bereitgestellt.
*/

#define TABLE_NAME_LENGTH 128

struct tbl_header{
	char tbl_name[TABLE_NAME_LENGTH];
	int* attr_list_head; //Liste mit Zeigern auf jedes Attribut
	int tupel_size; //Errechnet sich aus der Attribut-Liste
	int* tupel_list_head; //Liste mit Zeigern auf jedes einzelne Tupel
	int tupel_number; //Anzahl der Tupel
};




  /*-------------------------------------------*/
 /*-------  Attribut-List-Funktionen  --------*/
/*-------------------------------------------*/

/*
Gibt einen Zeiger auf das Attribut mit dem Namen attr_name zurück.
*/
struct attribut* tbl_get_attr(struct tbl_header* table, char attr_name[ ]);

/*
Gibt einen Zeiger auf den Attribut-Wert zum Attribut attr_name vom tupel zurück.
*/
int* tbl_get_attr_from_tupel(struct tbl_header table, int* tupel, char attr_name[ ]);

  /*-----------------------------------*/
 /*-------  Tupel-Funktionen  --------*/
/*-----------------------------------*/

/*
Fügt ein Tupel in die Tabelle ein.
*/
int tbl_insert_tupel(struct tbl_header* tbl_head, int* tupel_ptr);

/*
Löscht ein Tupel aus der Tabelle
*/
int tbl_remove_tupel(struct tbl_header* tbl_head, int* tupel_ptr);

/*
Gibt einen Zeiger auf den Anfang eines Tupels zurück.
(Das Tupel, das den Wert value in dem Attribut hat)
*/
int tbl_get_tupel(struct tbl_header* tbl_head, struct attribut* attr, int value);
