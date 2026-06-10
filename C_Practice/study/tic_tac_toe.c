/*Fix to do:
 * BUG: if you insert alpha chars it go in an infinite loop.
 * TODO: Doesn't ask for quit or a new game after the victory, only in case of spare.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initiliaze_matrix(char matrix[3][3]);
void print_matrix(char matrix[3][3]);
void player_move(int move[2], char matrix[3][3], char pm[1]);
int check_move(int move[2], char matrix[3][3]);
char check_winner(char matrix[3][3]);
int main(void){
	static char matrix[3][3];
	char exit_code[1], pm[1];
	int move[2], correct_insert=0, total_move=0;
	system("clear");
	printf("Here starts your game\nFirst slot up-left corner is 00 the last in the right-down corner is 22\n");
	initiliaze_matrix(matrix);
	while(strcmp(exit_code, "q")!=0)
	{
		while(correct_insert==0)
		{
			int go=0;
			if(check_winner(matrix)!='N'){printf("The winner is %c\n", check_winner(matrix)); exit(0);}
			printf("Digit where you want to put your X, example 11 stands for row 1 column 1: ");
			pm[0]='X';
			scanf("%1d%1d", &move[0], &move[1]);
			if (check_move(move, matrix)==1){printf("There is already a move in the place, try again\n");go=1;}
			for(int i=0; i<2; i++)
			{
				if(move[i]>2) {printf("Move out of boundaries, try again\n"); go=1; break; } 
			}
			if(check_winner(matrix)!='N'){printf("The winner is %c\n", check_winner(matrix)); exit(0);}
			if(go==0) {player_move(move, matrix, pm);correct_insert=1;total_move++;}
			if(total_move==9){
				int option;
				correct_insert=0;
				system("clear");
				print_matrix(matrix); 
				printf("End of moves, restart the game.\n"); 
				printf("Do you want to restart the game? y for Yes and n for No: ");
				while (getchar() != '\n');
				option=getchar();
				if(option=='y') {system("clear"); initiliaze_matrix(matrix);}
				else exit(0);
				total_move=0;
			}
		}
		correct_insert=0;
		system("clear");
		print_matrix(matrix);
		while(correct_insert==0)
		{
			int go=0;
			if(check_winner(matrix)!='N'){printf("The winner is %c\n", check_winner(matrix)); exit(0);}
			printf("Digit where you want to put your O, example 11 stands for row 1 column 1: ");
			pm[0]='O';
			scanf("%1d%1d", &move[0], &move[1]);
			if (check_move(move, matrix)==1){printf("There is already a move in the place, try again\n");go=1;}
			for(int i=0; i<2; i++)
			{
				if(move[i]>2) {printf("Move out of boundaries, try again\n"); go=1; break;}
			}
			if(check_winner(matrix)!='N'){printf("The winner is %c\n", check_winner(matrix)); exit(0);}
			if(go==0) {player_move(move, matrix, pm); correct_insert=1;total_move++;}
		}
		correct_insert=0;
		system("clear");
		print_matrix(matrix);
	}	
	return 0;
}

void player_move(int move[2], char matrix[3][3], char player_move[1]){	
	matrix[move[0]][move[1]]=player_move[0];
}

void initiliaze_matrix(char matrix[3][3]){	
	for(int i=0; i<3;i++)
	{
		for (int j=0; j<3; j++)
		{
			matrix[i][j]='-';	
			printf("|-|");
		}
		printf("\n");
	}
}

void print_matrix(char matrix[3][3]){
	for(int i=0; i<3;i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("|%c| ", matrix[i][j]);
		}
		printf("\n");
	}
}
int check_move(int move[2], char matrix[3][3]){
	int check=0;
	if (matrix[move[0]][move[1]]!='-') return check=1;
	else return check;
}
char check_winner(char matrix[3][3])
{
	for (int i=0; i<3;i++)
	{
		if(matrix[i][0]=='X'&&matrix[i][1]=='X'&&matrix[i][2]=='X')return 'X';
		if(matrix[i][0]=='O'&&matrix[i][1]=='O'&&matrix[i][2]=='O')return 'O';
	}
	for(int i=0; i<3; i++)
	{
		if(matrix[0][i]=='X'&&matrix[1][i]=='X'&&matrix[2][i]=='X') return 'X';
		if(matrix[0][i]=='O'&&matrix[1][i]=='O'&&matrix[2][i]=='O') return 'O';
	}
	if(matrix[0][0]=='X'&&matrix[1][1]=='X'&&matrix[2][2]=='X')return 'X';
	if(matrix[2][0]=='X'&&matrix[1][1]=='X'&&matrix[0][2]=='X')return 'X';
	if(matrix[0][0]=='O'&&matrix[1][1]=='O'&&matrix[2][2]=='O')return 'O';
	if(matrix[2][0]=='O'&&matrix[1][1]=='O'&&matrix[0][2]=='O')return 'O';
	return 'N';
}
