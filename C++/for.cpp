/* Using std::endl it forces the flush of the buffer so the is not efficient, is better
to use the \n inside the string so is the system that choose when flush the buffer
*/

#include <iostream> //inside <> there is the header
int main()
{
    int sum=0; 
    for (int i=-100; i<=100; ++i)
        sum+=i;
    std::cout << "Sum is " << sum << "\n";

    /*READ NUMBERS FROM USER UNTIL IT FINISHED EOF*/
    int result=0, value=0;
    while (std::cin >> value)
        result+=value;
    std::cout << "Sum is " << result << std::endl;
    return 0;
}