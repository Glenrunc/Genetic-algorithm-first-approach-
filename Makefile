main: Population.o main.o
	gcc -o main.exe Population.o main.o
Population.o: Population.c
	gcc -o Population.o -c Population.c -W -Wall -pedantic
main.o: main.c Population.h
	gcc -o main.o -c main.c -W -Wall -pedantic 
clean:
	rm -rf *.o *.exe