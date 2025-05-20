main: main.o Windowmain.o Windowmode.o library.o
	sudo gcc -o main main.o Windowmain.o Windowmode.o library.o -lraylib
main.o: main.c Windowmain.h 
	sudo gcc -c main.c -lraylib
Windowinsert.o: Windowmain.c Windowmain.h Windowmode.h library.h
	sudo gcc -c Windowmain.c -lraylib
Windowmode.o: Windowmode.c Windowmode.h library.h
	sudo gcc -c Windowmode.c -lraylib