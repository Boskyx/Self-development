#ifndef WINDOWREAD_H
#define WINDOWREAD_H
#include "/home/boskyx/Documents/raylib/src/raylib.h"
#include "raygui.h"
#include <stdbool.h>
#include <stdio.h>


void homescreen(bool flag, Rectangle Read, Rectangle Insert, Rectangle PasswordCheck, Rectangle PasswordTest, char text[]);
void insertscreen(Rectangle Name,Rectangle Home, Rectangle Password, Rectangle Send, char name[], char password[], int namePressed, int passwordPressed);
int readscreen( FILE *file, Rectangle Read_screen,Rectangle Home);
void log_in_page(Rectangle Read_page_ins_passw, Rectangle log_in_send_pass ,char Master_Key[], int log_in_new_passw, int master_key_sent, int log_in_send_button);
void log_in_page_check_password(Rectangle Read_page_ins_passw, char Master_Key_Input[], int log_in_new_passw);
void delete_row(FILE *file, int line);
void change_row(FILE *file, int line);
#endif
