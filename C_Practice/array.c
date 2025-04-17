#include<stdio.h>
#include<math.h>
int main()
{
    int m[5][4]={ {1, 1, 1, 1},
                  {1, 0, 1, 0},
                  {1, 1, 0, 0}}; //In that way the rows 4 and 5 will intitialised with all 0
    double ident[2][2] = {[0][0]=1.0, [1][1]=1.0};
    const char hex_chars[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char buffer[33];
    int a=pow(2,8);//include math.h and the func pow is pow(base, esponent)
    sprintf(buffer, "%d", hex_chars[5]);
    printf("%c\n", hex_chars[13]);

}