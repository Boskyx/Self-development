#include<stdio.h>
#define MK_ID(n) i##n
int main(void){
    for(;;)
        printf("%s %s\n", __TIME__, __DATE__);
}