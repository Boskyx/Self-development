#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

SDL_Window* gWindow = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* gTextTexture = NULL;

void init();
void handleTextInput(const char* inputText);
void renderText(const char* text);

int main(void)
{
    init();

    bool quit = false;
    SDL_Event e;
    char inputText[100] = "";  // Variabile per memorizzare il testo inserito

    while (!quit)
    {
        // Gestione degli eventi
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_TEXTINPUT)  // Cattura l'input da tastiera
            {
                strcat(inputText, e.text.text);  // Aggiungi il testo alla variabile
            }
            else if (e.type == SDL_KEYDOWN)  // Gestione tasti speciali
            {
                if (e.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText) > 0)
                {
                    inputText[strlen(inputText) - 1] = '\0';  // Rimuove l'ultimo carattere
                }
                if (e.key.keysym.sym == SDLK_RETURN)  // Quando premi "Enter"
                {
                    printf("Testo inserito: %s\n", inputText);
                }
            }
        }

        // Puliamo lo schermo
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Visualizziamo il testo
        renderText(inputText);

        // Presentiamo il rendering alla finestra
        SDL_RenderPresent(renderer);
    }

    // Liberiamo le risorse e chiudiamo SDL
    SDL_DestroyTexture(gTextTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();

    return 0;
}

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Errore inizializzazione SDL: %s\n", SDL_GetError());
        exit(1);
    }

    gWindow = SDL_CreateWindow("SDL Text Input", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        printf("Errore creazione finestra: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Errore creazione renderer: %s\n", SDL_GetError());
        exit(1);
    }

    // Abilita l'input da tastiera
    SDL_StartTextInput();
}

void renderText(const char* text)
{
    // Per visualizzare il testo, avrai bisogno di una libreria per il rendering del testo
    // Ad esempio, puoi usare SDL_ttf (SDL TrueType Font). Aggiungi questa libreria per facilitare il rendering del testo.
    // Codice per caricare e renderizzare il testo...
    
    // Per esempio:
    // SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, {255, 255, 255});
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    // SDL_RenderCopy(renderer, texture, NULL, &textRect);
    // SDL_FreeSurface(textSurface);
    // SDL_DestroyTexture(texture);
}
