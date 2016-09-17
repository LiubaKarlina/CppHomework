all: bin task2

bin:
	mkdir -p bin

task2:bin/test.o bin/str.o bin/test_str.o
	gcc bin/test.o bin/str.o bin/test_str.o -o task2

bin/test.o:src/test.c include/test_str.h
	gcc -c -I include src/test.c -o bin/test.o

bin/test_str.o:src/test_str.c include/str.h
	gcc -c -I include src/test_str.c -o bin/test_str.o

bin/str.o:src/str.c
	gcc -c -I include src/str.c -o bin/str.o

clean:
	rm -rf bin task2
