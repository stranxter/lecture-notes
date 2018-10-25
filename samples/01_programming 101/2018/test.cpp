#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

double triangleSurface (double a, double b, double c)
{
  double p = (a+b+c)/2;
  double surface = sqrt (p*(p-a)*(p-b)*(p-c));

  cout << "The surface is " << surface << endl;

  return surface;
}

void printBiggerNumber (int a, int b)
{
  if (a > b)
  {
    cout << "a" << endl;
  } else {
    cout << "b" << endl;
  }

  //return 0;
}

double enterValidTriangleSide ()
{
  double side = -1;

  for (;side <= 0;)
  {
    cout << "Please, enter side=";
    cin >> side;
  }

  return side;
}

//по даден низ връща броя на символите в него
//(дължина на низ)
int mystrlen (char str[])
{

  int currentIndex = 0;

  while (str[currentIndex] != 0)
  {
    currentIndex++;
  }

  /*
  int currentIndex = 0;
  for (;str[currentIndex] !=0;)
  {
    currentIndex++;
  }*/

  return currentIndex;
}

int howManyOccurences (char str[], char symbol)
{
  int currentIndex = 0,
      symbolsCounter = 0;

  while (str[currentIndex] != 0)
  {
    if (str[currentIndex] == symbol)
    {
      symbolsCounter++;
    }
    currentIndex++;
  }

  return symbolsCounter;

}

void mystrcpy (char destination[], char source[])
{
  int count = 0;

  while (source[count] != 0)
  {
    destination[count] = source[count];
    count++;
  }

  destination[count] = source[count];
}

void mystrcat (char destination[], char source[])
{
  int count = 0;
  int prefixLength = mystrlen (destination);

  while (source[count] != 0)
  {
    destination[count+prefixLength] = source[count];
    count++;
  }

  destination[count+prefixLength] = source[count];

}

int main ()
{

/*
  double s1 = triangleSurface (enterValidTriangleSide(),
                               enterValidTriangleSide(),
                               enterValidTriangleSide());

  cout << "Howdy! Surface = " << s1 << endl;
*/
/*
  int arr[100], n;

  std::cout << "Please enter number of elements=";
  std::cin >> n;

  for (int count = 0; count < n; count++)
  {
    std::cin >> arr[count];
  }

  for (int count = 0; count < n; count++)
  {
    std::cout << "The "
              << count
              << "-th variable is "
              << arr[count]
              << std::endl;
  }
*/
/*
  char str[100] = "Hello world!";
  cout << str << endl;
  str[0] = 'Y';
  cout << str << endl;

  cout << "Please input a string:";
  cin >> str;

  for (int counter = 0; counter < 100; counter++)
  {
    if (str[counter] == 'a') {
      str[counter] = 'b'; }
  }
  cout << str << endl;

  char a[99] = "sdcsccsacasdcs";
  char b[7] = "zzz";

  b = a;
*/
/*
  char str[100] = "Hel  lo w    or  ld!";

  std::cout << "The length of the string is: "
            << mystrlen (str)
            << std::endl
            << "Number of spaces is:"
            << howManyOccurences (str,' ')
            << std::endl
            << "Number of occurance of 'o' is:"
            << howManyOccurences (str,'o')
            << std::endl;


  int i1 = 10;
  char str2[2] = "a";
  int i2 = 20;

  str2[1] = 'b';
  str2[2] = 0;

  std::cout << "The length of the string is: "
            << mystrlen (str2)
            <<std::endl
            << " "
            << i1
            << " "
            << i2
            <<std::endl;

  */

  char a1[50] = "Hello";
  char a2[30] = "Students of FMI";

  strcat  (a1,a2);
  std::cout << a1 << std::endl; //HelloStudenos of FMI


  //a2 = a1
  strcpy (a2,a1);

  std::cout << a2 << std::endl;





  return 0;
}
