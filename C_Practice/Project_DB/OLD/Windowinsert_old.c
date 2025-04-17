#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include "Windowinsert.h"


#define MAX_INPUT_CHARS 32
// Keycode for enter button on keyboard is 257
void window()
{
    // Inizializza la finestra
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
            ClearBackground(RAYWHITE);
        }
        if (ReadPressed==1)
        {
            //INSERT CODE
        }

        // Disegna la scena
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangleRec(Read, LIGHTGRAY);
        DrawRectangleRec(Insert, LIGHTGRAY);
        if(flagpassword)
            DrawRectangleRec(PasswordCheck, GREEN);
        else
            DrawRectangleRec(PasswordCheck, RED);
        DrawRectangleRec(Passwordtest, LIGHTGRAY);
        DrawRectangleLinesEx(Read, 5, (flagpassword==false) ? LIGHTGRAY : GREEN);
        DrawRectangleLinesEx(Insert, 5, (flagpassword==false) ? LIGHTGRAY : GREEN);
        DrawText("Read", Read.x + 5, Read.y + 15, 20, BLACK);
        DrawText("Insert", Insert.x+5, Insert.y+15, 20, BLACK);
        DrawText("Digita password", 5, 30, 15, BLACK);
        DrawText(text, Passwordtest.x + 5, Passwordtest.y + 15, 15, BLACK);

        EndDrawing();
    }

    CloseWindow();
}

void homescreen(bool flag, Rectangle Read, Rectangle Insert,Rectangle PasswordCheck,Rectangle PasswordTest, char password [], char text[])
{
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(Read, LIGHTGRAY);
        DrawRectangleRec(Insert, LIGHTGRAY);
        if(flag)
            DrawRectangleRec(PasswordCheck, GREEN);
        else
            DrawRectangleRec(PasswordCheck, RED);
        DrawRectangleRec(PasswordTest, LIGHTGRAY);
        DrawRectangleLinesEx(Read, 5, (flag==false) ? LIGHTGRAY : GREEN);
        DrawRectangleLinesEx(Insert, 5, (flag==false) ? LIGHTGRAY : GREEN);
        DrawText("Read", Read.x + 5, Read.y + 15, 20, BLACK);
        DrawText("Insert", Insert.x+5, Insert.y+15, 20, BLACK);
        DrawText("Digita password", 5, 30, 15, BLACK);
        DrawText(text, PasswordTest.x + 5, PasswordTest.y + 15, 15, BLACK);

        EndDrawing();
}