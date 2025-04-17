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
struct db *first = NULL; //initialize the first element of the list with Null (other elements will linked with this point as 0)

int position=0;
FILE *fp;


/*The MAIN 
THE CODE IS TO BE ADJUSTET FOR NOW I HAVE ONLY MANAGED THE WINDOW FILE FOR NOW*/
int main(int argc, char *argv[])
{
    window();
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
            //CALL THE LIBRARY.C FUNCTIONST FOR PUSH AND FIND
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


