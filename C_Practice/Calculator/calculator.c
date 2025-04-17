#include<stdio.h>
#include"operations.h"

int main(void)
{
    int a, b;
    printf("Digit 2 numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("result: %d\n", add_num(a, b));
}