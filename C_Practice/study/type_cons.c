#include<stdio.h>
#include<string.h>
int main(void){
	const char *string="Test, cannot modify it";
	printf("%s, %ld\n", string,sizeof(string));
}
