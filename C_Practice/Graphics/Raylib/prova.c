#include "raylib.h"
#include <string.h>
#include <stdio.h>

#define MAX_INPUT_CHARS 32

int main(void)
{
    // Inizializza la finestra
    const int screenWidth = 800;
    const int screenHeight = 450;
    int GetCharPressed(void);
    InitWindow(screenWidth, screenHeight, "Raylib - Input Box");

    char text[MAX_INPUT_CHARS + 1] = "", sent[MAX_INPUT_CHARS + 1] = ""; // Buffer per il testo
    int letterCount = 0;
    Rectangle textBox = { screenWidth / 2 - 100, screenHeight / 2 - 25, 200, 50 };
    Rectangle enterBox = { screenWidth / 2 - 100, screenHeight / 2 + 50, 70, 50 };
    bool textOn = false;
    int buttonPressed=0;
    int enterPressed=0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Controlla se il mouse è sopra il box di testo e se ha cliccato per abilitare la scrittura
        if (CheckCollisionPointRec(GetMousePosition(), textBox)&&IsMouseButtonPressed(0)&&buttonPressed==0) 
            {
                textOn = true;
                buttonPressed=1;
            }
        else if (CheckCollisionPointRec(GetMousePosition(), textBox)&&IsMouseButtonPressed(0)&&buttonPressed==1) 
            {
                textOn = false;
                buttonPressed=0;
            }  
        // Controlla se il tasto enter e' stato premuto
        if (CheckCollisionPointRec(GetMousePosition(), enterBox)&&IsMouseButtonPressed(0)&&enterPressed==0) 
            {
                enterPressed=1;
            }
        else if (CheckCollisionPointRec(GetMousePosition(), enterBox)&&IsMouseButtonPressed(0)&&enterPressed==1) 
            {
                enterPressed=0;
            }  

        // Gestione input
        if (textOn)
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
        //controlla se esiste testo nel buffer e appena si preme enter viene printato il testo scritto
        //poi prende la casella di testo e la svuota cosi da scrivere altro testo
        if(strlen(text)>0 &&enterPressed==1)
        {
            strcpy(sent, text);
            printf("testo digitato: %s\n",sent);
            enterPressed=0;
            text[0]='\0';
            letterCount=0;
        }

        printf(GetCharPressed());
        // Disegna la scena
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Digita qualcosa:", screenWidth / 2 - 100, screenHeight / 2 - 50, 20, DARKGRAY);
        DrawRectangleRec(textBox, LIGHTGRAY);
        if(textOn)
            DrawRectangleRec(enterBox, GREEN);
        else
            DrawRectangleRec(enterBox, LIGHTGRAY);
        DrawRectangleLinesEx(textBox, 2, (buttonPressed==1) ? RED : DARKGRAY);
        DrawText(text, textBox.x + 5, textBox.y + 15, 20, BLACK);
        DrawText("enter", enterBox.x, (enterBox.y+12.5), 25, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
