#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 500  // Lunghezza massima del testo
#define CURSOR_BLINK_TIME 500  // Tempo in ms per far lampeggiare il cursore

int main(int argc, char* argv[]) {
    // Inizializza SDL e SDL_ttf
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("Input Box", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Carica il font
    TTF_Font* font = TTF_OpenFont("arial_narrow_7.ttf", 20);
    if (!font) {
        printf("Errore caricamento font: %s\n", TTF_GetError());
        return 1;
    }

    SDL_StartTextInput();  // Abilita input testuale

    char inputText[MAX_LEN] = "";  // Buffer per il testo
    int quit = 0, textLength = 0, showCursor = 1;
    SDL_Event e;
    Uint32 lastCursorToggle = SDL_GetTicks(); // Tempo per il lampeggio del cursore

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }

            if (e.type == SDL_TEXTINPUT) {  // Input testuale
                if (textLength + strlen(e.text.text) < MAX_LEN) {
                    strcat(inputText, e.text.text);
                    textLength += strlen(e.text.text);
                }
            }

            if (e.type == SDL_KEYDOWN) {  // Gestione tasti speciali
                if (e.key.keysym.sym == SDLK_BACKSPACE && textLength > 0) {
                    inputText[--textLength] = '\0';  // Cancella ultimo carattere
                }
                if (e.key.keysym.sym == SDLK_RETURN) {
                    printf("Testo salvato: %s\n", inputText);  // Salva testo e resetta
                    inputText[0] = '\0';
                    textLength = 0;
                }
            }
        }

        // Lampeggio cursore
        if (SDL_GetTicks() - lastCursorToggle > CURSOR_BLINK_TIME) {
            showCursor = !showCursor;
            lastCursorToggle = SDL_GetTicks();
        }

        // Pulizia dello schermo
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Disegna il box dell'input
        SDL_Rect inputBox = {50, 200, 500, 50};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &inputBox);

        // Renderizza il testo digitato
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, inputText, textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = {60, 210, textSurface->w, textSurface->h};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        // Disegna il cursore lampeggiante
        if (showCursor) {
            SDL_Rect cursor = {60 + textRect.w + 5, 210, 2, textRect.h};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &cursor);
        }

        // Aggiorna lo schermo
        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput();  // Disattiva input testuale
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

