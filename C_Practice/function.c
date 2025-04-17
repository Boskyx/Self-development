#include<stdio.h>
double average (double a, double b)
{
    return (a+b)/2;
}
int main(void)
{
    double x, y, z;
    printf("Enter 3 numbers: ");
    scanf("%lf%lf%lf", &x,&y,&z);
    printf("%g %g %g", average(x, y), average(y, z), average(x, z));
}