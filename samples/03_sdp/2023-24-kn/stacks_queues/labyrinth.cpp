#include <iostream>
#include <stack>
#include <queue>

const unsigned int labSize = 5;

int lab[labSize][labSize] = {0, 1, 0, 0, 0,
                             0, 1, 0, 0, 0,
                             0, 0, 0, 0, 0,
                             0, 1, 1, 1, 1,
                             0, 0, 0, 0, 0};


bool correct(int sx, int sy)
{
    return sx >= 0 &&
           sy >= 0 &&
           sx < labSize &&
           sy < labSize &&
           lab[sy][sx] == 0;
}

bool way(int sx, int sy,
         int ex, int ey)
{

    if(sx == ex && sy == ey)
    {
        return true;
    }

    if(!correct(sx,sy))
    {
        return false;
    }

    lab[sy][sx] = 2;

    return way(sx,sy+1,ex,ey) ||
           way(sx+1,sy,ex,ey) ||
           way(sx,sy-1,ex,ey) ||
           way(sx-1,sy,ex,ey);

    //lab[sy][sx] = 0; ???

}

struct Position {
    int x; 
    int y; 
    bool operator==(const Position& p)
    {
        return x == p.x && y == p.y;
    }
    bool operator!=(const Position& p)
    {
        return !(*this == p);
    }    
    Position left(){return {x-1,y};}
    Position right(){return {x+1,y};}
    Position up(){return {x,y-1};}
    Position down(){return {x,y+1};}
};

bool correct(Position p)
{
    return correct(p.x,p.y);
}

std::ostream& operator << (std::ostream& out, const Position &p)
{
    out << "(" 
        << p.x 
        << ","
        << p.y
        << ")";

    return out;
}

class PathFinder
{
    public:

    PathFinder(int sx, int sy, int ex, int ey):goal({ex,ey})
    {
        trace.push({sx,sy});
    }

    bool done()
    {
        return trace.empty() || found();  
    }

    bool found()
    {
        return !trace.empty() && trace.top() == goal;
    }


    void walk()
    {
        Position current = trace.top(); trace.pop();
        
        lab[current.y][current.x] = 2;
    
        trace.push({current.x-1,current.y});
        trace.push({current.x,current.y-1});
        trace.push({current.x+1,current.y});
        trace.push({current.x,current.y+1});

        while(!trace.empty() && 
              !correct(current = trace.top()))
        {
            trace.pop();    
        }

    }

    Position location()
    {
        return trace.top();
    }

    private:
    std::stack<Position> trace;
    Position goal;
};

const Position sentinel = {-5,-5};

int waybfs (Position start,
            Position goal)
{
    std::queue<Position> q;

    Position current = start;
    q.push(current);
    //std::cout << current;
    q.push(sentinel);
    
    int countLevel = 0;

    while(!q.empty() && current != goal)
    {
        q.pop();

        if(correct(current))
        {
            lab[current.y][current.x] = 2;
            q.push(current.down());
            q.push(current.right());
            q.push(current.up());
            q.push(current.left());
        }

        if(current == sentinel && q.size() > 1)
        {
            q.push(sentinel);
            ++countLevel;
        }

        if(!q.empty())
        {
            current = q.front();     
            //std::cout << current;
        }

    }

    return (current == goal?countLevel:-1);
}



int main()
{
   // std::cout << way(0,0,4,4);

/*
    PathFinder finder(0,0,4,4);

    while(!finder.done())
    {
        std::cout << finder.location();
        std::cin.get();
        finder.walk();
    }
*/
    std::cout << "path found=" << waybfs({0,0},{4,0}) << std::endl;

}