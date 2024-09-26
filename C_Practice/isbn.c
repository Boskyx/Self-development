#include<stdio.h>
int main(void)
{
    int gsi, group_id, publ_code, item_number, check_digit;
    printf("Insert the ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gsi, &group_id, &publ_code, &item_number, &check_digit);
    printf("GSI:%d\nGroup Id:%d\nPub:%d\nItem Id:%d\nCheck digits:%d\n", gsi, group_id, publ_code, item_number, check_digit);
}