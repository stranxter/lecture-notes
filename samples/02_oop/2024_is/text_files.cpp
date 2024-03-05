#include <cassert>
#include <iostream>
#include <fstream>

struct Student
{
    int fn;
    char name[100];
    double grades[10];
    int nGrades;

};

const int maxStudents = 1000;

Student myStudentsDB[maxStudents];
int nStudents = 0;


void addStudentToDatabase(Student student)
{
    assert(nStudents < maxStudents);

    myStudentsDB[nStudents] = student;
    ++nStudents;

}

void writeStudent(Student s, std::ostream& out)
{
    out << s.name << std::endl;
    out << s.fn << ":";
    out << s.nGrades << " ";
    for(int igrade = 0; igrade < s.nGrades; ++igrade)
    {
        out << " " << s.grades[igrade];
    }
    out << std::endl;    
}

void printAllStudents()
{
    for(int i = 0; i < nStudents; ++i)
    {
        writeStudent(myStudentsDB[i],std::cout);
    }
}

void saveDatabase(const char* fileName)
{
    std::ofstream myFile (fileName);

    myFile << nStudents << std::endl;

    for(int i = 0; i < nStudents; ++i)
    {

        writeStudent(myStudentsDB[i],myFile);
 
    } 
}

Student readStudentData(std::istream& in)
{
    Student s;

    in.getline(s.name,100);
    in >> s.fn;

    assert(in.get() == ':');

    in >> s.nGrades;

    for(int i = 0; i < s.nGrades; ++i)
    {
        in >> s.grades[i];
    }
    in.get();

    return s;
}

void loadDatabase(const char* fileName)
{
    std::ifstream myFile (fileName);
    int nSt;
    
    myFile >> nSt;
    myFile.get();

    for(int istudent = 0; istudent < nSt; ++istudent)
    {
        Student s = readStudentData(myFile);
        addStudentToDatabase(s);
    }
}

void insertNewStident()
{
    std::cout << "Please enter: <name>\n<fn>:<g1> ... <gk>=";
    Student s = readStudentData(std::cin);
    addStudentToDatabase(s);
}

void searchStudent()
{
    std::cout << "Please enter fn=";
    int fn;
    std::cin >> fn;

    for(int i = 0; i < nStudents; ++i)
    {
        if(myStudentsDB[i].fn == fn)
        {
            writeStudent(myStudentsDB[i],std::cout);
            return;
        }
    }

    std::cout << "Student not found!\n";
}

int main()
{

    while (true)
    {

        std::cout << "     WELCOME TO STUDENTS DB\n"
                    "=================================\n"
                    "Please select:\n"
                    "1. Load database\n"
                    "2. Save datavase\n"
                    "3. Print all data\n"
                    "4. Insert new student\n"
                    "5. Search student\n"
                    "0. Exit\n"
                    "Your choice = ";
        int choice;
        std::cin >> choice;
        std::cin.get();
        switch(choice)
        {
            case 1: loadDatabase("kalin_students.txt"); break;
            case 2: saveDatabase("kalin_students.txt"); break;
            case 3: printAllStudents(); break;
            case 4: insertNewStident(); break;
            case 5: searchStudent(); break;
            case 0: exit(0); 
        }

    }


}

