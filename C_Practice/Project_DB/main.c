#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Windowmain.h"

/*
TO RUN THE PROGRAM "SUDO ./MAIN DATABASE.TXT"
*/

FILE *fp;
int main(int argc, char *argv[])
{
    char *database=argv[1], buffer[1];
    size_t ByteRead;
    fp=fopen(database, "a+");
    if((ByteRead=fread(buffer, 1, sizeof(buffer),fp))==0)
        {
            fprintf(fp, "Sito                   Password\n");
            fprintf(fp, "--------------         -------------\n");
        }
    
    window(fp);
    fclose(fp);
}

