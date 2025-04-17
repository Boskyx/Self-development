#include<stdio.h>
int main(void)
{
    int i, N, series[N];
    printf("How many numbers do you want to insert: ");
    scanf("%d", &N);
    printf("digits numbers: ");
    for(i=0; i<N; i++)
        scanf("%d", &series[i]);
    printf("In revers order:");
    for(i=N-1; i>=0; i--)
        printf(" %d", series[i]);
    printf("\n");
    return 0;
}
