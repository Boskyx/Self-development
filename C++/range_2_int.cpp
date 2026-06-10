/* Using std::endl it forces the flush of the buffer so the is not efficient, is better
to use the \n inside the string so is the system that choose when flush the buffer
*/

#include <iostream> //inside <> there is the header
int main()
{
    std::cout << "Enter 2 values and the range will go from the first to the second" << "\n";
    int n_1=0, n_2=0;
    std::cin>>n_1>>n_2;
    std::cout << "\n";
    if (n_1<n_2) 
    {
        while(n_1<=n_2)
        {
            std::cout << "sequence: " << n_1 << "\n";
            ++n_1;
        }
    }
    else
    {
        std::cout << "the second number is lower than the first so the count will be reversed\n" << std::endl;
        while(n_1>=n_2)
        {
            std::cout << "sequence: " << n_1 << "\n";
            --n_1;
        }
    }


    return 0;
}