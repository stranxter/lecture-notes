#include <cassert>
#include "hanoiplayer.h"

HanoiPlayer::HanoiPlayer (int k)
{
    s.push({k,'A','C','B'});   
}

HanoiPlayer::HanoiMove HanoiPlayer::getNextMove()
{
    assert(!s.empty());

    HanoiPlayer::GameGoal current = s.top();s.pop();

    if (current.k > 1)
    {   
        do
        {
            s.push({current.k-1,current.temp, current.dest,current.source});
            s.push({1,current.source, current.dest, current.temp});
            s.push({current.k-1,current.source, current.temp, current.dest}); 

            current = s.top();s.pop();       
        } while (current.k != 1);
    }

    return {current.source,current.dest}; 

}

bool HanoiPlayer::hasMoreMoves()
{
    return !s.empty();
};
