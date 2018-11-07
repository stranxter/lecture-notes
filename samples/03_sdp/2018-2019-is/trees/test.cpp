#include "btree.h"
#include "btree.cpp"
#include <fstream>


int main ()
{
    BTree<int> t;
    t.insert (10,"");
    t.insert (20,"L");
    t.insert (8,"R");
    t.insert (17,"LL");
    t.insert (19,"RL");

    assert (t.sum () == 74);
    assert (t.countLeaves () == 2);
    BTree<int> t2 (t);

    assert (t == t2);
    assert (t.member(10));
    assert (!t.member(99));

    t.insert (99,"LR");
    assert (t.member(99));

    assert (!(t == t2));

    std::ofstream out1 ("tree1.hsl");
    t.printToHs (out1);
    out1.close ();

    std::ifstream in1 ("tree1.hsl");
    t2.readFromHs (in1);

    assert (t == t2);
    assert (!t.isBOT());

    BTree<int> bot;

    bot.insertBOT (10);
    bot.insertBOT (232);
    bot.insertBOT (577);
    bot.insertBOT (232);
    bot.insertBOT (878);
    bot.insertBOT (23);
    bot.insertBOT (68);
    bot.insertBOT (1);

    std::ofstream botf ("botf.dot");
    bot.printToDotty (botf);

    assert (bot.isBOT());


    return 0;
}
