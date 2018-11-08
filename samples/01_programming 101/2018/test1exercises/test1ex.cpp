#include <iostream>


void factorialCalculation ()
{
  /*
      Да се въведе естествено число n и да се отпечата n!

      1.2.3.4.5...n
      n.(n-1).(n-2)..1

  */

  unsigned long n=0;
  std::cout << "Please enter n=";
  std::cin >> n;

  unsigned long result = 1;

  for (unsigned long counter = n; counter > 0; counter--)
  {
    result *= counter;
  }

  std::cout << "n!=" << result << std::endl;
}

void FibonacciCalculation ()
{
  /*
      Да се въведе естествено число n и да се отпечата
      n-тото число на Фибоначи

      a(0) = 0            | 0
      a(1) = 1            | 1
      a(2) = a(0) + a(1)  | 1
      a(3) = a(1) + a(2)  | 2
      a(4) = a(2) + a(3)  | 3
      .
      .
      a(n) = a(n-2) + a(n-1) | n >= 2

      0    1   1  2  3  5  8  13  21
                           ^
      ^    ^   ^
      nm2 nm1  n

  */

  unsigned long n = 0;
  std::cout << "Please enter n=";
  std::cin >> n;

  if (n < 2)
  {
    std::cout << "N-th Fibomnacci number is="
              << n
              << std::endl;
  } else {

    unsigned long fibnm2=0, fibnm1 = 1, fibn=-1;

    for (unsigned long counter = 2; counter <= n; counter++)
    {
        fibn = fibnm2+fibnm1;
        fibnm2 = fibnm1;
        fibnm1 = fibn;
    }

    std::cout << "N-th Fibomnacci number is="
              << fibn
              << std::endl;

  }
}

void checkIncreasingProgression ()
{
  /*
    При въведена редица от n цели числа от клавиатурата, да се провери
    дали редицата е растяща или не
  */

  unsigned long n = 0;
  std::cout << "Please enter N=";
  std::cin >> n;

  long currentNumber = -1, previousNumber = -1;

  std::cout << "Please enter 0-th number =";
  std::cin >> currentNumber;

  unsigned counter = 1;
  do {
    std::cout << "Please enter " << counter << "-th number =";
    previousNumber = currentNumber;
    std::cin >> currentNumber;

    counter++;
  } while (counter < n && currentNumber >= previousNumber);


  if (currentNumber >= previousNumber)
  {
      std::cout << "Yes!" << std::endl;
  } else {
      std::cout << "No!" << std::endl;
  }
}

void checkAnyProgression ()
{
  /*
    При въведена редица от n цели числа от клавиатурата, да се провери
    дали редицата е строго монотонно растяща,
    строго монотонни намаляваща, или нито едното от двете
  */

  unsigned long n = 0;
  std::cout << "Please enter N=";
  std::cin >> n;

  long currentNumber = -1, previousNumber = -1;

  std::cout << "Please enter 0-th number =";
  std::cin >> previousNumber;
  std::cout << "Please enter 1-st number =";
  std::cin >> currentNumber;

  bool expectIncrease = currentNumber > previousNumber;

  unsigned counter = 2;
  do {
    std::cout << "Please enter " << counter << "-th number =";
    previousNumber = currentNumber;
    std::cin >> currentNumber;

    counter++;
  } while (counter < n &&
          (
            ((currentNumber >= previousNumber) && expectIncrease) ||
            ((currentNumber < previousNumber) && !expectIncrease)
          ));


  if (expectIncrease && currentNumber > previousNumber)
  {
      std::cout << "Increasing!" << std::endl;
  } else if (!expectIncrease && currentNumber < previousNumber) {
      std::cout << "Decreasing" << std::endl;
  } else {
      std::cout << "Nothing!" << std::endl;
  }
}

void determineRange ()
{
  /*
    При въведена редица от n цели числа от клавиатурата:

    >>>Да се намери най-малкият затворен интервал от
       цели числа, съдържащ всички елементи на редицата

       или

    >>> Да се намерят най-малкото и най-голямото от тях

  */

  unsigned long n = 0;
  std::cout << "Please enter n =";
  std::cin >> n;

  long currentNumber = -1;

  long currentlyFoundMin = -1, currentlyFoundMax = -1;

  std::cout << "Please enter 0-th number=";
  std::cin >> currentNumber;

  currentlyFoundMax = currentlyFoundMin = currentNumber;

  for (unsigned long count = 1; count < n; count++)
  {
    std::cout << "Please enter " << count << "-th number=";
    std::cin >> currentNumber;

    if (currentNumber < currentlyFoundMin)
    {
      currentlyFoundMin = currentNumber;
    }
    if (currentNumber > currentlyFoundMax)
    {
      currentlyFoundMax = currentNumber;
    }
  }

  std::cout << "Max = " << currentlyFoundMax
            << std::endl
            << "Min = " << currentlyFoundMin
            << std::endl;

}

void checkPrime ()
{
  /*
     За въведено от клавиатурата естествено числа да се изпише на
     екрана "yes" или "no" в зависимост от това, дали числото е просто.
  */

  unsigned long n = 0;
  std::cout << "Please enter n =";
  std::cin >> n;

  //  2  3  4   5  6  7  8  | 9
  //     ^

  unsigned long count = 2;
  while (count < n-1 && n%count != 0)
  {
    count++;
  }

  if (n%count == 0)
  {
    std::cout << "Not prime!" << std::endl;
  } else {
    std::cout << "Prime!" << std::endl;
  }
}

void findPrimes ()
{
  /*
    Да се намерят и отпечатат всички числа в целочисления
    итервал [a,b], които са прости
  */

  unsigned long a = -1, b = -1;
  std::cout << "Please enter a =";
  std::cin >> a;
  std::cout << "Please enter b =";
  std::cin >> b;

  unsigned long countFoundPrimes = 0;

  for (unsigned long count = a; count <= b; count++)
  {
    //имаме да проверяваме дали count е просто
    unsigned long denominator = 2;
    while (denominator < count-1 && count%denominator !=0)
    {
      denominator++;
    }
    if (count == 2 || count%denominator!=0)
    {
      countFoundPrimes++;
      std::cout << count << std::endl;
    }
  }
  std::cout << "Number of primes = " << countFoundPrimes << std::endl;
}

int main ()
{
  //factorialCalculation ();
  //FibonacciCalculation();
  //checkIncreasingProgression ();
  //checkAnyProgression ();
  //determineRange();
  //checkPrime();
  findPrimes();
}
