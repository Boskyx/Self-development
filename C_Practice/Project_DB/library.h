#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
void push(FILE *fp, char name[], char password[]);
struct db* find(FILE *fp);
#endif