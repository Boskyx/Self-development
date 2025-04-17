#include<stdio.h>
#include"sdlgraph.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
SDL_Surface* gScreenSurface=NULL;
SDL_Surface* gHelloWorld=NULL;
SDL_Window* gWindow;
SDL_Renderer* renderer;
SDL_Texture* gTexture=NULL;
int main(void)
{
    SDL_Window* gWindow = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    rect(gWindow, renderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}