#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    float number, largest;
    _Bool digit=true;
    while(digit==true)
        {printf("Insert a number or digit 0 or a negative number to quit: ");
        scanf("%f", &number);
        if (number<0||number==0)
            digit=false;
        else
            if (number>largest)
                largest=number;
        }
    printf("the largest number is: %.2f\n", largest);
}