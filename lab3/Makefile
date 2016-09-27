all: bin lab_3

bin:
	mkdir -p bin

lab_3:bin/main.o bin/clist.o
	gcc bin/main.o bin/clist.o -o lab_3

bin/main.o:src/main.c include/clist.h
	gcc -c -I include src/main.c -o bin/main.o

bin/clist.o:src/clist.c include/clist.h
	gcc -c -I include src/clist.c -o bin/clist.o

clean:
	rm -rf bin lab_3
