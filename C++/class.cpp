
#include <iostream>
#include"Sales_item.h"
int main()
{
    Sales_item item_1;
    if (std::cin >> item_1)
    {
        Sales_item actual;
        while (std::cin >> actual)
        {
            if (item_1.isbn() == actual.isbn())
                item_1+=actual;
            else // keep the {} if you have more than 1 line of code otherwise the second will be out of the statement
            {
                std::cout << item_1 << std::endl;
                item_1=actual;
            }
                
        }
    } else
    {
        std::cerr << "no data?" << std::endl;
        return -1;    
    }
    return 0;
}