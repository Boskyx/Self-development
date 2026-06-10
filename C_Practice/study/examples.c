#include<stdio.h>
#include<string.h>
char xgets(char *s, ...);
struct bitfield{
	unsigned prova:1;
	unsigned andiamo:1;
}__attribute__((packed));
int main(void){
	char s[]="When, in the course of...", *p, test[50]; //test is used to see how memset works
	char array_2d[3][3];
	p=s+10;
	memmove(s, p, strlen(p)+1);
	printf("%s\n",s);
	memset(array_2d, 'A', 9);
	memset(test, 'A', 5);//initialize the first 5 bytes with the letter A, amazing how it's not necessary to use a for cicle
	printf("%s\n", test);
	printf("%s\n",(char*)array_2d); //this part doesnt work correctly because it prints "AAAAAAAAAhe course of..." 
				  	//It happens because there isn't a \0 at the end of array_2d and it takes the next part of memory that is string s
					//(char*) needs to tell to printf that is a cast to an array so treats it like that and not as a pointer to an array of chars
	memset(array_2d, '\0', 9);
	memset(array_2d, 'A', 8); // This part WORKS because set all the bytes to \0 and then add 8 bytes so the last one is the null terminator and printf know
				  // that this is a stop
	printf("%s\n", (char*)array_2d);
#if 0
	for(int i=0; i<3; i++)				//
		for(int j=0; j<3; j++)			//This part works correctly
			printf("%c\n", array_2d[i][j]); //
 #endif
	return 0;

}

