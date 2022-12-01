#include "bot.cpp"


int main()
{
    BinOrdTree<int> t;

    t.add(50);
    t.add(30);
    t.add(20);
    t.add(45);
    t.add(90);
    t.add(99);
    t.add(70);

    std::cout << t.checkOrder() << std::endl;

}