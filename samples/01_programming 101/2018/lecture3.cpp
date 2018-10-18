#include <iostream>

using namespace std;

int main ()
{

  long n;

  cout << "Please enter n=";
  cin >> n;


  long countDigits = 1,
       sumDigits = 0;

  while (n >= 10)
  {
    sumDigits += n % 10;
    countDigits++;

    n /= 10;
  }

  sumDigits += n;

  cout << "You entered "
       << countDigits
       << " digts. Their sum is "
       << sumDigits
       << endl;


  return 0;
}
