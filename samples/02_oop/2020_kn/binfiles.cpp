#include <iostream>
#include <fstream>

struct Student
{
    int fn;
    char name[100];
    double grade;
};


int main ()
{
    Student students[] = {{42860,"Kalin Georgiev",5.50},{99999,"Ivan Petrov",6.00}, {8888,"Mriya Ivanova",6.00}};
/*
    std::ofstream out ("students.txt");

    for (int i = 0; i < 3; ++i)
    {
        out << students[i].fn 
            << std::endl
            << students[i].name
            << std::endl
            << students[i].grade
            << std::endl;
    }

    out.close();

    std::ifstream in ("students.txt");
    Student students2[3];

    for (int i = 0; i < 3; ++i)
    {
        in >> students2[i].fn; in.get();
        in.getline (students2[i].name,100);
        in >> students2[i].grade; in.get();
    }

    std::cout << students2[2].fn << std::endl;
    
*/
   std::ofstream out ("students.bin", std::ios::binary);

    for (int i = 0; i < 3; ++i)
    {
        out.write((char*)(&students[i]), sizeof(Student));
    };


}