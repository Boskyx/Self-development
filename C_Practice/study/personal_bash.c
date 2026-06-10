#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_intro(void);
int main(void){
	while(1){
		char ch[10]; 
		static int start=0; //Use a static variable so it keeps the last value and doesn't reset to zero every time the cicle start
		if(start==0){system("clear");print_intro(); start++;}
		printf("192.268.1.1|bosky> ");
		//Fgets is taking the chars, with a maximum of ch size from the stdin, if you want you can
		//redirect the input from a file
		if (fgets(ch, sizeof(ch), stdin)== NULL) {printf("Error\n");}
		/*Check for the overflow, if the len of ch is 9 (so the buffer is full) we check for the 10th char to check if there is an overflow
		 * or if is the end of the strig. In case there is an overflow it stop the cicle and delete all the overflowed chars in the buffer*/
		printf("%ld\n", strlen(ch));
		if (strlen(ch)==9) {
			printf("%c\n", ch[9]);
			int check=fgetc(stdin); //If we insert 8 chars + \n (so press enter after the 8 chars) for a total of 9 the fgetc waits for an insert)
						//Maybe is needed a struct with a pointer to an char array to manage it in a dynamic way
			if ((ch[9] =='\n' || ch[9]=='\0') && (check=='\n' && check=='\0')) {printf("%s", ch); continue;}
			if(check!='\n' && check!='\0'){
				printf("Buffer overflow, you have inserted more than 9 chars\nInsert a correct input string\n"); 
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
			
			}
			else printf("%s", ch);
		}
		else printf("%s", ch);
		if(strcmp(ch, "\n")==0) continue;
	}
}
void print_intro(void){
	printf("**********************************\nYour are inside your personal bash\n**********************************\n");
}
