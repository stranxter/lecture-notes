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
    Student students[] = {{42860, "Калин Георгиев", 5.0},
                          {99999, "Трифон Трифонов", 6.0}};


    std::ofstream data ("class.txt");

    for(unsigned i = 0; i < 2; ++i)
    {
        data << students[i].fn << " "   
             << students[i].grade << " "
             << students[i].name << std::endl;
    }
}