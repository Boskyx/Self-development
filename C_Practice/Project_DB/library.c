#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Windowmain.h"
#include "library.h"
struct db {
    char row[100];
    struct db *next;
};
struct db *first = NULL;
void push(FILE *fp, char name[], char password[])
{

    fprintf(fp, "%-10s", name);
    fprintf(fp, "%20s", password);
    fputs("\n",fp);
}
struct db* find(FILE *fp)
{
    
    rewind(fp);
    struct db *new_node;
    static char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp)!=NULL)
        {
            new_node=malloc(sizeof(struct db));
            strncpy(new_node->row, buffer, sizeof(new_node->row)-1);    
            new_node->row[sizeof(new_node->row)-1]='\0';
            new_node->next=first;
            first=new_node;
        }
    return first;
}

