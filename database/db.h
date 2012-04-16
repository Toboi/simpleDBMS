/*
Header für db.c
Hier wird die Verwaltung mehrerer, unterschiedlicher Datenbanken bereitgestellt.
*/

#define DB_NAME_LENGTH 128


typedef struct{
	int* tbl_list_head; //Liste mit Zeigern auf jede Tabelle in der DB.
	char db_name[DB_NAME_LENGTH];
} db_header;



/*-------  Table-List-Funktionen  --------*/

/*
IMPLEMENTIERT
Gibt den tbl_header der Tabelle mit dem Namen tbl_name zurück.
 */
tbl_header* db_get_tbl(db_header* db, char tbl_name[ ]);



/*-------  DB-List-Funktionen  --------*/
/*
IMPLEMENTIERT
Fügt einen db_header in die db-Liste ein.
Gibt einen Return-Value zurück, definiert in datastruct.h
*/
int db_list_add_db(int** list_head, db_header* db);

/*
IMPLEMENTIERT
Löscht einen db_header aus einer db-Liste.
Gibt einen Return-Value zurück, definiert in datastruct.h
*/
int db_list_remove_db(int** list_head, db_header* db);

/*
IMPLEMENTIERT
Gibt die Datenbank mit diesem Namen aus der db-Liste zurück.
*/
db_header* db_list_get_db(int* list_head, char db_name[ ]);
