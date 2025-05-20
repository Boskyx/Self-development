#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"
#include "library.h"
void window(FILE *file);
void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char password [], char text[]);
void insertscreen(FILE *file, Rectangle Name, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed);
void readscreen(FILE *file, Rectangle Read_screen);
#endif