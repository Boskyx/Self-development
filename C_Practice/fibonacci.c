#include<stdio.h>
int main(void)
{
    long fib[40]={0,1}, i=2, a=0, b=1;
    while(i<40)
    {
        fib[i]=fib[a]+fib[b];
        a++;
        b++;
        i++;

    }
    for(i=0; i<40; i++){
        printf("%ld ", fib[i]);
    }
}