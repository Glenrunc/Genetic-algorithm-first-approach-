main: Population.o individu.o main.o
	gcc -o main.exe individu.o Population.o main.o -lm
Population.o: Population.c
	gcc -o Population.o -c Population.c -W -Wall -pedantic
individu.o: individu.c
	gcc -o individu.o -c individu.c -W -Wall -pedantic
main.o: main.c Population.h individu.h
	gcc -o main.o -c main.c -W -Wall -pedantic 
clean:
	rm -rf *.o *.exe
	clear
l:
	wc *.c *.h -l