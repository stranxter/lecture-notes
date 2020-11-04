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
    pstack<int> s = pstack<int>().push(1).push(2).push(3);

    printstack(s);
    printstack(s.push(4).push(5).push(6));
    printstack(s.push(7).push(8));
}