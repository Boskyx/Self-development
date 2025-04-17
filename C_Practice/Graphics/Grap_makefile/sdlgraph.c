#include<stdio.h>
#include"sdlgraph.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
char rect(SDL_Window* gWindow, SDL_Renderer* renderer)
{
    char testo[50]="";
    printf("SDL da inizializzare\n");
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);  
    SDL_Rect rect = {0,0, 100, 100};
    SDL_SetRenderDrawColor(renderer, 255,100,0,SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderPresent(renderer);  
    SDL_RenderClear(renderer);  
    printf("SDL inizializzato\n");
    printf("Mouse spostato\n");
    SDL_WarpMouseInWindow(gWindow, 320,240);
    SDL_StartTextInput();
    int x_m, y_m;
    SDL_Event e; 
    bool quit = false; 
    while( !quit )
    { while( SDL_PollEvent( &e ))
        { 
            if( e.type == SDL_QUIT ) 
                {quit = true;} 
            if(SDL_TEXTINPUT==e.type)
                {
                    strcat(testo, e.text.text);
                    //return *testo;
                    printf("testo %s\n", testo);
                }
            if(SDL_MOUSEMOTION==e.type)
            {
                SDL_GetMouseState(&x_m,&y_m);
                printf("x%d y%d\n", x_m, y_m);
            }
            if(SDL_MOUSEBUTTONDOWN==e.type)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    printf("premuto in x:%d e y:%d\n", x_m,y_m);
                    if(x_m>=0&&x_m<=100&&y_m>=0&&y_m<=100)
                        {
                            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                            SDL_RenderClear(renderer);
                            SDL_RenderPresent(renderer);
                        }  
                }
            }
        } 
    }
    

}

