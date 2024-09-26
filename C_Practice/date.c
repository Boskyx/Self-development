#include<stdio.h>
int main(void)
{
    int month, day, year;
    printf("insert date in format mm/dd/yyyy: ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("the date is: %d%.2d%d\n", year, month, day);
}