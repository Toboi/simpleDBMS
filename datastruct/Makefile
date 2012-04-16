HEADERS = datastruct.h stack.h list.h tree.h

all: datastruct.o
stack.o: stack.c datastruct.h $(HEADERS)
	cc -c stack.c
list.o: list.c datastruct.h $(HEADERS)
	cc -c list.c
tree.o: tree.c datastruct.h $(HEADERS)
	cc -c tree.c
datastruct.o: stack.o list.o tree.o
	ld -i -o datastruct.o stack.o list.o tree.o
clean:
	rm stack.o list.o tree.o	
git-push:
	git add Makefile; \
	git add *.c; \
	git add *.h
