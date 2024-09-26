#include<stdio.h>
int main(void)
{
    int grade;
    printf("Insert your grade: ");
    scanf("%d", &grade);
    switch (grade)
    {
    case 4:
        printf("Excellent");
        break;
    case 3:
        printf("perfect");
        break;
    case 2: case 1: case 0:
        printf("Failin");
        break;
    default:
        printf("Not valuable");
        break;
    }

}