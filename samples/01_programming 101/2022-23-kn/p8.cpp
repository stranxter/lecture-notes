#include <iostream>
#include <iomanip>

const int cols = 3;

int a[][cols] = {1,2,3,
                 4,500,6,
                 7,8,9};

/*
1 2 3
  5 6
    9
*/

//int[10]


void printDiag(int matrix[][cols], int rows)
{
    for (int r = 0; r < rows; ++r)
    {

        for (int i = 0; i < 4*r; ++i)
            std::cout << " ";
        //=========цикъл за зивеждане на ред =========
        for (int c = r; c < cols; ++c)
        {
                std::cout << std::setw(3) << matrix[r][c] << " ";
        }
        std::cout << std::endl;
        //===========================================
    }
}


int main()
{
    printDiag(a,3);


}   