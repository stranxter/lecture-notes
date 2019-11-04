#include <iostream>
#include "dllist.h"
#include "dllist.cpp"


#include "sequence.hpp"
#include "mappediterator.hpp"
#include "filteriterator.hpp"

#include "functions.hpp"



int plusone (const int& x)
{
    return x+1;
}

int plus (const int& x, const int& y)
{
    return x+y;
}

struct Student
{
    char name[50];
    int age;
    int group;
};

int getAge (const Student& s)
{
    return s.age;
}

bool isYoung (const Student& s)
{
    return s.age <= 20;
}

int main ()
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);



    /*
    for (DListIterator<int> current = test.begin();
         current != test.end();
         ++current)
    {

        std::cout << *current << std::endl;
        
    }
    */

    Sequence<DListIterator<int>> seq(test.begin(), test.end());

    std::cout << "======ORGINAL SEQUENCE=======\n";

    for (int x : seq)
    {
        std::cout << x << std::endl;
    }

    std::cout << "======MAPPED SEQUENCE=======\n";

    for (int x : map(seq, plusone))
    {
        std::cout << x << std::endl;
    }

    std::cout << "======REDUCED SEQUENCE=======\n";

    std::cout << "sum = " << reduce (map(seq,plusone),plus,0) << std::endl;

    DLList<Student> students;
    //Student s= ;
    students.insertAt(0, {"Kalin Georgiev", 38, 4});
    students.insertAt(1, {"Ivan Petrov", 19, 1});
    students.insertAt(2, {"Petyr Ivaniov", 18, 4});
    students.insertAt(3, {"Mariya Gerogieva", 19, 1});

    Sequence<DListIterator<Student>> studseq (students.begin(),students.end());

    std::cout << "======AGES OF STUDENTS=======\n";

    for (int x: map (studseq,getAge))
    {
        std::cout << x << std::endl;
    }

    std::cout << "======SUM OF AGES OF STUDENTS=======\n";

    std::cout << "sum = " << reduce(map(studseq, getAge), plus, 0) << std::endl;

    std::cout << "======LIST OF YOUNG STUDENTS=======\n";

    for (Student s : filter (studseq,isYoung))
    {
        std::cout << s.name << std::endl;
    }

    std::cout << "======AVERAGE AGE OF YOUNG STUDENTS=======\n";

    std::cout << "sum = " << reduce(map(filter(studseq, isYoung), getAge), plus, 0) / filter(studseq, isYoung).size() << std::endl;
}