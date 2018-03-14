#include <iostream>
#include <cstring>




int main ()
{
  const char *s1 = "He\0llo ";
  const char *s2 = "World!";

  //char s3[100];
  char *s3 = new char [strlen(s1) + strlen(s2) + 1];

  strcpy (s3,s1);
  strcat (s3,s2);

  std::cout << "r=" << s3 << std::endl;

  strcpy (s3,"Dog!");

  std::cout << "r=" << s3 << std::endl;

  std::cout << "<:" << ("World" < "Dog") << std::endl;
  std::cout << "<:" << (long)"World" << " " << (long)"Dog" << std::endl;
  std::cout << "<:" << ("World" == "World") << std::endl;

  std::cout << "addr=" << (long)"World!" << std::endl;
  std::cout << "addr=" << (long)"World!" << std::endl;
  std::cout << "addr=" << (long)"World!" << std::endl;

  delete []s3;

  s3 = s1 + s2;

}
