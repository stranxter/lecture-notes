#include <iostream>
#include <cmath>
#include <cstring>

long sum (long arr[], size_t n)
{
  if (n == 0)
  {
    return 0;
  }
  return sum (arr,n-1) + arr[n-1];
  //return arr[0] + sum (arr+1,n-1);

/*  return sum (arr,n/2) +
         arr[n/2] +
         sum (arr+(n/2)+1,ceil(n/2.0));
*/
}

void concat3Strings (char result[],
                      const char s1[],
                      const char s2[],
                      const char s3[])
{
//char result[strlen(s1) + strlen(s2) + 1]

  strcpy (result,s1);
  strcat (result,s2);
  strcat (result,s3);

}

int main ()
{
  long a = 5, b = 6;
  long *p = &a;

  p = &b;
  *p = a;


  long arr[] = {1,2,3}; //const long *!!!!

  *arr = 3;

  p = arr;
  *p = 5;

  arr[0] = 3;
  p[0] = 3;
  p[1] = 5;

  std::cout << (long)p << std::endl;
  p = p + 1;
  std::cout << (long)p << std::endl;
  p = p + 1;
  std::cout << (long)p << std::endl;

  char s[] = "Hello world!";
  char *pchar = s;

  std::cout << "===========\n";

  std::cout << (long)pchar << std::endl;
  pchar = pchar + 1;
  std::cout << (long)pchar << std::endl;
  pchar = pchar + 1;
  std::cout << (long)pchar << std::endl;

  arr[2] = 0;
  //<=>
  *(arr+2) = 0;

  long larr[] = {1,2,3,4,5,6,7,8,9,10};

  std::cout << sum (larr,10) << std::endl;

  char s1[] = "Hello world!";
  char s2[] = "Have a nice day!";

  char concatenated[strlen(s1) + strlen(s2) + 2];


  int *px;
  {int x = 0; px=&x;}; *px = 5;

  strcpy (concatenated,s1);
  strcat (concatenated," ");
  strcat (concatenated, s2);

  std::cout << concatenated << std::endl;

  char result [255];
  concat3Strings (result, "This is ", "a class in ", "Programming.");
  std::cout << result << std::endl;

}
