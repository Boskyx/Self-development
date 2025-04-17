#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include "Windowmain.h"
#include "Windowmode.h"


#define MAX_INPUT_CHARS 32
// Keycode for enter button on keyboard is 257
void window()
{
    // Inizializza la finestra
    /*Creazione dell'enum così da gestire le 3 modalità della finestra
    Quando si avvia la parte di codice della finestra parte subito con la HOME la quale richiama
    la funzione homescrren nella libreria windowmode che disegna la schermata principale
    In base al testo che si sceglierà READ o INSERT la switch case modificherà lo screen facendo entrare
    in quella schermata*/

    const int screenWidth = 800;
    const int screenHeight = 450;
    typedef enum {HOME, READ, INSERT} ScreenMode;
    ScreenMode currentscreen = HOME;
    InitWindow(screenWidth, screenHeight, "Project DataBase");

    char text[MAX_INPUT_CHARS + 1] = "", sent[MAX_INPUT_CHARS + 1] = "", password[]="andrea"; // Buffer per il testo
    int letterCount = 0;
    Rectangle Read = { screenWidth / 2 -150, screenHeight / 2 - 25, 100, 50 };
    Rectangle Insert = { screenWidth / 2+50 , screenHeight / 2 - 25, 100, 50 };
    Rectangle PasswordCheck = {0,0,10,10};
    Rectangle Passwordtest={5,50,80,30};
    bool flagpassword=false; //flag false == RED, true == GREEN
    int ReadPressed=0;
    int InsertPressed=0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        switch (currentscreen)
        {
        case HOME:
            {
                // Controlla se il mouse e' sopra read o insert e se ha cliccato
                if (CheckCollisionPointRec(GetMousePosition(), Read)&&IsMouseButtonPressed(0)&&flagpassword) 
                    {
                        ReadPressed=1;
                    }
                if (CheckCollisionPointRec(GetMousePosition(), Insert)&&IsMouseButtonPressed(0)&&flagpassword) 
                    {
                        InsertPressed=1;
                    }

                // Gestione input
                if (!flagpassword)
                {
                    int key = GetCharPressed();
                    while (key > 0)
                    {
                        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                        {
                            text[letterCount] = (char)key;
                            text[letterCount + 1] = '\0'; // Null-terminate
                            letterCount++;
                        }
                        key = GetCharPressed();
                    }

                    // Rimuovi carattere con backspace
                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        if (letterCount > 0)
                        {
                            letterCount--;
                            text[letterCount] = '\0';
                        }
                    }
                }
                //controlla se esiste testo nel buffer e appena si preme enter fa il check sulla password
                //poi prende la casella di testo e la svuota cosi da scrivere altro testo
                if(strlen(text)>0 && GetKeyPressed()==257)
                {
                    if(strcmp(text, password)==0) //password inserita corretta, mette il flagpassword a true cosi non puoi piu inserire il testo
                    {
                        text[0]='\0';
                        flagpassword=true;

                    }
                    else //password errata, cancella il testo e puoi riprovare
                    {
                        text[0]='\0';
                    }
                    letterCount=0;
                }
                if (InsertPressed==1)
                {
                    currentscreen=INSERT;
                }
                if (ReadPressed==1)
                {
                    currentscreen=READ;
                }
                homescreen(flagpassword, Read, Insert, PasswordCheck, Passwordtest, password, text);
            } break;
        
        case READ:
            {
                readscreen(Read);
            }
            break;

        case INSERT:
            {
                insertscreen(Read);
            }
            break;


        }


    }

    CloseWindow();
}

