#include<stdio.h>
void quick_sort(int a[], int low, int high);
#define N 4

int main(void)
{ 
   int a[N], i;
   printf("Enter %d values to be sorted:", N);
   for(i=0; i<N; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, N-1);
    printf("Sequence in order: ");
    for(i=0; i<N; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void quick_sort(int a[], int low, int high)
{
    int check,x=N;
    while(x>0){
        for(int i=0; i<high+1;){
            if(i==high) break;
            if(a[i]<a[i+1]) i++;
            else{ //if(a[i]>a[i+1])
                check=a[i+1];
                a[i+1]=a[i];
                a[i]=check;
                i++;
            }
        } 
        x--;  
    }
}