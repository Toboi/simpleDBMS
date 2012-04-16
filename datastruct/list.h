#ifndef list_h
#define list_h
int list_int_get(int index, int* head, int* returnVal);
int list_int_append(int val, int** head);
int list_int_insert(int index, int val, int** head);
int list_int_delete(int index, int** head);
int list_int_free_all(int** head);
int list_int_size(int* head);
#endif
