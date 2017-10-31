#include <iostream>
#include <fstream>

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

int main ()
{

  testBuild ();
  testTrace();
  testBOT();
  testMemory();

  testSerialize ();

}
