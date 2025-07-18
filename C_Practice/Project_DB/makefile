main: main.o Windowmain.o Windowmode.o library.o
	sudo gcc -o main main.o Windowmain.o Windowmode.o library.o -lraylib -lm -ldl -lpthread -lrt -lGL
main.o: main.c Windowmain.h Windowmode.h library.h
	sudo gcc -c main.c 
Windowmain.o: Windowmain.c Windowmain.h library.h
	sudo gcc -c Windowmain.c 
Windowmode.o: Windowmode.c Windowmode.h library.h
	sudo gcc -c Windowmode.c 
library.o: library.c library.h
	sudo gcc -c library.c 
clean:
	rm -f *.o main