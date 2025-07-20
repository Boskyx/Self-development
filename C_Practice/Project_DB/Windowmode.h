#ifndef WINDOWREAD_H
#define WINDOWREAD_H
#include "/home/boskyx/Documents/raylib/src/raylib.h"
#include "raygui.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char password [], char text[]);
void insertscreen(FILE *file, Rectangle Name,Rectangle Home, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed);
int readscreen( FILE *file, Rectangle Read_screen,Rectangle Home);
void delete_row(FILE *file, int line);
void change_row(FILE *file, int line);
#endif