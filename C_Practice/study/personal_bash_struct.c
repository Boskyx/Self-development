// TO DO MODIFY THE CHECK OF OVERFLOW OG THE STRING

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_intro(void);
struct pls{
	int len_string;
	char string[];	
};
int main(void){
	struct pls *string = malloc(sizeof(*string)+(sizeof(char)*10));
	while(1){
		static int start=0; //Use a static variable so it keeps the last value and doesn't reset to zero every time the cicle start
		if(start==0){system("clear");print_intro(); start++;}
		printf("192.268.1.1|bosky> ");
		if (fgets(string->string, (sizeof(char)*10), stdin)== NULL) {printf("Error\n");}
		string->len_string=strlen(string->string);
		printf("%d\n", string->len_string);
		if (string->len_string>9) {
			printf("Buffer overflow, you have inserted more than 9 chars\nInsert a correct input string\n"); 
			}
		else printf("%s", string->string);
	}
}
void print_intro(void){
	printf("**********************************\nYour are inside your personal bash\n**********************************\n");
}
