#include<stdio.h>
#include<stdlib.h>
int main(void){
	while(1){
		static int counting=0;
		int *p=malloc(1000000000);
		counting++;
		if(!p) { printf("Out of memory after %d cicles\n", counting); exit(1);}
	}
}
