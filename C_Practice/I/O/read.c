#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    FILE *fp;
    int i, j;
    char ch, str[20];
    fp=fopen("prova.txt", "a+"); //a+ open the file and append on it
    //ch=fgetc(fp);
    //while(ch!=EOF)
    //puts("");
    fputs(" prova scrittura aaa\n", fp);
    //fputs("prova scrittura aaa\n", fp);
    strcpy(str,"popolo");
    //fwrite(str, 1, (sizeof(str)/sizeof(str[0])), fp);
    //fwrite(str, 1, (sizeof(str)/sizeof(str[0])), fp);
    //printf("%s",fgets(str, sizeof(str), fp)); //it works when the while cicle is disabled otherwise the cursor is at the end of the file
    //fscanf(fp, "%d %d", &i, &j); //it reads 00 because there aren't more data
    //printf("%d%d", i, j);
    fclose(fp);
}