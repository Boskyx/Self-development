#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Windowmode.h"
#include "library.h"

#define MAX_INPUT_CHARS 32
struct db {
    char row[100];
    struct db *next;
};
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
void insertscreen(FILE *file, Rectangle Name, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed)
{
        //TO DO -> UNDERSTAND HOW TO USE THE OPENING OF FP FILE ETC...

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(Name, LIGHTGRAY);
        DrawRectangleRec(Password, LIGHTGRAY);
        DrawRectangleRec(Send, LIGHTGRAY);
        //DrawRectangleRec(Send, RED);
        DrawText("Name", Name.x, Name.y - 15, 20, BLACK);
        DrawText("Password", Password.x , Password.y - 15, 20, BLACK);
        DrawText("Send", Send.x , Send.y - 15, 20, BLACK);
        if(namePressed==1)
        {
            DrawRectangleLinesEx(Name, 5, (namePressed==0) ? LIGHTGRAY : GREEN);
        }
         if(passwordPressed==1)
        {
            DrawRectangleLinesEx(Password, 5, (passwordPressed==0) ? LIGHTGRAY : GREEN);
        }        
        DrawText(name, Name.x + 5, Name.y + 15, 15, BLACK);
        DrawText(password, Password.x + 5, Password.y + 15, 15, BLACK);
        EndDrawing();
}

void readscreen(FILE *file, Rectangle Read_screen)
{
        //RESOLVE THE FUNCTION IT GOES IN FAULT AND DOESNT REVERSE THE LIST AT NOW
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(Read_screen, LIGHTGRAY);
        struct db *origin_node=find(file);
        struct db *first;
        first=origin_node;
        while(origin_node!=NULL)
        {
            origin_node=origin_node->next;
            struct db *new_node;
            new_node=malloc(sizeof(struct db));
            new_node=origin_node;
            new_node->next=first;
            first=new_node;
        }
        DrawText(first->row, Read_screen.x, Read_screen.y , 20, BLACK);
        EndDrawing();
}

