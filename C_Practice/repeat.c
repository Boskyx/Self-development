#include<stdio.h>
int main(void)
{
    int seq[30], i=0;
    int ch;
    printf("Enter a number: ");
    ch=getchar(); //the first number is a character and is converted in int ASCII so if you digit 2 the var ch has 50
    //Convert Ascii do decimal
    while(ch != '\n'){
        switch (ch)
        {
        case 48:
            seq[i]=0;
            break;
        case 49:
            seq[i]=1;
            break;
        case 50:
            seq[i]=2;
            break;
        case 51:
            seq[i]=3;
            break;
        case 52:
            seq[i]=4;
            break;
        case 53:
            seq[i]=5;
            break;    
        case 54:
            seq[i]=6;
            break; 
        case 55:
            seq[i]=7;
            break;
        case 56:
            seq[i]=8;
            break; 
        case 57:
            seq[i]=9;
            break; 
        default:
            break;
        }
        i++;
        ch=getchar();
    }
    printf("There are %d digits\n", i);
    /*Check if there are repeated digits and if the final array already has the digit*/
    int rep[i], k=0, j=1, sequ=0, pri=0, x=0, check=0;
    while(k<i)
    {
        while(j<i)
        {
            if (seq[k]==seq[j])
            { 
                while(x<sequ+1)
                {
                    if(rep[x]==seq[k]) {x++; check++;}
                    else{x++;}
                }
                x=0;
                if(check==0)
                {
                    rep[sequ]=seq[k];
                    j++;
                    sequ++;
                }
                else {j++; check=0;}
                break; //in that way if there is a corrispondences the while is stopped and k is increases
            }
            else
                j++;
        }
        k++;
        j=k+1;
    }
    if(sequ==0) {printf("There aren't repeated digits\n");}
    while(pri<sequ)
    {
        printf("The repeated digit is: %d\n", rep[pri]);
        pri++;
    }
    return 0;
}