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

    void move(char source,
              char aux,
              char destination, int k)
    {
        if (k == 0)
            return;

        move(source,destination,aux,k-1);
        std::cout << "Please move 1 disk from " << source << " to " << destination << std::endl;
        //state -> state'
        performMove(source,destination);
        printBoard();
        std::cin.get();
        move(aux,source,destination,k-1);
    }

    void play()
    {
        printBoard();
        std::cin.get();
        move('A','B','C',state.poles[0].size());
    }

    private:
    Game state;

    void performMove(char source, char destination)
    {
        int sourceIndex = source - 'A';
        int destinationIndex = destination - 'A';
        state.poles[destinationIndex].push(state.poles[sourceIndex].top());
        state.poles[sourceIndex].pop();
    }
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
};


int main()
{
    HanoiGame game(16);

    game.play();
}