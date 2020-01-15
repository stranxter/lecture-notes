#include <iostream>
#include <fstream>
#include <cstring>


struct Student
{
    int fn;
    char name[100];
    double grade;
};

void printStudents (Student arr[], int size, std::ostream &out)
{
    for (int i =0; i < 3; ++i)
    {
        out << arr[i].fn
            << " "
            << arr[i].name 
            << std::endl
            << arr[i].grade
            << std::endl;
    }    
}

void deleteStudent (const char *f1, const char *f2, int fn, int n)
{
    std::ifstream in (f1);
    std::ofstream out (f2);

    for (int i = 0; i < n; ++i)
    {
        Student s;
        
        in >> s.fn;
        char c = in.get();
        in.getline (s.name,100);
        in >> s.grade;        

        if (s.fn != fn)
        {
            out << s.fn
                << " "
                << s.name 
                << std::endl
                << s.grade
                << std::endl;
        }
    }
}

int main ()
{
    deleteStudent ("students.txt","result.txt",42999,3);

}