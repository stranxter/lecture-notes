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

int main ()
{
    Student s1, s2, s3;

    s1.fn = 42860;
    strcpy (s1.name,"Kalin Georgiev");
    s1.grade = 5.57;

    s2.fn = 42999;
    strcpy (s2.name,"Trifon Trifonov");
    s2.grade = 6.00;

    s3.fn = 99999;
    strcpy (s3.name,"Ivan Petrov");
    s3.grade = 5.99;

    Student arr[3] = {s1,s2,s3};


    printStudents (arr,3,std::cout);

    std::ofstream outf ("students.txt");

    printStudents (arr,3,outf);



}