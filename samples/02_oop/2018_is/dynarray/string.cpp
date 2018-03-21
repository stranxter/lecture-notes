#include <iostream>


int main ()
{
  String s = "Hello";
  String s1;

  assert (s1 == "");

  s1 = s;
  assert (s == s1);

  s1 = "Good Buy";
  assert (s == "Hello");

  assert (s + s1 == "HelloGood Buy");

  s[0] = 'h';
  assert (s == "hello");

  s += "zzz";
  assert (s == "hellozzz");

  String s2 (s);

  s[0] = 'z';
  assert (s != s2);
  assert (s2=="hellozzz");

  assert (s2 < s);

  std::cout << s2;


}
