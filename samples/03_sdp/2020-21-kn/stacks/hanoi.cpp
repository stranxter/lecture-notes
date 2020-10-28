#include <iostream>
#include <stack>
#include "hanoiplayer.h"

struct GameGoal
{
    int k;
    char source, dest, temp;
};

void playHanoi (int k, char source, char dest, char temp)
{
    if (k==1)
    {
        std::cout << "Please move one disk from " << source << " to " << dest << std::endl;
        return;
    }

    playHanoi (k-1,source,temp,dest);
    playHanoi (1,source,dest,temp);
    playHanoi (k-1,temp,dest,source);
}

void hanoiIter (int k, char source, char dest, char temp)
{
    std::stack<GameGoal> s;

    s.push({k,source,dest,temp});

    while (!s.empty())
    {
       GameGoal current = s.top(); s.pop();
       if (current.k == 1)
       {
           std::cout << "Please move one disk from " << current.source << " to " << current.dest << std::endl;
       } else 
       {
           s.push({current.k-1,current.temp,current.dest,current.source});
           s.push({1,current.source,current.dest,current.temp});
           s.push({current.k-1,current.source,current.temp,current.dest});
       }
    }

    //
}


int main ()
{
    playHanoi(3,'A','C','B');
    std::cout << "=====================\n";
    hanoiIter(3,'A','C','B');

    std::cout << "=====================\n";
    HanoiPlayer player(3);

    while (player.moreMoves())
    {
        typename HanoiPlayer::gameMove move = player.nextMove();
        std::cout << "Please move one ddisk from " << move.from << " to " << move.to << std::endl;
    }


}