#ifndef WINDOWREAD_H
#define WINDOWREAD_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char password [], char text[]);
void insertscreen(FILE *file, Rectangle Name, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed);
void readscreen( FILE *file, Rectangle NaRead_screen);
#endif