#include <iostream>
#include <iomanip>

const int rows = 4;
const int cols = 3;

int main()
{

    int m[rows][cols] = {1,2,3,
                         4,5,6,
                        7,8,9,
                        10,11,12};
/*
    for(int row = 0; row < rows; ++row)
    {
        //в момента обработвам row-ти ред
        std::cout << "Въвеждаме ред: " << row << "!" << std::endl;

        for(int col = 0; col < cols; ++col)
        {
            std::cout << "Моля, въведете колона: " << col << " =";
            std::cin >> m[row][col];
        }        
    }
*/
    std::cout << "======== ВАШАТА МАТРИЦА Е:=============\n";

    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            std::cout << std::setw(5) << m[row][col] << " ";
        }        
        std::cout << std::endl;
    }


    for(int row = 0; row < rows; ++row)
    {
        int sum = 0;
        for(int col = 0; col < cols; ++col)
        {
            sum += m[row][col];
        }  
        std::cout << "Сумата е=" << sum << std::endl;      
    }

    for(int col = 0; col < cols; ++col)
    {
        int sum = 0;
        for(int row = 0; row < rows; ++row)
        {
            sum += m[row][col];
        }  
        std::cout << "Сумата е=" << sum << std::endl;      
    }


    return 0;
}