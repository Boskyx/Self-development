#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include <stdio.h>
#include <stdbool.h>
#include "/home/boskyx/Documents/raylib/src/raylib.h"
void window(FILE *file);
void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char text[]);
void insertscreen(Rectangle Name,Rectangle Home, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed);
int readscreen(FILE *file, Rectangle Read_screen,Rectangle Home);
void log_in_page(Rectangle log_in_ins_passw, Rectangle log_in_send_pass, char Master_Key[], int log_in_new_passw, int master_key_sent, int log_in_send_button);
#endif
