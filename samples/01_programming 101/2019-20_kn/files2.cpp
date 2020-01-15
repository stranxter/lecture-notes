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
            << std::endl
            << arr[i].name 
            << std::endl
            << arr[i].grade
            << std::endl;
    }    
}

int main ()
{
    Student s1, s2, s3;

    Student arr[3];

    std::ifstream inf ("students.txt");

    for (int i = 0; i < 3; ++i)
    {
        inf >> arr[i].fn;
        char c = inf.get();
        inf.getline (arr[i].name,100);
        inf >> arr[i].grade;        
    }

    printStudents (arr,3,std::cout);

}