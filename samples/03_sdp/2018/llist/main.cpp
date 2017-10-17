#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

#include "llist.cpp"
#include "arrayiterator.cpp"

void testInsertWithFile ()
{
  std::string fname;

  std::cout << "Enter file name:";
  std::cin >> fname;

  std::cerr << "Opening:" << fname << std::endl;
  std::ifstream inf (fname);

  assert ((bool)inf != false);

  std::string word;
  LList<std::string> allwords;

  //inserting
  while (inf >> word)
  {
    std::cerr << "Inserting: " << word << std::endl;
    allwords.pushBack (word);
  }

  inf.close ();
  inf.open (fname);
  //comparing
  int index = 0;
  std::string listWord;

  ListIterator<std::string> it = allwords.begin();

  while (inf >> word)
  {
    listWord = it.getNext();
    std::cerr << "Comparing: "
              << word
              << " vs. "
              << listWord
              << std::endl;
    assert (word == listWord);
    index++;
  }

  std::cerr << "Compared " << index << " words." << std::endl;
}

void testBasic ()
{
  LList<int> list;
  list.push (1);
  list.push(0);
  list.pushBack (3);
  list.addAt (2,2);

  LList<int> copiedList (list);

  assert (list[0] == 0);
  assert (list[1] == 1);
  assert (list[2] == 2);
  assert (list[3] == 3);

  assert (copiedList[0] == 0);
  assert (copiedList[1] == 1);
  assert (copiedList[2] == 2);
  assert (copiedList[3] == 3);

  assert (list.remove(4) == false);
  list.remove(2);
  assert (list[0] == 0);
  assert (list[1] == 1);
  assert (list[2] == 3);

  list.remove(0);
  assert (list[0] == 1);
  assert (list[1] == 3);

  list.pop();
  list.pop();
  assert (list.empty() == true);
  assert (list.pop() == false);

  assert (copiedList[0] == 0);
  assert (copiedList[1] == 1);
  assert (copiedList[2] == 2);
  assert (copiedList[3] == 3);
}

void testIterator ()
{
  LList<int> list;
  list.push (2);
  list.push (1);
  list.push(0);

  ListIterator<int> it = list.begin();

  int last = it.getNext(), next;
  assert (last == 0);

  while (it.more())
  {
    next = it.getNext();
    assert (last+1 == next);
    last = next;
  }
}

template <class E>
E sumAll (BaseIterator<E>& i)
{
  E sum = 0;
  while (i.more())
  {
    sum += i.getNext();
  }
  return sum;
}


template <class E>
void map (BaseIterator<E>& i, E (*f) (const E&))
{
  while (i.more())
  {
    E &current = i.getNext();
    current = f (current);
  }
}


void testModification ()
{
  LList<int> list;
  list.push (1);
  list.push(0);

  ListIterator<int> it1 = list.begin();
  it1.getNext() += 10;

  int &ref = it1.getNext();
  ref += 10;

  assert (list[0] == 10);
  assert (list[1] == 11);
}

int plus10 (const int& i)
{
  return i+10;
}

void testMap ()
{
  LList<int> list;
  list.push (1);
  list.push(0);

  ListIterator<int> it = list.begin();

  map (it,plus10);

  assert (list[0] == 10);
  assert (list[1] == 11);

}

void testSum ()
{
  LList<int> list;
  list.push (2);
  list.push (1);
  list.push(0);

  int arr[] = {1,2,3,4};

  ListIterator<int> it = list.begin();
  ArrayIterator<int> ai(arr,4);

  assert (sumAll<int>(it) == 3);
  assert (sumAll<int>(ai) == 10);
}



int main ()
{
  testBasic();
  testIterator();
  testSum ();
  testModification();
  testMap();
  //testInsertWithFile ();
  return 0;
}
