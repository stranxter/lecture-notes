#include <iostream>
#include <iomanip>

const int labSize = 10;

int lab[labSize][labSize] = {0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                             1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                             0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool canstep(int x, int y)
{
    return x >= 0 &&
           x < labSize &&
           y >= 0 &&
           y < labSize &&
           lab[y][x] == 0;
}

int count = 0;

//start{x,y}, goal{x,y}
bool way(int sx, int sy, int gx, int gy, int lenght)
{

    if(sx == gx && sy == gy)
    {
        std::cout << "Path length = " <<lenght << std::endl;
        return true;
    }

    if(!canstep(sx,sy))
    /*
        1. Излезли сме от границите на лабиринта
        2. Търсим път от непроходима позиция
    */
    {
        return false;
    }

    ++count;
    lab[sy][sx] = 2;


    if(way(sx+1,sy,gx,gy,lenght+1) ||
       way(sx,sy+1,gx,gy,lenght+1) ||
       way(sx-1,sy,gx,gy,lenght+1) ||
       way(sx,sy-1,gx,gy,lenght+1))
    {
        std::cout << "(" << sx << "," << sy << ")";
        lab[sy][sx] = 0;            
        return true;
    }

    lab[sy][sx] = 0;            
    return false;

}

void printLab()
{
    std::cout << "------------------------\n";
    for(int y = 0; y < labSize; ++y)
    {
        for(int x = 0; x < labSize; ++x)
        {
            std::cout << std::setw(3) << lab[y][x];
        }
        std::cout << std::endl;
    }
}

int main()
{
    printLab();
    std::cout << "w=" << way(0,0,9,9,0) << std::endl;
    printLab();
}