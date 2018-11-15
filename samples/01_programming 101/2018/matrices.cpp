#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

bool find (int a[], size_t size, int x)
{
  size_t c = 0;
  while (c < size && a[c] != x)
  {
    c++;
  }
  return c < size;
}

void timedFind ()
{

  const size_t arrsize = 300000;
  int repetitions = 10;

  int a[arrsize];
  for (size_t c = 0; c < arrsize; c++)
  {
    a[c] = c;
  }

  int x = arrsize/2;

  for (repetitions = 10; repetitions < 1000001; repetitions *= 10)
  {

      clock_t start = std::clock();
      for (int r = 0; r < repetitions; r++)
      {
         find (a, arrsize, x);
      }
      clock_t end = std::clock();
      long ms = (double)(end-start)/(CLOCKS_PER_SEC/1000);
      std::cout << "Time passed = "
                << ms
                << "ms. for"
                << repetitions
                << " iterations."
                << std::endl;
  }
  //std::cout << "Find " << x << "=" << << std::endl;




}

int main ()
{

  char s[6] = "Hello";  //char[6]

  int iarray[] = {1,2,3};

  char texts[][6] = {
                      'H','E','L','L','O', 'z',
                      'W','O','z','L','D', 'a',
                      'C','A','T','z','q',0};

  std::cout << (texts[0]) << std::endl; //char[6][3] -> char[3]
  std::cout << (texts[1]) << std::endl; //char[6][3] -> char[3]
  std::cout << (texts[2]) << std::endl; //char[6][3] -> char[3]

  //std::cin >> texts[1];

  std::cout << (texts[0]) << std::endl; //char[6][3] -> char[3]
  std::cout << (texts[1]) << std::endl; //char[6][3] -> char[3]
  std::cout << (texts[2]) << std::endl; //char[6][3] -> char[3]

  int countAllLs = 0, countRowLs = 0;

  for (int rowCount = 0; rowCount < 3; rowCount++)
  {
    countRowLs = 0;

    std::cout << "Now processing row #" << rowCount << std::endl;
    for (int colCount = 0; colCount <5; colCount++)
    {
        if (texts[rowCount][colCount] == 'L')
        {
          countRowLs++;
        }
    }
    std::cout << "Number of Ls so far (row#"
              << rowCount
              << ")="
              << countRowLs
              << std::endl;
    countAllLs += countRowLs;
  }

  std::cout << "Total number of Ls=" << countAllLs << std::endl;

  for (int colCount = 0; colCount < 6; colCount++)
  {

    for (int rowCount = 0; rowCount < 3; rowCount++)
    {
      std::cout << texts[rowCount][colCount] << " ";
    }

    std::cout << std::endl;

  }

  char transposed[6][3];

  for (int rowCount = 0; rowCount < 3; rowCount++)
  {
    for (int colCount = 0; colCount < 6; colCount++)
    { //texts -> transposed
        transposed[colCount][rowCount]=texts[rowCount][colCount];
    }
  }

  std::cout << "========== TRANSPOSED =========\n";

  for (int rowCount = 0; rowCount < 6; rowCount++)
  {
    for (int colCount = 0; colCount < 3; colCount++)
    {
      std::cout << transposed[rowCount][colCount] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "========== A =========\n";


  int a[4][4] = {1, 2, 3, 4,
                 5, 6, 7, 8,
                 9, 10, 11, 12,
                13, 14, 15, 16};

  for (int rowCount = 0; rowCount < 4; rowCount++)
  {
    for (int colCount = 0; colCount < 4; colCount++)
    {
      std::cout << std::setw(4) << a[rowCount][colCount];
    }
    std::cout << std::endl;
  }

  int save;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < i; j++)
    {
      save = a[i][j];
      a[i][j] = a[j][i];
      a[j][i] = save;

    }
    std::cout << std::endl;
  }
  std::cout << "========== AT =========\n";

  for (int rowCount = 0; rowCount < 4; rowCount++)
  {
    for (int colCount = 0; colCount < 4; colCount++)
    {
      std::cout << std::setw(4) << a[rowCount][colCount];
    }
    std::cout << std::endl;
  }

  std::cout << "========== FIND =========\n";

  //bool find (int a[], size_t size, int x)
  timedFind();


}
