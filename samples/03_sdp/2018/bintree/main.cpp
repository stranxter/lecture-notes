#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "btree.cpp"


void testSerialize ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);


  std::ofstream f ("tree.txt");

  f << t7;

  f.close ();

  BTree<int> newTree;
  std::ifstream fin ("tree.txt");

  newTree.read (fin);

  //assert (t7==newTree);

  std::cout << std::endl << newTree;
}

void testBuild ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);


  t7.insertElement ("RR",100);
  std::cout << t7;

}

void testTrace ()
{
  BTree<int> t;

  t.insertElement ("",10);
  t.insertElement ("L",20);

  std::cout << t;
}

void testBOT ()
{
  BTree<int> t;

  t.insertBOT (10);
  t.insertBOT (20);
  t.insertBOT (5);

  std::cout << t;

  assert (t.member (5));
  assert (!t.member (6));

}

void testMemory ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);

  BTree<int> *tmp = new BTree<int> (t7);

  assert (tmp->member (90));
  assert (tmp->member (7));
  assert (*tmp == t7);

  delete tmp;
  assert (t7.member (90));
  assert (t7.member (7));

  t90 = t7;
  assert (t90 == t7);
  t7 = t7;
  assert (t90 == t7);
  assert (t7 == t7);

}


void testDelete ()
{
  BTree<int> t;

  int save = -1, toInsert=-1;

  for (int i = 0; i < 50; i++)
  {

    toInsert = rand()%100;
    if (i == 25)
    {
      save = toInsert;
    }
    t.insertBOT (toInsert);
  }

  std::ofstream f1 ("before.dot");
  t.printDotty (f1);

  assert (t.member (save));

  t.deleteBOT (save);

  std::ofstream f2 ("after.dot");
  t.printDotty (f2);
  assert (!t.member (save));

  std::cout << save;
}


void testFill ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);



 std::ofstream f1 ("before.dot");
 t7.printDotty (f1);

 t7.fillGaps (0,5);

 std::ofstream f2 ("after.dot");
 t7.printDotty (f2);
}

void testPrintWithStack ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);


  t7.printWithStack(std::cout);

  std::stringstream str;
  t7.printWithStack(str);

  int x, y, z;
  str >> x >> y >> z;
  assert (x == 30);
  assert (y == 90);
  assert (z == 12);

  //или
  assert (str.str() == "30 90 12 7 50 5 ");

}

void testIterator ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);

  LRoRTreeIterator<int> it = t7.begin ();

  while (it != t7.end())
  {
    std::cout << *it << " ";
    it++;
  }
}

void testBFS ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);

  t7.levelsPrint(std::cout);
}

void testMutationIt ()
{

  BTree<int> t;

  MutIterator<int> it = t.beginMut();

  it.set (10);
  it.left().set (11);
  it.left().set (15);
  it.left().right().set(12);
  it.left().left().set(14);

  std::stringstream str;
  t.printWithStack(str);

  assert (str.str() == "14 15 12 10 ");
  std::cout << str.str() << std::endl;

  std::cout << t << std::endl;

}

int main ()
{
  srand (0);

//  testBuild ();
//  testTrace();
//  testBOT();
//  testMemory();
//  testDelete ();
//  testFill();
//  testSerialize ();
//  testPrintWithStack();
//  testIterator();

//  testBFS ();

  testMutationIt();

}
