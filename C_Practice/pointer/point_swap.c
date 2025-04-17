#include<stdio.h>
void swap(int *first, int *second);

int main(void)
{
    int i, j;
    printf("Write 2 number: ");
    scanf("%d %d", &i, &j);
    printf("BEFORE -> i=%d, j=%d\n", i, j);
    swap(&i, &j);
    printf("AFTER -> i=%d, j=%d\n", i, j);
    
}

void swap(int *first, int *second)
{
    int a=*first;
    int b=*second;
    *first = b;
    *second=a;
}