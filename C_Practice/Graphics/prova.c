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
void close();
void init();
void loadMedia();

int main(void)
{
    
    printf("SDL da inizializzare\n");
    init();
    printf("SDL inizializzato\n");
    loadMedia();  
    printf("Mouse spostato\n");
    SDL_WarpMouseInWindow(gWindow, 50, 50);
    printf("USCITO DA LOADMEDIA\n");
    SDL_Event e; 
    bool quit = false; 
    while( !quit )
    { while( SDL_PollEvent( &e ))
        { 
            if( e.type == SDL_QUIT ) 
                {quit = true;} 
            //if(SDL_MOUSEMOTION==e.type)
            //{
            //    
            //    int x,y;
            //    SDL_GetMouseState(&x,&y);
            //    printf("x%d y%d\n", x, y);
            //}

        }      
    }
    
    SDL_FreeSurface(gHelloWorld);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    //close();
	return 0;
}
void init()
{
    printf("ENTRATO IN INIT\n");
    fflush(stdout);
    gWindow = SDL_CreateWindow( "SDL Prova", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (gWindow==NULL)
        printf("Errore inizializzaizione finestra DSL");
    //renderer=SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
        printf("errore inizializzazione");
    
    gScreenSurface = SDL_GetWindowSurface( gWindow );
    if(gScreenSurface==NULL)
        printf("Errore inizializzazione surface");
    
    
    
}
void loadMedia()
{
    printf("ENTRATO IN LOADMEDIA\n");
    fflush(stdout);
    gHelloWorld = SDL_LoadBMP("hello_world.bmp");
    gTexture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("hello_world.bmp"));
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );
    
    
}
//void close()
//{
//    // Libera la superficie dell'immagine solo se esiste
//    if (gHelloWorld != NULL) {
//        SDL_FreeSurface(gHelloWorld);
//        gHelloWorld = NULL;
//    }
//
//    // Distrugge la finestra solo se esiste
//    if (gWindow != NULL) {
//        SDL_DestroyWindow(gWindow);
//        gWindow = NULL;
//    }
//
//    // Chiude SDL
//    SDL_Quit();
//}