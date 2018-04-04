#include <iostream>
#include <cstring>
#include <fstream>

class Company
{
private:

  char *name;
  double budget;

  void copy (const char *n, double b)
  {
    name = new char[strlen(n)+1];
    strcpy (name, n);
    budget = b;
  }

public:

  Company ()
  {
    name = new char[1];
    name[0] = 0;

    budget = 0;
  }

  Company (const char *_n, double _b)
  {
    copy (_n, _b);
  }

  Company (const Company& other)
  {
    copy (other.name, other.budget);
  }

  Company& operator = (const Company& other)
  {
    if (this != &other)
    {
      delete []name;
      copy (other.name, other.budget);
    }
    return *this;
  }

  ~Company ()
  {
    delete []name;
  }
  friend std::ostream& operator << (std::ostream&, const Company&);
  friend std::istream& operator >> (std::istream&, Company&);

};

std::ostream& operator << (std::ostream& out, const Company& c)
{
  out << strlen(c.name)
      << std::endl
      << c.name
      << std::endl
      << c.budget
      << std::endl;
  return out;
}

std::istream& operator >> (std::istream &in, Company& c)
{
  int size;
  in >> size;
  in.get();

  delete c.name;
  c.name = new char [size+1];

  for (int i = 0; i < size; i++)
  {
    c.name[i] = in.get(); //in >> buffer[i];
  }
  c.name[size] = 0;

  in >> c.budget;

  return in;
}

void writeToFile (Company arr[], int size)
{
  std::ofstream f ("companies.txt");

  for (int i = 0; i < size; i++)
  {
    f << arr[i];
  }
}

void readFromFile (Company arr[], int size)
{
  std::ifstream f ("companies.txt");

  for (int i = 0; i < size; i++)
  {
    f >> arr[i];
  }

}

int main ()
{
  Company c1 ("Vivacom", 1000),
          c2 ("UniSofia", -200),
          c3 ("Toplofikacia\nSofia", 200000);

  Company a1[3] = {c1,c2,c3};
  writeToFile (a1, 3);

  Company a2[3];

  readFromFile (a2,3);

  for  (int i = 0; i < 3; i++)
  {
    std::cout << a2[i];
  }


}
