/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Surface* gScreenSurface=NULL;
SDL_Surface* gHelloWorld=NULL;
SDL_Window* gWindow=NULL;
SDL_Renderer* renderer=NULL;
SDL_Texture* gTexture=NULL;
void init();

int main(void)
{
    
    int x_m, y_m;
    printf("SDL da inizializzare\n");
    init();
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
    SDL_Event e; 
    bool quit = false; 
    while( !quit )
    { while( SDL_PollEvent( &e ))
        { 
            if( e.type == SDL_QUIT ) 
                {quit = true;} 
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
        //SDL_SetRenderDrawColor(renderer, 0,0,0,SDL_ALPHA_OPAQUE);
        
           
    }
    
    SDL_FreeSurface(gHelloWorld);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
	return 0;
}
void init()
{
    printf("ENTRATO IN INIT\n");
    fflush(stdout);
    gWindow = SDL_CreateWindow( "SDL Prova", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (gWindow==NULL)
        printf("Errore inizializzaizione finestra DSL");
    renderer=SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
        printf("errore inizializzazione");
}
