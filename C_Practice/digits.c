#include<stdio.h>
int main(void)
{
    int number;
    printf("Digit a number: ");
    scanf("%d", &number);
    if (number<100)
        printf("2 digits\n");
    else if (number < 1000)
        printf("3 digits\n");
}