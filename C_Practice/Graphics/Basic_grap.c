/*sudo gcc Basic_grap.c -o window -I/usr/include/SDL2 -L/usr/lib -lSDL2 */
#include "SDL2/SDL.h"
#include<stdio.h>

int main(int argc, char* argv[]) {
    // Inizializzazione di SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL non può essere inizializzato! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    // Creazione della finestra
    SDL_Window* window = SDL_CreateWindow(
        "Prova",                     // Titolo della finestra
        SDL_WINDOWPOS_UNDEFINED,            // Posizione X
        SDL_WINDOWPOS_UNDEFINED,            // Posizione Y
        2000,                                // Larghezza
        600,                                // Altezza
        SDL_WINDOW_SHOWN                    // Finestra visibile
    );

    if (window == NULL) {
        printf("Impossibile creare la finestra! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Creazione di un renderer per la finestra
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Impossibile creare il renderer! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Ciclo principale per visualizzare la finestra
    int running = 1;
    SDL_Event e;
    while (running) {
        // Gestione degli eventi
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = 0; // Esci dal ciclo se viene richiesta la chiusura della finestra
            }
        }

        // Pulisce la finestra con il colore nero
        SDL_SetRenderDrawColor(renderer, 0, 0, 125, 125);
        SDL_RenderClear(renderer);

        // Mostra la finestra
        SDL_RenderPresent(renderer);
    }

    // Pulizia e chiusura
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
