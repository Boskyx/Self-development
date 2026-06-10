#include <stdio.h>

int swap_endianess(int value)
{
	int left_most=(value & 0x000000FF)<<24;
	int left_middle=(value & 0x0000FF00)<<8;
	int righ_middle=(value & 0x00FF0000)>>8;
	int right_most=(value & 0xFF000000)>>24;	

	int result = (left_most|left_middle|righ_middle|right_most);
	return result;

}

int main(void){

	int number_insert=0, little_endian=0;
	printf("Insert a number: ");
	scanf("%x", &number_insert);
	little_endian=swap_endianess(number_insert);	
	printf("initial number was 0x%x\n", number_insert);
	printf("Little endian: 0x%x\n", little_endian);
	return 0;
}

