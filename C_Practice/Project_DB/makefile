main: main.o Windowmain.o Windowmode.o
	sudo gcc -o main main.o Windowmain.o Windowmode.o -lraylib
main.o: main.c Windowmain.h 
	sudo gcc -c main.c -lraylib
Windowinsert.o: Windowmain.c Windowmain.h Windowmode.h
	sudo gcc -c Windowmain.c -lraylib
Windowmode.o: Windowmode.c Windowmode.h 
	sudo gcc -c Windowmode.c -lraylib