all: threadtest treetest listvoidtest
clean:
	rm threadtest treetest listvoidtest;
threadtest: threadtest.c
	cc threadtest.c -lpthread -o threadtest
treetest: treetest.c ../datastruct/datastruct.o
	cc treetest.c -o treetest ../datastruct/datastruct.o
listvoidtest: listvoidtest.c ../datastruct/datastruct.o
	cc listvoidtest.c -o listvoidtest ../datastruct/datastruct.o
git-push:
	git add Makefile; \
	git add *.c; \
	git add *.h
