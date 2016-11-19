all: bin main

bin:
	mkdir -p bin

main:bin/main.o bin/msg.o bin/bmp.o
	gcc bin/main.o bin/bmp.o bin/msg.o -o main

bin/main.o:src/main.c include/bmp.h  include/msg.h
	gcc -c -I include src/main.c -o bin/main.o

bin/msg.o:src/msg.c  include/bmp.h
	gcc -c -I include src/msg.c -o bin/msg.o

bin/bmp.o:src/bmp.c
	gcc -c -I include src/bmp.c -o bin/bmp.o

clean:
	rm -rf bin main
