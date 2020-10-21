#include <iostream>
#include <stack>

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
}


int main ()
{
    playHanoi(3,'A','C','B');
    std::cout << std::endl;
    hanoiIter(3,'A','C','B');
}