#ifndef tree_h
#define tree_h
int tree_int_insert(int key, int val, int **rootNode);
int tree_int_get(int key, int *rootNode, int* returnVal);
int tree_int_remove(int key, int **rootNode);
int tree_int_get_height(int *ptr);
int tree_int_get_size(int *ptr);
int tree_int_free_all(int **rootNode);
int tree_int_free_all_rec_step(int *ptr);
#endif
