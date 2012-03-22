/*
Header für attribut.c
Hier werden Funktionen für den Umgang mit Attributen von Tabellen(->table.c) und deren Tupeln bereitgestellt, ebenso wie indizierung über Attributen.
*/

//Datentypen der Attribute

/*
!!!ZUNÄCHST NUR SUPPORT FÜR INTEGER!!!
*/
#define ATTR_STRING 1
#define ATTR_STRING_INDEX 1
#define ATTR_STRING_UNIQUE 1
#define ATTR_INT 1
#define ATTR_INT_INDEX 1
#define ATTR_INT_UNIQUE 1
/* Byte rauslassen: würde bedeuten, dass es nur 4 byte lange attribute gäbe.
#define ATTR_BYTE 1
#define ATTR_BYTE_INDEX 1
#define ATTR_BYTE_UNIQUE 1
*/



/*
IMPLEMENTIERT für Integer
Gibt einen Zeiger auf ein Tupel (/Eine Liste von Tupeln bei nicht UNIQUE-Attributen?) zurück, das innerhalb dieses Attributs indiziert ist.
key wird je nach Datentyp des Attributs als int, byte oder char* behandelt.
*/
int* attr_get_tupel(struct attribut* attr, int key);

/*
IMPLEMENTIERT für Integer
Fügt ein Tupel in die Index-Struktur dieses Attributs ein, falls indiziert. value ist hier der Attribut-Wert des Tupels.
Gibt einen Return-Wert gemäß datastruct.h zurück.
*/
int attr_insert_tupel(struct attribut* attr, int* tupel, int value);


struct attribut{
	int datatype; //Datentyp, wird später definiert per z.B. #define ATTRIBUT_STRING_INDEX oder _UNIQUE (impliziert INDEX)
	int* index_struct; //Falls in datatype das index-bit gesetzt ist.
	struct attribut *attribut_list_next; 
};
