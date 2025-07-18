#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Windowmain.h"
#include "library.h"
int first_position=0;
void push(FILE *fp, char name[], char password[])
{
    char results_name[50],results_password[50], final[50];
    int i=0;
    for(i; i<strlen(name);i++)
    {
        results_name[i]=name[i]^2;
    }
    results_name[i]='\0';
    i=0;
    for(i; i<strlen(password);i++)
    {
        results_password[i]=password[i]^2;
    }
    results_password[i]='\0';
    fprintf(fp, "%-23s %s", results_name, results_password);
    fputs("\n",fp);
}

