#include <iostream>

const unsigned size = 8;

unsigned world[size][size] = {0,0,0,1,0,0,0,0,
                              0,0,0,1,0,0,0,0,
                              0,0,0,1,0,2,0,0,
                              1,0,1,1,0,0,0,0,
                              1,0,1,0,0,0,0,0,
                              0,0,1,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,
                              0,0,1,0,0,0,0,0}; 

struct Position
{
    int x;
    int y;
};

bool dead(Position p)
{
    return p.x < 0 ||
           p.x >= size ||
           p.y < 0 ||
           p.y >= size ||
           world[p.y][p.x] == 1;
      
}

const Position noGold = {-1,-1};

bool isGold(Position p)
{
    return !dead(p) && world[p.y][p.x] == 2;
}

void blockPosition(Position p)
{
    world[p.y][p.x] = 1;
}

Position findTreasure(Position start)
{

    if(isGold(start))
    {
        return start;
    }
    if(dead(start))
    {
        return noGold;
    }

    blockPosition(start);

    Position found = findTreasure({start.x,start.y+1});
    if(isGold(found)) return found;

    found = findTreasure({start.x+1,start.y});
    if(isGold(found)) return found;

    found = findTreasure({start.x,start.y-1});
    if(isGold(found)) return found;

    found = findTreasure({start.x-1,start.y});
    return found;

}

void printPosition(Position p)
{
    std::cout << "(" << p.x << "," << p.y << ")";
}

int main()
{
    printPosition(findTreasure({0,0}));
    
}