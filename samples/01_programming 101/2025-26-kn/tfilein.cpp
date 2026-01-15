#include <iostream>
#include <fstream>

struct Student
{
    int fn;
    char name[100];
    double grade;
};

int main()
{
    Student students[2];

    std::ifstream data ("class.txt");

    for(unsigned i = 0;i < 2; ++i)
    {
        data >> students[i].fn;
        data >> students[i].grade;
        data.getline(students[i].name,99);
    }

    for(unsigned i = 0; i < 2; ++i)
    {
        std::cout << students[i].fn << " "   
                  << students[i].grade << " "
                  << students[i].name << std::endl;
    }

}