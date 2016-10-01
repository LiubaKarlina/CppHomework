all: bin ms_cli

bin:
	mkdir -p bin

ms_cli:bin/main.o bin/mergesort.o bin/ms_cli.o
	gcc bin/main.o bin/mergesort.o bin/ms_cli.o -o ms_cli

bin/main.o:src/main.c include/ms_cli.h include/mergesort.h
	gcc -c -I include src/main.c -o bin/main.o 

bin/mergesort.o:src/mergesort.c include/ms_cli.h
	gcc -c -I include src/mergesort.c -o bin/mergesort.o
 
bin/ms_cli.o:src/ms_cli.c
	gcc -c -I include src/ms_cli.c -o bin/ms_cli.o

clean:
	rm -rf bin ms_cli
