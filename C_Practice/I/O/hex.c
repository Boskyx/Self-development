/*THIS PROGRAM TAKE AS INPUT ONE FILE (EG HEX.C) AND OPENS IT IN BYNARY MODE
  READS ONE LINE AT A TIME AND PRINT THE HEX VALUE FOR EACH BYTE (DIVIDED BY 10 BYTES FOR ROW) AND THE 
  CORRESPONDING CHAR ASSOCIATED TO THE HEX VALUE
  WHEN YOU RUN FROM TERMINAL YOU HAVE TO WRITE ./hex hex.c  hex.c is the name as the program take as input
  for reading it in binary mode*/
#include<stdio.h>
int main(int argc, char *argv[])
{
    char *filename=argv[1];
    char buffer[10];
    int byte, count;
    size_t ByteRead;
    if (argc<2)
        {
            printf("command error");
            return 0;
        }
    FILE *fp;
    fp=fopen(filename, "rb");
    if (fp==NULL)
        {
            printf("Errore nel file");
            return 0;
        }
    printf("Hex code for 10 byte              Char\n______________________________    ______________\n");
    while((ByteRead=fread(buffer, 1, sizeof(buffer), fp))>0)
        {
            for(count=0; count<sizeof(buffer);count++)
                {
                    if(buffer[count]==10)
                        buffer[count]='.';
                    if (buffer[count]==EOF)
                        break;
                    printf("%x ", buffer[count]);

                }
                
            printf("%15s", buffer);
            buffer[0]='\0';
        }

    fclose(fp);

}
