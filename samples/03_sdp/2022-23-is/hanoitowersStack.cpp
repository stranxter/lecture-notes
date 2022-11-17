#include <stack>
#include <iostream>

struct Game
{
    std::stack<int> poles[3];
};

template <typename T>
void printStack(std::stack<T> s)
{
    if (s.empty())
        return;
    int top = s.top(); s.pop();
    printStack(s);
    std::cout << "-" << top;
}
class HanoiGame
{
    public:

    HanoiGame(int k)
    {
        while (k > 0)
        {
            state.poles[0].push(k);
            --k;
        }
    }

    bool moreMoves()
    {
        return !state.poles[0].empty() || !state.poles[1].empty();
    }
    
    void startGame()
    {
        tasks.push(task{'A','B','C',state.poles[0].size()});
    }

    void makeMove()
    {
        task t = tasks.top(); tasks.pop();

        while(t.k > 1)
        {

            tasks.push(task{t.aux,t.source,t.destination,t.k-1});
            tasks.push(task{t.source,t.aux,t.destination,1});
            tasks.push(task{t.source,t.destination,t.aux,t.k-1});
    
            t = tasks.top(); tasks.pop();
        }

         performMove(t.source,t.destination);

    };

    void printBoard()
    {
        /* {5,4,3,1}
        {2}
        {}
        */   
        for (std::stack<int> pole : state.poles)
        {
            std::cout << "|";
            printStack(pole);
            std::cout << std::endl;
        }
    }


    private:
    Game state;
    struct task {
        char source; 
        char aux;
        char destination;
        unsigned long k;};

    std::stack<task> tasks;

    void performMove(char source, char destination)
    {
        int sourceIndex = source - 'A';
        int destinationIndex = destination - 'A';
        state.poles[destinationIndex].push(state.poles[sourceIndex].top());
        state.poles[sourceIndex].pop();
    }
};


int main()
{
    HanoiGame game(4);

    game.startGame();
    
    game.printBoard();
    std::cin.get();

    while (game.moreMoves())
    {
        game.makeMove();
        
        game.printBoard();
        std::cin.get();
    }

    game.printBoard();

}