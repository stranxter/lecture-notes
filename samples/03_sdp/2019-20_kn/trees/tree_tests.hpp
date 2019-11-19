TEST_CASE("Create Empty Tree")
{
    BinTree<int> empty;
}

#include <fstream>

TEST_CASE("Create Non-Empty Tree")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    /**************************************
    **    КОМАНДЕН РЕД ЗА GRAPHVIZ       **
    **                                   **
    ** >dot tree.dot -Tpdf -o tree.pdf   **
    **                                   **
    **************************************/
   
    std::ofstream file ("tree.dot");
    test.dottyPrint(file);
}

TEST_CASE("Member Test")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    CHECK (test.member(7)==true);
    CHECK (test.member(30)==true);
    CHECK (test.member(12)==true);
    CHECK (test.member(90)==true);
    CHECK (test.member(5)==true);
    CHECK (test.member(50)==true);
    CHECK (test.member(8)==false);
    CHECK (test.member(18)==false);
    CHECK (test.member(51)==false);
    CHECK (test.member(9)==false);
    CHECK (test.member(0)==false);
    CHECK (test.member(-1)==false);

}

TEST_CASE("Test Sum")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    CHECK (test.sum() == 194);

}

int plus (const int& x, const int& y)
{
    return x+y;
}

TEST_CASE("Test Reduce")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    CHECK (test.reduce(plus,0) == test.sum());

}

