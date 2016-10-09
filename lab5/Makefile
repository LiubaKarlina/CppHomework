all: bin lab_5

bin:
	mkdir -p bin

lab_5:bin/main.o bin/clist.o bin/position.o bin/apply.o
	gcc bin/main.o bin/clist.o bin/position.o bin/apply.o -o lab_5

bin/main.o:src/main.c include/position.h include/apply.h
	gcc -c -I include src/main.c -o bin/main.o

bin/apply.o:src/apply.c include/position.h
	gcc -c -I include src/apply.c -o bin/apply.o

bin/position.o:src/position.c include/clist.h
	gcc -c -I include src/position.c -o bin/position.o

bin/clist.o:src/clist.c
	gcc -c -I include src/clist.c -o bin/clist.o

clean:
	rm -rf bin lab_5
