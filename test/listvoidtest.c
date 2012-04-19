struct test{
	int i;
};

int test(struct test i){
	printf("%i\n", i);
}

void main(){
	int* head = 0;
	int i;
	for(i = 0; i< 10; i++)
		list_int_append(i, &head);
	list_int_void_each(head, (void (*)(int))test);
}
