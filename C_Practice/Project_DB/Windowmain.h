#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include <stdio.h>
#include <stdbool.h>
#include "/home/boskyx/Documents/raylib/src/raylib.h"
#include "library.h"
void window(FILE *file);
void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char password [], char text[]);
void insertscreen(FILE *file, Rectangle Name,Rectangle Home, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed);
int readscreen(FILE *file, Rectangle Read_screen,Rectangle Home);
#endif