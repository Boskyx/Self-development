#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    float value, fee;
    bool flag;
    printf("Insert the ammount: ");
    scanf("%f", &value);
    if(value<2500.00f)
        {fee=value*0.017f+30.00f;
        printf("The fee is: %f\n", fee);}
    else
        {fee=value*0.0022f+100.00f;
        printf("The fee is: %.2f\n", fee);}
    return 0;
}