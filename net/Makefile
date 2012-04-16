HEADERS = net.h server.h con_handler.h


all: net.o

con_handler.o: con_handler.c $(HEADERS)
	cc -c con_handler.c
server.o: server.c $(HEADERS)
	cc -c server.c
net.o: server.o con_handler.o
	rm net.o; \
	ld -i *.o -o net.o
clean:
	rm server.o con_handler.o;
clean-all:
	rm *.o;
git-push:
	git add Makefile; \
	git add *.c; \
	git add *.h
