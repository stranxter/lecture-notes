#include <iostream>

/*
    проверка дали масивът съдържа даден елемент
*/

template <class ElementType>
bool iselem (ElementType arr[], 
             size_t size, 
             ElementType x)
{
    for (size_t i = 0; i < size; i++)
    {
        if (x == arr[i])
        {
            return true;
        }
    }
    return false;
}

/*
    
*/

template <class ArrayType>
void printArray (ArrayType arr, 
                 size_t size)
{
    std::cout << "[";
    for (size_t i = 0; i < size-1; i++)
    {
        std::cout << arr[i] << ",";
    }
    if (size > 0)
    {
        std::cout << arr[size-1];
    }
    std::cout << "]\n";
}



int main ()
{
    int ia[] = {1,2,3,4,5,6,7,8,9,0};

    std::cout << iselem (ia,10,5) << std::endl;
    std::cout << iselem (ia,10,12) << std::endl;

    double da[] = {1.0,2,3,4.0,5,6,7,8.0,9,0};

    std::cout << iselem (da,10,5.0) << std::endl;
    std::cout << iselem<double> (da,10,12) << std::endl;

    char s[] = "Hello world!";

    std::cout << iselem<char> (s,12,97) << std::endl;

    printArray (s, 12);
    printArray (ia, 10);

    return 0;
}