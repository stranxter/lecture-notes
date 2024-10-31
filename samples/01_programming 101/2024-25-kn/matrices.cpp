#include <iostream>
#include <iomanip>


void print(int m[4][4])
{
    for(int r = 0; r < 4; ++r)
    {
        //================================= ИЗВЕЖДАМЕ ЕДИН РЕД
        for(int c = 0; c < 4; ++c)
        {
            std::cout << std::setw(5) << m[r][c] << " ";
        }
        //=================================
        std::cout << std::endl;
    }
}

void printzigzag(int m[4][4])
{
    for(int r = 0; r < 4; ++r)
    {
        for(int c = 0; c < 4; c++)
        {
            if(r % 2 == 0)
            {
                std::cout << m[r][c] << " ";
            } else
            {
                std::cout << m[r][3-c] << " ";    
            }
                     
        }
        std::cout << std::endl;
        
    }

}


void printcols(int m[4][4])
{
    for(int c = 0; c < 4; ++c)
    {
        //================================= ИЗВЕЖДАМЕ ЕДНА КОЛОНА
        for(int r = 0; r < 4; ++r)
        {
            std::cout << std::setw(5) << m[r][c] << " ";
        }
        //=================================
        std::cout << std::endl;
    }
}



int main()
{
    int m[4][4] = {0};


    //i = 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
    //r = 0 0 0 0 1 1 1 1 2 2 2  2  3  3  3  3  
    //c = 0 1 2 3 0 1 2 3 0 1 2  3  0  1  2  3 

    for(int i = 0; i < 16; ++i)
    {
        std::cin >> m[i/4][i%4];
    }

    printzigzag(m);
    printcols(m);


}