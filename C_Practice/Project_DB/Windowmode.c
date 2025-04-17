#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "Windowmode.h"

#define MAX_INPUT_CHARS 32
// Keycode for enter button on keyboard is 257
void homescreen(bool flag, struct Rectangle Read, struct Rectangle Insert,struct Rectangle PasswordCheck,struct Rectangle PasswordTest, char password [], char text[])
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
void insertscreen(Rectangle prova)
{
        //WRITE THE REAL CODE AND UNDERSTAND HOW TO USE THE OPENING OF FP FILE ETC...
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(prova, LIGHTGRAY);
        EndDrawing();
}

void readscreen(Rectangle prova)
{
        //WRITE THE REAL CODE AND UNDERSTAND HOW TO USE THE OPENING OF FP FILE AND THE PRINTING ON THE WINDOWS
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(prova, LIGHTGRAY);
        EndDrawing();
}