#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct db {
    char name[100];
    char timestamp[20];
    struct db *next;
};
struct db *first = NULL; //initialize the first element of the list with Null (other elements will linked with this point as 0)
void push(void);
void find(void);
void clear_buffer(void);
int position=0;
FILE *fp;


/*The MAIN */
int main(int argc, char *argv[])
{
    char insert, *database, buffer[1];
    size_t ByteRead;
    database=argv[1];
    fp=fopen(database, "a+");
    if((ByteRead=fread(buffer, 1, sizeof(buffer),fp))==0)
        fputs("Nome        Password\n-------  ---------------\n", fp);
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
                find();
                return 0;
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
    fclose(fp);
}

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
