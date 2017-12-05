#include <cassert>
#include <string>
#include <iostream>
#include "hashmap.cpp"

unsigned int h (const std::string &s, unsigned int n)
{
  unsigned int sum = 0;
  for (int i = 0; i < s.length(); i++)
  {
    //h("abc") == h("acb");
    sum += s[i];
  }
  return sum % n;
}

void testBasicOp ()
{
  HashMap<std::string,int> map (255,h);

  map["John Smith"] = 10;
  map["John Smith"] = 12;
  map["John Simth"] = 15;

  map["Lisa Smith"] = 20;

  assert (map["John Smith"] == 12);
  assert (map["John Simth"] == 15);
  assert (h("John Smith",255) == h("John Simth",255));

  assert (map["Lisa Smith"] == 20);

}


void testCompare ()
{
  HashMap<std::string,int> map1 (255,h);
  HashMap<std::string,int> map2 (1,h);

  map1["John Smith"] = 10;
  map1["Lisa Smith"] = 20;

  map2["John Smith"] = 10;
  map2["Lisa Smith"] = 20;

  assert (map1 == map2);

  map2["Sam Doe"] = 20;

  assert (map1 != map2);

}

int main ()
{
  testBasicOp ();
  testCompare ();
  std::cout << "Passed!\n";
  return 0;
}
