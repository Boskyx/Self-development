#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Windowmain.h"
#include "Windowmode.h"
#include "library.h"

FILE *fp;
/*The MAIN 
THE CODE IS TO BE ADJUSTET FOR NOW I HAVE ONLY MANAGED THE WINDOW FILE FOR NOW*/
int main(int argc, char *argv[])
{
    char insert, *database=argv[1], buffer[1];
    size_t ByteRead;
    fp=fopen(database, "a+");
    if((ByteRead=fread(buffer, 1, sizeof(buffer),fp))==0)
        {
            fprintf(fp, "Nome         Password\n");
            fprintf(fp, "----         --------\n");
        }
    
    window(fp);
    fclose(fp);
}


