#include "pstack.cpp"
#include <iostream>

void printstack (pstack<int> s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s = s.pop();
    }
    std::cout << std::endl;
}

int main ()
{
    pstack<int> s = pstack<int>().push(3).push(2).push(1);

    printstack(s);
    printstack(s.push(4).push(6));
    printstack(s.push(7));
}