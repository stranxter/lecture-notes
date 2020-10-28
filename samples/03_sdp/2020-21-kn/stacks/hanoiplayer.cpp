#include "hanoiplayer.h"
#include <cassert>


HanoiPlayer::HanoiPlayer(int n)
{
    s.push({n,'A','C','B'});
}

HanoiPlayer::gameMove HanoiPlayer::nextMove()
{
    assert(!s.empty());

    HanoiPlayer::GameGoal nextGoal = s.top(); s.pop();

    while (nextGoal.k != 1) 
    {
        s.push({nextGoal.k-1,nextGoal.temp,nextGoal.dest,nextGoal.source});
        s.push({1,nextGoal.source,nextGoal.dest,nextGoal.temp});
        s.push({nextGoal.k-1,nextGoal.source,nextGoal.temp,nextGoal.dest});

        nextGoal = s.top(); s.pop();        
    } 

    return {nextGoal.source,nextGoal.dest};
}
    
bool HanoiPlayer::moreMoves()
{
    return !s.empty();    
}
