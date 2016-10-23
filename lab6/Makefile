all: bin lab_6

bin:
	mkdir -p bin

lab_6:bin/main.o bin/phonebook.o
	gcc bin/main.o bin/phonebook.o -lexpat -o lab_6

bin/main.o:src/main.c include/names.h include/phonebook.h
	gcc -c -I include src/main.c -o bin/main.o

bin/phonebook.o:src/phonebook.c
	gcc -c -I include src/phonebook.c -o bin/phonebook.o

clean:
	rm -rf bin lab_6
