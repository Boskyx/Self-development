#include <stdio.h>
#include "library.h"

void push(struct db *a, int *position)
{
    char nome[100], ch_nome;
    char pass[20], ch_pass;
    int stamp, k=0;
    printf("Inserire nome:");
    clear_buffer();
    ch_nome=getchar();
    while(ch_nome!='\n'&&k<100)
    {
        nome[k]=ch_nome,
        ch_nome=getchar();
        k++;
    }
    nome[k]='\0';
    printf("Inserire password:");
    //clear_buffer();
    k=0;
    ch_pass=getchar();
    while(ch_pass!='\n'&&k<20)
    {
        pass[k]=ch_pass,
        ch_pass=getchar();
        k++;
    }
    pass[k]='\0';
    printf("Inserire data solo numeri:");
    scanf("%d", &stamp);
    strcpy(a[*position].name,nome); //non si puo copiare un array char dentro un altro, bisogna passare per copia di stringa
    strcpy(a[*position].password,pass);
    a[*position].timestamp=stamp;
    (*position)++;
}