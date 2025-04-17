#include<stdio.h>
char reverse(char a[], int b);
int main(void)
{
    char phrase[20], word, *p;
    int i, num_char=0;
    printf("Enter a messagge: ");
    for(i=0; i<20; i++){
        word=getchar();
        if (word=='\n')
            break;
        else
            num_char++;
            phrase[i]=word;
    }
    printf("The reverse message is: ");
    for(p=&phrase[num_char]; p>=&phrase[0];p--)
        printf("%c", *p);
    printf("\n");

}
// char reverse(char a[], int b)
// {
//     char rev_mess[20]="";
//     rev_mess[0]="\0";
//     int i;
//     for(i=b; i<=0;i++)
//         rev_mess[i-b]=a[i];
//     rev_mess[i]="\0";
//     i=0;
//     return rev_mess;

// }