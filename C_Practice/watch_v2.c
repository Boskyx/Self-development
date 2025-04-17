/*Permits to display more than one series[i] at a time*/
#include<stdio.h>
#define N 5
int main(void)
{
    const int segments[10][7]={{1,1,1,1,1,1,0}, 
                               {0,1,1,0,0,0,0},
                               {1,1,0,1,1,0,1},
                               {1,1,1,1,0,0,1},
                               {0,1,1,0,0,1,1},
                               {1,0,1,1,0,1,1},
                               {1,0,1,1,1,1,1},
                               {1,1,1,0,0,0,0},
                               {1,1,1,1,1,1,1},
                               {1,1,1,1,0,1,1}};
    int number=0, i=0, series[N], check=N;
    printf("Digit the number:");
    for(int a=0; a<5; a++)
    {
        scanf("%d", &series[a]);
    }
    while(check>0)
    {
        if(series[i]>9)
            {printf("Error invalid number\n");}
        else
        {   
            switch(series[i]){
                case 0 :printf("---\n|  |\n---\n"); break;
                case 1 :printf("|\n|\n");break;
                case 2 :printf("__\n _|\n|__\n");break;
                case 3 :
                case 4 :
                case 5 :
                case 6 :
                case 7 :
                case 8 :
                case 9 :
                default:
                    break;
            }
        }
        check--;
        i++;
    }
}
        
        
        // while(check>0){
        //     if(segments[series[i]][0]==1)
        //         {
        //             printf("___ ");
        //         }
        //     else
        //         printf("    ");
        //     i++;
        //     check--;
        //     }
        // printf("\n");
        // check=5;
        // i=0;
        // while(check>0)
        // {
        //     if (segments[series[i]][1]==1||segments[series[i]][5]==1||segments[series[i]][6]==1)
        //     {
        //         if(segments[series[i]][5]==1)
        //             {printf("|");}
        //         if (segments[series[i]][6]==1)
        //         {
        //             printf("__");
        //         }
        //         if (segments[series[i]][1]==1)
        //         //In that way we capture the exception when we digit 7 and 0 where the segm 6 is 0 so it doesnt print the space for the 6
        //         {
        //             if ((segments[series[i]][1]==1&&segments[series[i]][0]==1&&segments[series[i]][5]==0&&segments[series[i]][6]==0&&segments[series[i]][2]==1&&segments[series[i]][3]==0&&segments[series[i]][4]==0)||
        //             (segments[series[i]][1]==1&&segments[series[i]][0]==1&&segments[series[i]][5]==1&&segments[series[i]][6]==0&&segments[series[i]][2]==1&&segments[series[i]][3]==1&&segments[series[i]][4]==1))
        //             {
        //                 printf("  |");
        //             }
        //             else
        //                 printf("|");
        //         }
        //         //printf("");
        //     }
        //     i++;
        //     check--;
        // }
        // printf("\n");
        // check=5;
        // i=0;
        // while(check>0)
        // {
        //     if (segments[series[i]][2]==1||segments[series[i]][3]==1||segments[series[i]][4]==1)
        //     {
        //         if(segments[series[i]][4]==1)
        //             {printf("|");}
        //         if (segments[series[i]][3]==1)
        //         {
        //             printf("__");
        //         }
        //         if (segments[series[i]][2]==1)
        //         //In that way we capture the exception when we digit 7 and 0 where the segm 6 is 0 so it doesnt print the space for the 6
        //         {
        //             if (segments[series[i]][1]==1&&segments[series[i]][0]==1&&segments[series[i]][5]==0&&segments[series[i]][6]==0&&segments[series[i]][2]==1&&segments[series[i]][3]==0&&segments[series[i]][4]==0)
        //             {
        //                 printf("  |");
        //             }
        //             else
        //                 printf("|");
        //         }
        //         //printf("   ");
        //     }
        //     i++;
        //     check--;
        // }printf("\n");