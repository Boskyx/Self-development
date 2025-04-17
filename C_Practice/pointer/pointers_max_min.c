#include<stdio.h>
#define N 10
void max_min(int a[], int n, int *max, int*min);
int main(void)
{
    int b[N], i, big, small;
    printf("Enter 10 numbers: ");
    for(i=0; i<N; i++)
        scanf("%d", &b[i]);
    max_min(b, N, &big, &small);
    printf("min is: %d\n", small);
    printf("max is: %d\n", big);
    return 0;
}
void max_min(int a[], int n, int *max, int *min)
{
    int i;
    *max= *min= a[0];
    for(i=1; i<n; i++){
        if (a[i]>*max)
            *max=a[i];
        else if (a[i]<*min)
            *min=a[i];
    }

}