#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    int len;
    printf("Enter the message: ");
    ch=getchar();
    printf("%c\n", ch);
    while (ch!='\n'){
        len++;
        ch=getchar();
        printf("%c\n", ch);
    }
    printf("%d\n", len);
    
}