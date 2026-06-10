//cin stands for see in for the input with >> (input operator)
//cout stand for see out for the output <<
//endl is a special operator called manupulator, effect fo ending the current line and flushing the buffer
//:: is the scope operator to say that we want to use the name cout as defined in namespace std

/* other type of comment*/

#include <iostream> //inside <> there is the header
int main()
{
    std::cout << "Enter 2 values" << std::endl;
    float v1=0, v2=0;
    std::cin >>v1>>v2; //>> takes istream as its left-hand operand and an object in the right hand
    std::cout << "the sum of " <<v1<<" end " << v2 << " is " << v1+v2 <<std::endl;
    std::cout << "the product of " <<v1<<" end " << v2 << " is " << v1*v2 <<std::endl;

    std::cout << "the sum of " << v1
              << " and " << v2
              << " is " << v1+v2 << std::endl;

    std::cout << "\n";   
    std::cout << ">>>>Part 2 with while<<<<\n" <<"\n";
    
    /* PART II WHILE*/
    /*sum all the numbers from 1 to 10 included  = 55*/
    int sum=0, val=50;
    while (val<=100)
    {
        sum +=val;
        ++val;
    }

    std::cout << "Sum of 1 to 10 is " << sum << std::endl;

    int value=10;
    while (value >=0 )
    {
        std::cout << "actual number is " << value << "\n" << std::endl;
        --value;
    }


    return 0;
}