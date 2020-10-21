#include <iostream>
#include <stack>

const int labSize = 8;
int lab[labSize][labSize] = {0, 1, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 1, 0, 0, 0,
                             1, 1, 0, 0, 1, 0, 0, 0,
                             0, 0, 0, 0, 1, 0, 0, 0,
                             1, 0, 1, 0, 1, 0, 0, 0,
                             0, 0, 1, 0, 1, 0, 0, 0,
                             0, 0, 1, 0, 1, 0, 0, 0,
                             0, 0, 1, 0, 1, 0, 0, 0};


struct position
{
    int x,y;
    position down()
    {return position{x,y+1};}
    position right()
    {return position{x+1,y};}
    position up()
    {return position{x,y-1};}
    position left()
    {return position{x-1,y};}
    bool operator== (const position& pos)
    { return x == pos.x && y == pos.y; }
    bool operator!= (const position& pos)
    { return x != pos.x || y != pos.y; }
};

bool viable (position pos)
{
    return pos.x >= 0 &&
           pos.y >= 0 &&
           pos.x < labSize &&
           pos.y < labSize &&
           lab[pos.y][pos.x] == 0;
}

bool way (position current, position goal)
{
    if (!viable(current))
    { return false; }
    if (current == goal)
    { return true; }
    //============================  
    lab[current.y][current.x] = 9;
    //============================
    bool found = false;
    found = way (current.down(),goal);
    if (!found)
    { found = way (current.right(),goal); }
    if (!found)
    { found = way (current.up(),goal); }
    if (!found)
    { found = way (current.left(),goal); }
    //============================
    lab[current.y][current.x] = 0;
    //============================
    return found;
}

bool wayiter (position start, position goal)
{
    std::stack<position> s;

    s.push(start);

    while (!s.empty() && s.top() != goal)
    {
        position current = s.top(); s.pop();
        if (viable(current))
        {
            lab[current.y][current.x] = 9;
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
    std::cout << wayiter(position{0,0},position{7,7}) << std::endl;

}
