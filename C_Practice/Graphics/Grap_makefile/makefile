graph: graph.o sdlgraph.o
	gcc -o graph graph.o sdlgraph.o -lSDL2
graph.o: graph.c sdlgraph.h
	gcc -c graph.c -lSDL2
sdlgraph.o: sdlgraph.c sdlgraph.h
	gcc -c sdlgraph.c -lSDL2