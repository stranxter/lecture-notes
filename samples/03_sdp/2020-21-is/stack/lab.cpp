#include <iostream>
#include <stack>

const int labSize = 8;
int lab[labSize][labSize] = {0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 0, 0, 1, 0, 0,
                             0, 1, 0, 0, 0, 1, 0, 0,
                             0, 1, 1, 1, 0, 1, 0, 0,
                             0, 0, 0, 0, 0, 1, 0, 0,
                             1, 1, 1, 1, 1, 1, 0, 0,
                             0, 0, 1, 0, 0, 0, 0, 0,
                             0, 0, 1, 0, 0, 0, 0, 0};

struct position
{
    int x,y;
    bool operator ==(const position &p)
    {
        return x == p.x && y == p.y;
    }
    bool operator !=(const position &p)
    {
        return x != p.x || y != p.y;
    }
    position down()
    {
        return position{x,y+1};
    }
    position up()
    {
        return position{x,y-1};
    }
    position left()
    {
        return position{x-1,y};
    }
    position right()
    {
        return position{x+1,y};
    }

};

bool viablePosition (position pos)
{
    return pos.x >= 0 &&
           pos.y >= 0 &&
           pos.x < labSize &&
           pos.y < labSize &&
           lab[pos.x][pos.y] == 0;

}

/*
    way ({0,0},{7,7})
*/

bool way (position current, position goal)
{
    if (current==goal)
    { return true; }
    if (!viablePosition(current))
    { return false; }
    
    //===============================
    lab[current.x][current.y] = 9;
    //===============================
    
    bool found = way (current.down(),goal) ||
                 way (current.right(),goal) ||
                 way (current.up(),goal) ||
                 way (current.left(),goal);

    //===============================
    lab[current.x][current.y] = 0;
    //===============================

    return found;
}

bool wayiter(position start, position goal)
{
    std::stack<position> s;

    s.push(start);

    while (!s.empty() && s.top() != goal)
    {
        position current = s.top(); s.pop();

        if (viablePosition(current))
        {
            lab[current.x][current.y] = 9;

            s.push(current.left());
            s.push(current.up());
            s.push(current.right());
            s.push(current.down());
        }
    }

    return !s.empty();
}


int main ()
{
    std::cout << way ({0,0},{7,7}) << std::endl;
    std::cout << wayiter ({0,0},{7,7}) << std::endl;
}