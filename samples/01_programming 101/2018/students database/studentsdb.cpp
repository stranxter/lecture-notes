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

struct StudentDB
{
  Student *buffer;
  size_t nStudents;
  size_t bufferSize;
};

Student readStudent (std::istream& in, bool prompts)
{
  Student student;

  if (prompts)
    std::cout << "Please enter fn=";
  in >> student.fn;
  if (prompts)
    std::cout << "Please enter name=";
  in.get();
  in.getline (student.name,100);
  if (prompts)
    std::cout << "Please enter number of grades=";
  in >> student.nGrades;
  for (size_t cgrade = 0; cgrade < student.nGrades; cgrade++)
  {
    if (prompts)
      std::cout << "Please enter " << cgrade << "-th grade=";
    in >> student.grades[cgrade];
  }

  return student;
}

StudentDB loadStudents ()
{
  
  StudentDB db;
  //ifstream cin
  std::ifstream dbfile ("students.db");

  dbfile >> db.nStudents;
  db.bufferSize = db.nStudents;
  db.buffer = new Student [db.nStudents];

  for (size_t i = 0; i < db.nStudents; i++)
  {
    db.buffer[i] = readStudent (dbfile,false);
  }
  return db;
}

void addStudent (StudentDB &db)
{
  Student newStudent = readStudent (std::cin, true);

  if (db.bufferSize == db.nStudents)
  {
    Student* largerDatabase = new Student[db.nStudents+1];
    for (size_t i = 0; i < db.nStudents; i++)
    {
      largerDatabase[i] = db.buffer[i];
    }
    delete db.buffer;
    db.buffer = largerDatabase;
    db.bufferSize = db.nStudents+1;
  }

  db.buffer[db.nStudents] = newStudent;
  db.nStudents++;


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

void writeStudentToStream (Student student, std::ostream& out)
{
  out << student.fn 
      << " "
      << student.name
      << std::endl
      << student.nGrades
      << " ";
  for (size_t i = 0; i < student.nGrades; i++)
  {
    out << student.grades[i] << " ";
  }
  out << std::endl;
}

void printStudents (StudentDB db)
{
  std::cout << "-------- " << db.nStudents << " students, " << db.bufferSize << " slots -------------\n";

  for (size_t i = 0; i < db.nStudents; i++)
  {
    std::cout << "*** Student " << i << " ***\n";
    printStudent (db.buffer[i]);
  }
}

void saveStudents (StudentDB db)
{
  std::ofstream dbfile ("students.db");

  dbfile << db.nStudents << std::endl;

  for (size_t i = 0; i < db.nStudents; i++)
  {
    writeStudentToStream (db.buffer[i],dbfile);
  }

}

void deleteStudent (StudentDB &db)
{
  std::cout << "Please enter fn=";
  int fn;
  std::cin >> fn;

  size_t indexOfStudent;
  size_t i = 0;
  while (i < db.nStudents && db.buffer[i].fn != fn)
  {
    i++;
  }
  if (i == db.nStudents)
  {
    std::cout << "No such student!!!\n";
    return;
  }
  //...
  for (;i+1 < db.nStudents;i++)
  {
    db.buffer[i] = db.buffer[i+1] ;
  }
  db.nStudents--;
  
  
}

int main ()
{
  StudentDB database = loadStudents();

  char choice = 0;

  while (choice != 'q')
  {
    std::cout << "-----------MENU-----------\n"
              << "p: Print All Students\n"
              << "a: Add New Student\n"
              << "s: Save DB to file\n"
              << "d: Delete Student\n"
              << "q: Quit\n";
    std::cin >> choice;
    switch (choice)
    {
      case 'p': printStudents (database); break;
      case 'a': addStudent (database); break;
      case 's': saveStudents (database); break;
      case 'd': deleteStudent (database); break;

    };
  };
}
