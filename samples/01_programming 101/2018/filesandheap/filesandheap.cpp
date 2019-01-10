#include <iostream>
#include <fstream>

const size_t maxGrades = 15;

struct Student
{
  unsigned long fn;
  char name[100];
  double grades[maxGrades];
  size_t nGrades;
};

Student* loadStudents (size_t &nStudents)
{

  std::ifstream db ("students.db");

  db >> nStudents;
  Student* students = new Student [nStudents];

  for (size_t i = 0; i < nStudents; i++)
  {
    db >> students[i].fn;
    db.get();
    db.getline (students[i].name,100);
    db >> students[i].nGrades;
    for (size_t cgrade = 0; cgrade < students[i].nGrades; cgrade++)
    {
      db >> students[i].grades[cgrade];
    }
  }
  return students;
}

void addStudent (Student database[], size_t &nStudents)
{
  nStudents++;

  //TBD
}

void printStudent (const Student &s)
{
  std::cout << s.name
            << " : "
            << s.fn
            << std::endl;
  for (size_t cgrade = 0; cgrade < s.nGrades; cgrade++)
  {
    std::cout << s.grades[cgrade] << " ";
  }

  std::cout << std::endl;

}

void saveStudents (Student arr[], size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    printStudent (arr[i]);
  }
}

int main ()
{
  size_t nStudents;
  Student *database = loadStudents(nStudents);

  char choice = 0;

  while (choice != 'q')
  {

    std::cout << "-----------MENU-----------\n"
              << "p: Print All Students\n"
              << "a: Add New Student\n"
              << "q: Quit\n";
    std::cin >> choice;
    switch (choice)
    {
      case 'p': saveStudents (database,nStudents); break;
      case 'a': addStudent (database, nStudents); break;

    };
  };



}
