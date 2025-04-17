#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Windowmain.h"
#include "library.h"
struct db {
    char name[100];
    char timestamp[20];
    struct db *next;
};
struct db *first = NULL;

void push(void)
{
    struct db *new_node;
    new_node=malloc(sizeof(struct db));
    char nome[100], ch_nome, data[30],ch_data;
    int k=0, j=0;
    printf("Inserire nome:");
    scanf("%s", nome);
    //nome[k]='\0';
    printf("Inserire data:");
    scanf("%s", data);    
    //data[j]='\0';
    strcpy(new_node->name,nome); //non si puo copiare un array char dentro un altro, bisogna passare per copia di stringa
    fprintf(fp, "%-10s", nome);
    fprintf(fp, "%20s", data);
    fputs("\n",fp);
    strcpy(new_node->timestamp, data);
    new_node->next=first;
    first=new_node;
    position++;
}
void find(void)
{
    int i=0;
    char nome[10], data[10], buffer[100], check[100];
    size_t ByteReader;
    //clear_buffer();
    printf("%-10s%20s\n%-10s%20s\n","Nome","Password","-----","-----");
    for(i; i<2;i++)
        fgets(buffer, sizeof(buffer), fp);
    fgets(buffer, sizeof(buffer), fp);
    while(strlen(buffer)>0)
        {
            printf("%s", buffer);
            strcpy(check, buffer);
            if(fgets(buffer, sizeof(buffer), fp)==NULL)
                break;
        }
}
void clear_buffer(void)
{
    while(getchar() != '\n') ;
}