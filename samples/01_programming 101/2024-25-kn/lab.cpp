#include <iostream>

const int worldSize = 8;

int world [worldSize][worldSize] = {0, 1, 0, 0, 0, 0, 0, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1,
                                    0, 1, 0, 0, 0, 0, 0, 0,
                                    0, 1, 0, 0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0, 0, 0, 0,
                                    1, 0, 1, 0, 0, 0, 0, 0,
                                    0, 0, 1, 0, 0, 0, 0, 0,
                                    0, 0, 1, 0, 1, 0, 0, 0};

bool trap(int x, int y)
{
    return x < 0 ||
           y < 0 ||
           x >= worldSize ||
           y >= worldSize ||
           world[y][x] != 0;
}

bool hasway(int startx, int starty, int goalx, int goaly)
{

    if(trap(startx,starty))
    {
        return false;
    }

    if(startx == goalx && starty == goaly)
    {
        return true;
    }

    std::cout << "(" << startx << "," << starty << ")";
    world[starty][startx] = 10;

    return hasway(startx,starty+1,goalx,goaly) ||
           hasway(startx+1,starty,goalx,goaly) ||
           hasway(startx,starty-1,goalx,goaly) ||
           hasway(startx-1,starty,goalx,goaly);
           
}


int lengthway(int startx, int starty, int goalx, int goaly)
{
    if(trap(startx,starty))
    {
        return -1;
    }
    if(startx == goalx && starty == goaly)
    {
        return 0;
    }

    world[starty][startx] = 10;
    
    int l = lengthway(startx,starty+1,goalx,goaly);
    if (l == -1) l = lengthway(startx+1,starty,goalx,goaly);
    if (l == -1) l = lengthway(startx,starty-1,goalx,goaly);
    if (l == -1) l = lengthway(startx-1,starty,goalx,goaly);
    
    world[starty][startx] = 0;

    if (l >= 0)
    {        
        std::cout << "(" << startx << "," << starty << ")";
        return l+1;
    }

    return -1;
          
}

int main()
{
    std::cout << lengthway(0,0,7,7) << std::endl;
    std::cout << lengthway(0,0,7,7) << std::endl;
}