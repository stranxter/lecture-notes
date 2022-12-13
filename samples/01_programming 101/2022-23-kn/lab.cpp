#include <iostream>

const int gameSize = 8;

int game[gameSize][gameSize]= { 0,1,0,0,0,0,0,0,
                                0,1,0,0,0,0,0,0, 
                                0,1,0,0,0,0,0,0, 
                                0,0,0,0,0,0,0,0, 
                                1,0,1,1,0,1,1,1, 
                                0,0,1,0,0,0,0,0, 
                                0,0,1,0,0,0,0,0, 
                                0,0,2,0,0,0,0,0 };

bool canStepOn(int x, int y)
{
    return game[x][y] == 0 &&
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

    game[sx][sy] = 10;

    bool success =  way(sx,sy+1,gx,gy) ||
                    way(sx+1,sy,gx,gy) ||
                    way(sx,sy-1,gx,gy) ||
                    way(sx-1,sy,gx,gy);
    
    if(success)
    {
        std::cout << "(" << sx << "," << sy << ")";
    }
    
    return success;
    
}

int main()
{
    std::cout << way(0,0,7,7);
}