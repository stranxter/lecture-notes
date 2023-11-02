#include <iostream>
#include <stack>


struct HanoiProblem
{
    unsigned int k;
    char S,D,T;
};

class HanoiPlayer
{
    public:

    HanoiPlayer(unsigned int k, char S, char D, char T)
    {   
        problems.push({k,S,D,T});
    }

    bool done()
    {
        return problems.empty();
    }

    void makeMove()
    {
        HanoiProblem problem;
        while(problems.top().k > 1)
        {
            problem = problems.top(); problems.pop();
            problems.push({problem.k-1,problem.T,problem.D,problem.S});
            problems.push({1,problem.S,problem.D,problem.T});
            problems.push({problem.k-1,problem.S,problem.T,problem.D});
        }

        problem = problems.top(); problems.pop();
        std::cout << problem.S << "->" << problem.D << std::endl;

    }

    private:
    std::stack<HanoiProblem> problems;
};

void move(unsigned int k, char S, char D, char T)
{
    if(k == 1)
    {
        std::cout << S << "->" << D << "\n";
        return;
    }

    move(k-1,S,T,D);
    move(1,S,D,T);
    move(k-1,T,D,S);

}


int main()
{

    std::cout << "======REC=====\n";
    move(3,'A','C','B');

    std::cout << "======STACK=====\n";

    HanoiPlayer player(3,'A','C','B');
    while (!player.done())
    {
        player.makeMove();
    }
}