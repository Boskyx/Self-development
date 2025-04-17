#include<stdio.h>
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
    int number=0, i=1;
    printf("Digit the number:");
    scanf("%d", &number);
    if(number>9)
        {printf("Error invalid number\n");}
    else
    {
        if(segments[number][0]==1)
            {
                printf("___\n");
            }
        if (segments[number][1]==1||segments[number][5]==1||segments[number][6]==1)
        {
            if(segments[number][5]==1)
                {printf("|");}
            if (segments[number][6]==1)
            {
                printf("__");
            }
            if (segments[number][1]==1)
            //In that way we capture the exception when we digit 7 and 0 where the segm 6 is 0 so it doesnt print the space for the 6
            {
                if ((segments[number][1]==1&&segments[number][0]==1&&segments[number][5]==0&&segments[number][6]==0&&segments[number][2]==1&&segments[number][3]==0&&segments[number][4]==0)||
                (segments[number][1]==1&&segments[number][0]==1&&segments[number][5]==1&&segments[number][6]==0&&segments[number][2]==1&&segments[number][3]==1&&segments[number][4]==1))
                {
                    printf("  |");
                }
                else
                    printf("|");
            }
            printf("\n");
        }
        if (segments[number][2]==1||segments[number][3]==1||segments[number][4]==1)
        {
            if(segments[number][4]==1)
                {printf("|");}
            if (segments[number][3]==1)
            {
                printf("__");
            }
            if (segments[number][2]==1)
            //In that way we capture the exception when we digit 7 and 0 where the segm 6 is 0 so it doesnt print the space for the 6
            {
                if (segments[number][1]==1&&segments[number][0]==1&&segments[number][5]==0&&segments[number][6]==0&&segments[number][2]==1&&segments[number][3]==0&&segments[number][4]==0)
                {
                    printf("  |");
                }
                else
                    printf("|");
            }
            printf("\n");
        }

    }


}