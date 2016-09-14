lab1:bin/main.o bin/util.o bin/io.o bin/algorithm.o
	gcc bin/main.o bin/util.o bin/io.o bin/algorithm.o -o lab1  

bin/main.o:src/main.c include/util.h include/io.h include/algorithm.h
	gcc src/main.c -o bin/main.o

bin/algorithm.o:src/algorithm.c include/util.h include/io.h 
	gcc src/algorithm.c -o bin/algorithm.o

bin/util.o:src/util.c include/io.h 
	gcc src/util.c -o bin/util.o

bin/io.o:src/io.c  
	gcc src/io.c -o bin/io.o

clean:
	rm -rf bin/*o./main
