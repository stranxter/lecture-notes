#include <iostream>
#include "string.h"
#include <cassert>


String f ()
{
  return "hello";
}

void testString ()
{
  String s1 = "Hello", s2 = "Hello 2";

  assert (s1 != s2);

  s1 = s2;

  assert (s1 == s2);

  s1 += s2;

  assert (s1.operator == ("Hello 2Hello 2"));

  assert (s1[0] == 'H');
  s1[0] = 'Y';
  assert (s1[0] == 'Y');

  assert (s1 > s2);

  assert (f()[0] == 'h');



}

void testIO ()
{
  String s;
  std::cout << "Please input a string...";
  std::cin >> s;
  std::cout << "You just entered:\""
            << s
            << "\" which has "
            << s.getLength()
            << " characters." << std::endl;
}


int main ()
{

  testString();
  testIO();

}
