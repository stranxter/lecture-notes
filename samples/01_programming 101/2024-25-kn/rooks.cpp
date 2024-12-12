#include <iostream>

const unsigned boardSize = 5;

bool board[boardSize][boardSize] = {false};

unsigned count = 0;

void printBoard()
{
    std::cout << "[" << count << "]--------------------------------\n";
    for(int row = 0; row < boardSize; ++row)
    {
        for(int col = 0; col < boardSize; ++col)        
        {
            if(board[row][col])
            {
                std::cout << "[X]";
            } else 
            {
                std::cout << "[ ]";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------\n";
}

bool canPlaceRook(unsigned row, unsigned col)
{
    for(unsigned i = 0; i < boardSize; ++i)
    {
        if(board[row][i] || board[i][col])
        {
            return false;
        }
    }
    return true;
}


void placeRooks(unsigned n)
{
    if(n==0)
    {
        ++count;
        printBoard();
        return;
    }

    for(int row = 0; row < boardSize; ++row)
    {
        for(int col = 0; col < boardSize; ++col)        
        {
            if(canPlaceRook(row,col))
            {
                board[row][col] = true;
                placeRooks(n-1);
                board[row][col] = false;
            }
        }
    }
}

int main()
{
    placeRooks(boardSize);
}