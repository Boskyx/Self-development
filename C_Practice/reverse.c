#include<stdio.h>
int main(void)
{
    int first, second, number;
    printf("Insert 2 digits: ");
    scanf("%d", &number);
    first=number/10;
    second=number%10;
    printf("%d%d\n", second, first);
}