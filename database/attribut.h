/*
Header für attribut.c
Hier werden Funktionen für den Umgang mit Attributen von Tabellen(->table.c) und deren Tupeln bereitgestellt, ebenso wie Indizierung über Attributen.
*/

//Datentypen der Attribute

/*
!!!ZUNÄCHST NUR SUPPORT FÜR INTEGER!!!
TODO: Values
*/
#define ATTR_STRING 1
//#define ATTR_STRING_INDEX 1
//#define ATTR_STRING_UNIQUE 1
#define ATTR_INT 1
#define ATTR_INT_INDEX 1
#define ATTR_INT_UNIQUE 1
/* Byte rauslassen: würde bedeuten, dass es nur 4 byte lange attribute gäbe.
#define ATTR_BYTE 1
#define ATTR_BYTE_INDEX 1
#define ATTR_BYTE_UNIQUE 1
*/

#define ATTR_NAME_LENGTH 128

typedef struct{
	int datatype; //Datentyp, wird später definiert per z.B. #define ATTRIBUT_STRING_INDEX oder _UNIQUE (impliziert INDEX)
	int* index_struct; //Falls in datatype das index-bit gesetzt ist.
	struct attribut *attribut_list_next; 
	char attr_name[ATTR_NAME_LENGTH];
} attribut;

/*
IMPLEMENTIERT für Integer
Gibt einen Zeiger auf ein Tupel (/Eine Liste von Tupeln bei nicht UNIQUE-Attributen?) zurück, das innerhalb dieses Attributs indiziert ist.
key wird je nach Datentyp des Attributs als int, byte oder char* behandelt.
In *returnVal wird, falls returnVal != 0, der Return-Wert geschrieben.
*/
int* attr_get_tupel(attribut* attr, int key, int* returnVal);

/*
IMPLEMENTIERT für Integer
Fügt ein Tupel in die Index-Struktur dieses Attributs ein, falls indiziert. value ist hier der Attribut-Wert des Tupels.
Gibt einen Return-Wert gemäß datastruct.h zurück.
*/
int attr_insert_tupel(attribut* attr, int* tupel, int value);

/*
IMPLEMENTIERT für Integer
FEHLEND: int tree_int_remove(int key, int **rootNode);
Löscht ein Tupel aus der Index-Struktur.
Gibt einen Return-Wert gemäß datastruct.h zurück.
*/
int attr_remove_tupel(attribut* attr, int value);




/*
IMPLEMENTIERT, TODO: Nur für Integer
Gibt den Speicher, den ein Attribut mit Indexstruktur und attribut-header belegt, frei.
Rückgabewert ist in database.h definiert.
*/
int free_attr(attribut* attr);
