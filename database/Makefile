HEADERS = database.h db.h table.h attribut.h


all: database.o
attribut.o: attribut.c $(HEADERS)
	cc -c attribut.c
table.o: table.c $(HEADERS)
	cc -c table.c
db.o: db.c $(HEADERS)
	cc -c db.c
database.o: attribut.o table.o db.o
	rm database.o; \
	ld -i *.o -o database.o
clean:
	rm *.o;
 
