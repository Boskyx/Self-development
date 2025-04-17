#include<stdio.h>
int main(void)
{
    int a[]={0, 1, 5, 3, 4}, *p, *c;
    p=&a[2];
    *++p;
    c=p;
    printf("%d\n", *p);
    printf("%d\n", a[2]);


}