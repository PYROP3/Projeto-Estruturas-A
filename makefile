makeproject:
	gcc -c matriz.h
	gcc -g -c matriz.c
	gcc -c lista.h
	gcc -g -c lista.c
	gcc -g -c main.c
	gcc -g -o projetoC matriz.o lista.o main.o
	clear
	./projetoC
	rm -rf matriz.o
	rm -rf lista.o
	rm -rf main.o
