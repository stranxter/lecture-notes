#ifndef __HANOYP__H
#define __HANOYP__H

#include <stack>


class HanoiPlayer
{
    public:

    struct HanoiMove
    {
        char from, to;
    };

    HanoiPlayer (int k);
    HanoiMove getNextMove();
    bool hasMoreMoves();

    private:
    struct GameGoal
    {
        int k;
        char source, dest, temp;
    };
    std::stack<GameGoal> s;
    

};


#endif