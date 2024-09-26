#include<stdio.h>
#include<ctype.h>
int main(void)
{
    /*unsigned long int i, sum;
    i=18446744073709551614UL;
    sum=i+2UL;
    printf("%lu", sum);*/
    char ch='f';
    ch=toupper(ch); //convert a letter into its upper 
    printf("%c\n", ch);
    putchar(ch);
    ch=getchar();
    putchar(ch);
}