#include <iostream>
#include <cassert>
#include <vector>

#include "constfn.h"
#include "linearfn.h"
#include "cut.h"
#include "if.h"

void testBasicFunction ()
{
    Const f1(2), f2(5);

    assert (f1.value(0)==2);
    assert (f1.value(-1) == 2);
    assert (f1.value(1) == 2);

    assert (f2.value(0) == 5);
    assert (f2.value(-1) == 5);
    assert (f2.value(1) == 5);

    Linear l1 (-1,-1), l2 (0,1), l3 (1,2);

    assert (l1.value(1) == -2);
    assert (l1.value(-1) == 0);

}

void testPoly()
{
    std::vector<Function*> functions;

    Linear l1(-1, -1), l3(1, 2);
    Const f1(6);

    functions.push_back(&l1);
    functions.push_back(&l3);
    functions.push_back(&f1);

    for (Function *f : functions)
    {
        std::cout << "f(3)=" << f->value(3) << std::endl;
    }
}

void testCut ()
{
    Linear *l1 = new Linear (1, 0),
           *l2 = new Linear (-1,0);

    Cut cut_l1 (l1),
        cut_l2 (l2);

    delete l1;
    delete l2;

    Cut cut_cut (&cut_l2);

    assert (cut_l1.value (1) == 1);
    assert (cut_l1.value (-1) == 0);
    assert (cut_l1.value (0) == 0);

    assert(cut_l2.value(1) == 0);
    assert(cut_l2.value(-1) == 1);
    assert(cut_l2.value(0) == 0);

    assert(cut_cut.value(1) == 0);
    assert(cut_cut.value(-1) == 1);
    assert(cut_cut.value(0) == 0);
}

void testIf ()
{

    If *prog = new If (new Cut (new Linear (1,0)),
                       new Const (-3),
                       new Const (5));

    assert (prog->value (1) == -3);
    assert (prog->value (2) == -3);
    assert (prog->value (-1) == 5);
    assert (prog->value (-2) == 5);
}

int main()
{

    testBasicFunction();
    testPoly();
    testCut();
    testIf();
    std::cout << "All tests passed!\n";


}