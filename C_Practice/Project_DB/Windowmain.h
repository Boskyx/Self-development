#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include <stdbool.h>
#include "raylib.h"
void window();
void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char password [], char text[]);
void insertscreen( Rectangle prova);
void readscreen( Rectangle prova);
#endif