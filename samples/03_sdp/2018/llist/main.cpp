#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

#include "llist.cpp"


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
  while (inf >> word)
  {
    std::cerr << "Comparing: "
              << word
              << " vs. "
              << allwords[index]
              << std::endl;
    assert (word == allwords[index]);
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


int main ()
{
  testBasic();
  testInsertWithFile ();
  return 0;
}
