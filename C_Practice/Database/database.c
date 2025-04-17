#include <stdio.h>
#include <string.h>
#include "library.h"
struct db {
    char name[100];
    char password[20];
    int timestamp;
}db_andrea[100];
void push(void);
void find(void);
void clear_buffer(void);
int position=0;
char pass_db[10];
/*The MAIN */
int main(void)
{
    char insert, ch_pass;
    int j=0;
    printf("Scegliere pass db:");
    ch_pass=getchar();
    while(ch_pass!='\n'&&j<10)
    {
        pass_db[j]=ch_pass;
        ch_pass=getchar();
        j++;
    }
    for(;;) 
    {
        printf("Per inserire premi i, per trovare t, per uscire q: ");
        scanf("%c", &insert);
        switch(insert)
        {
        case 'i': 
            {   //clear_buffer();
                push();
            }
            break;
        case 't':
            {
                char check_pass[10], ch;
                int i=0;
                printf("Inserire password: ");
                clear_buffer();
                ch=getchar();
                while(ch!='\n'&&i<10)
                    {
                        check_pass[i]=ch;
                        ch=getchar();
                        i++;
                    }
                if(strcmp(pass_db, check_pass)==0)
                    {   find();
                        return 0;
                    }
                else
                    {
                        printf("Password errata");
                        return 0;
                    }
            }
        case 'q':
            return 0;
        default:
            printf("Illegal command");
            break;
        }
        printf("\n");
        clear_buffer();
    }
}

void push(void)
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
    strcpy(db_andrea[position].name,nome); //non si puo copiare un array char dentro un altro, bisogna passare per copia di stringa
    strcpy(db_andrea[position].password,pass);
    db_andrea[position].timestamp=stamp;
    position++;
}
void find(void)
{
    char search;
    char pass_db;
    char check[5], ch;
    int i=0, k=0;
    printf("Si conosce gia la lista, se no verra printata: ");
    //clear_buffer();
    ch=getchar();
    while(ch!='\n'&&k<5)
    {
        check[k]=ch;
        ch=getchar();
        k++;
    }
    while (strcmp(check, "no")==0&&i==0)
        {
            printf("Nome nel db\n");
            printf("--------\n");
            for(i; i<position; i++)
                printf("%s password: %s\n", db_andrea[i].name,db_andrea[i].password);
            printf("--------\n");
        }
    if(strcmp(check, "no")!=0)
        printf("non hai digitato no");
}
void clear_buffer(void)
{
    while(getchar() != '\n') ;
}