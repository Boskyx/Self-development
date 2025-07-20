#include "/home/boskyx/Documents/raylib/src/raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Windowmode.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "library.h"

#define MAX_INPUT_CHARS 32
// Keycode for enter button on keyboard is 257
void homescreen(bool flag,  Rectangle Read,  Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char password [], char text[])
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
void insertscreen(FILE *file, Rectangle Name, Rectangle Home,Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed)
{
        //TO DO -> UNDERSTAND HOW TO USE THE OPENING OF FP FILE ETC...

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(Name, LIGHTGRAY);
        DrawRectangleRec(Password, LIGHTGRAY);
        DrawRectangleRec(Send, LIGHTGRAY);
        DrawRectangleRec(Home, BLUE);
        //DrawRectangleRec(Send, RED);
        DrawText("Sito", Name.x, Name.y - 15, 20, BLACK);
        DrawText("Password", Password.x , Password.y - 15, 20, BLACK);
        DrawText("Send", Send.x , Send.y+10, 20, BLACK);
        DrawText("H", Home.x+10, Home.y+5 , 20, WHITE);
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

int readscreen(FILE *file, Rectangle Read_screen,Rectangle Home)
{
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(Read_screen, LIGHTGRAY);
        DrawRectangleRec(Home, BLUE);
        int start=0, i=0, message_box=0;
        DrawText("H", Home.x+10, Home.y+5 , 20, WHITE);
        
        rewind(file);
        char buffer[50], decript[50];
        buffer[0]='\0';
        bool showMessageBox[50];
        int y=0;
        while(start<2)
        {
            fgets(buffer, sizeof(buffer), file);
            DrawText(buffer, Read_screen.x, Read_screen.y+y , 20, BLACK);
            y+=20; 
            start++;
        }
        while(fgets(buffer, sizeof(buffer), file)!=NULL)
            {
                for(i; i<strlen(buffer);i++)
                    {
                        if(buffer[i]==' '|buffer[i]=='\n'|buffer[i]=='\0' ){decript[i]=' ';}
                        else
                        {decript[i]=buffer[i]^2;}
                        
                    }
                decript[i]='\0';
                i=0;
                //Rectangle output_screen = { 0, y, 300, 17 };
                //DrawRectangleRec(output_screen, WHITE);
                DrawText(decript, Read_screen.x, Read_screen.y+y , 20, BLACK);
                if (GuiButton((Rectangle){ 400, Read_screen.y+y, 15, 15 }, "#191#")) showMessageBox[message_box] = true;
                y+=20; 
                message_box++;
            }
        for (int x=0; x<message_box;x++)
        {
            if (showMessageBox[x])
            {
                char message[128];
                sprintf(message, "Hi! This is a message for the row %d", x);
                int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                    "#191#Options", message, "Change;Delete"); //0 when press x, 1 for the first button on the left and 2 for the second one on the right
                
                //TO BE COMPLETE, it needs all the instruction for change_row you must have the possibility to change only password or name
                switch (result)
                {
                case 1:
                    change_row(file, x);
                    break;

                case 2:
                    {   delete_row(file, x);
                        return 1;
                    }break;

                default:
                    break;
                }
                //printf("%d\n", result);
                if (result >= 0) showMessageBox[x] = false;
            }
        }

        EndDrawing();
}

//NEW FUNCTIONS TO BE COMPLETED AND TESTED

void change_row(FILE *file, int line)
{
    
}

void delete_row(FILE *file, int line)
{
    FILE *copy;
    int start=0, temp=0;
    char buffer[50];
    rewind(file);
    copy=fopen("copy.txt", "w");
    while(start<2)
    {
        fgets(buffer, sizeof(buffer), file);
        fprintf(copy, "%s", buffer);
        start++;
    }
    while(fgets(buffer, sizeof(buffer), file)!=NULL)
    {
        if(temp!=line){fprintf(copy, "%s", buffer); temp++;}
        else {temp++;}
    }
    fclose(copy);
    remove("database.txt");
    rename("copy.txt", "database.txt");

}


