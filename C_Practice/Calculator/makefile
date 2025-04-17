calculator: calculator.o operations.o
	gcc -o calculator calculator.o operations.o
calculator.o: calculator.c operations.h
	gcc -c calculator.c
operations.o: operations.c operations.h
	gcc -c operations.c