#include <iostream>
#include <stack>
#include <cassert>

const int labsize = 8;

int lab [labsize][labsize] = {0, 0, 1, 0, 0, 0, 0, 0,
                              0, 0, 1, 0, 0, 0, 0, 0,
                              0, 1, 1, 0, 1, 0, 0, 0,
                              0, 1, 0, 0, 1, 0, 0, 0,
                              0, 1, 1, 1, 1, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 1, 1, 1, 0, 0, 0, 0,
                              0, 0, 0, 1, 0, 0, 0, 0};

struct Position
{
    int x,y;

};

bool correct (int cx, int cy)
{
    return cx >= 0 &&
           cy >= 0 &&
           cx < labsize &&
           cy < labsize &&
           lab[cy][cx] == 0;
}

bool correct (Position p)
{
    return correct (p.x,p.y);
}

bool visited (Position p)
{
    return p.x >= 0 &&
           p.x >= 0 &&
           p.x < labsize &&
           p.y < labsize &&
           lab[cy][cx] == 2;
}

bool hasway (int cx, int cy, int tx, int ty)
{
    if (cx == tx && cy == ty)
    {
        return true;
    }
    if (!correct (cx,cy))
    {
        return false;
    }

    lab[cy][cx] = 2;

    return hasway (cx,cy+1,tx,ty) ||
           hasway (cx+1,cy, tx, ty) ||
           hasway (cx-1,cy,tx,ty) ||
           hasway (cx,cy-1,tx,ty);

}


class Mario
{   
    public:
        Mario (int x, int y, int _tx, int _ty):tx(_tx),ty(_ty)
        {
            s.push (Position({x,y}));
        }

        bool foundTreasure()
        {
            return s.size () > 0 && 
                   s.top().x == tx && 
                   s.top().y == ty;
        }

        bool canMakeMoreSteps()
        {
            return s.size () > 0;
        }

        Position getCurrentPosition ()
        {
            return s.top();
        }

        void makeStep ()
        {

            assert (s.size() > 0);

            Position crr = s.top(); 
            if (correct (crr.x,crr.y))
            {
                lab[crr.y][crr.x] = 2;
                s.push (Position ({crr.x,crr.y-1}));
                s.push (Position ({crr.x-1,crr.y}));
                s.push (Position ({crr.x+1,crr.y}));
                s.push (Position ({crr.x,crr.y+1}));
            }

            while (s.size() > 0 && !correct(s.top()))
            {
                s.pop();
            }

        }

    private:
        std::stack<Position> s;
        int tx, ty;

};

bool haswayit (int cx, int cy, int tx, int ty)
{
    std::stack<Position> s;
    s.push (Position ({cx,cy}));

    while (s.size() != 0 && 
           !(s.top().x == tx && s.top().y == ty))
    {
        Position crr = s.top(); s.pop();
        if (correct (crr.x,crr.y))
        {
            lab[crr.y][crr.x] = 2;
            s.push (Position ({crr.x,crr.y-1}));
            s.push (Position ({crr.x-1,crr.y}));
            s.push (Position ({crr.x+1,crr.y}));
            s.push (Position ({crr.x,crr.y+1}));
        }
    }
    return s.size() > 0;
}

int main ()
{
   // std::cout << hasway (0,0,labsize-1,labsize-1) << std::endl;
    //std::cout << haswayit (0,0,7,7) << std::endl;

    Mario m (0,0,7,7);

    while (m.canMakeMoreSteps() && !m.foundTreasure())
    {
        m.makeStep();
        Position p = m.getCurrentPosition();
        std::cout << "(" << p.x << "," << p.y << ")";
    }
    std::cout << std::endl;
}