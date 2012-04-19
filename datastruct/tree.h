#ifndef tree_h
#define tree_h
int tree_int_insert(int key, int val, int **rootNode); //getestet
int tree_int_get(int key, int *rootNode, int* returnVal); //getestet
int tree_int_remove(int key, int **rootNode);
int tree_int_get_height(int *ptr); //getestet
int tree_int_get_size(int *ptr); //getestet
int tree_int_free_all(int **rootNode);
/*
Außerdem noch tree_int_pre_order_list bzw. in- und post-order ((alle getestet))
*/
#endif
