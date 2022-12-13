#include <iostream>

const int gameSize = 8;

int game[gameSize][gameSize]= { 0,1,0,0,0,0,0,0,
                                0,1,0,0,0,0,0,0, 
                                0,1,0,0,0,0,0,0, 
                                0,0,0,0,0,0,0,0, 
                                0,1,1,1,1,1,1,0, 
                                0,0,0,0,1,0,0,0, 
                                0,0,1,0,1,0,1,0, 
                                0,0,1,0,0,0,1,0 };


int foundWay[gameSize*gameSize][2] = {};
int wayLength = 0;

void addToWay(int x, int y)
{
    foundWay[wayLength][0] = x;
    foundWay[wayLength][1] = y;    
    ++wayLength;
}

void printWay()
{
    std::cout << wayLength << ":";

    for(int i = wayLength-1; i >= 0; --i)
    {
        std::cout << "("
                  << foundWay[i][0]
                  << ","
                  << foundWay[i][1]
                  << ")";
    }
}

bool canStepOn(int x, int y)
{
    return game[y][x] == 0 &&
           x >= 0 &&
           x < gameSize &&
           y >= 0 &&
           y < gameSize;
}

bool way(int sx, int sy, int gx, int gy)
{
    if(sx==gx && sy == gy)
    {
        return true;
    }

    if (!canStepOn(sx,sy))
    {
        return false;
    }

    game[sy][sx] = 10;

    bool success =  way(sx,sy+1,gx,gy) ||
                    way(sx+1,sy,gx,gy) ||
                    way(sx,sy-1,gx,gy) ||
                    way(sx-1,sy,gx,gy);

    game[sy][sx] = 0;
    
    if(success)
    {
        addToWay(sx,sy);
    }
    
    return success;
    
}



int main()
{
    way(0,0,7,7);
    printWay();

    std::cout << std::endl;

    for(int r=0; r < gameSize; ++r)
    {
        for (int c=0; c < gameSize; ++c)
        {
            std::cout << game[r][c] << " ";
        }
        std::cout << std::endl;
    }
}