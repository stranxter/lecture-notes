//find, count, filter
#include <iostream>
#include <cstring>

/*
* Търсене на елементи, удовлетворяващи
* някакво свойство: find
*/
template <class T>
bool find (T a[], size_t size, T x)
{
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}

/*
* find от високо ниво: superfind
*/

template <class T>
using Test = bool (*) (T);

template <class T>
bool superfind (T a[], size_t size, Test<T> pred)
{
    for (size_t i = 0; i < size; i++)
    {
        if (pred(a[i]))
        {
            return true;
        }
    }
    return false;
}

bool is5 (int x)
{
    return x == 5;
}
bool is15 (int x)
{
    return x == 15;
}

bool is444 (double x)
{
    return x == 4.44;
}

bool iseven (int x)
{
    return x % 2 == 0;
}


/*
* find от високо ниво: supercount
*/

template <class T>
size_t supercount (T a[], size_t size, Test<T> pred)
{

    size_t count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (pred(a[i]))
        {
            ++count;
        }
    }
    return count;
}

/*
* Работа със студенти
*/

struct Student
{
    int fn;
    char name[100];
    double grade;

};

bool isExcellent (Student s)
{
    return s.grade >= 5.5;
}

bool isKalin (Student s)
{
    return strncmp (s.name,"Kalin",5) == 0;
}

/*
* Филтриране
*/

struct intarray
{
    int* buffer;
    size_t n;
};

intarray filter (intarray arr, Test<int> pred)
{
    intarray result;

    result.n = supercount (arr.buffer,arr.n,pred);
    result.buffer = new int [result.n];

    size_t resulti = 0;
    for (size_t i = 0; i < arr.n; i++)
    {
        if (pred(arr.buffer[i]))
        {
            result.buffer[resulti] = arr.buffer[i];
            resulti++;
        }
    }

    return result;
}

template <class T>
void printArray (T arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main ()
{

    //======== find =======

    int ia[] = {1,2,3,4,5,6,7,8,9,10};
    std::cout << find (ia,10,5) << std::endl;
    std::cout << find (ia,10,15) << std::endl;

    double da[] = {1.0,2.0,3.0,4.44,5.67,6,7,8,9,10};
    std::cout << find (da,10,4.44) << std::endl;
    std::cout << find<double> (da,10,4) << std::endl;

    //======== superfind =======

    std::cout << superfind (ia,10,is5) << std::endl;
    std::cout << superfind (ia,10,is15) << std::endl;
    
    //!!!!
    std::cout << superfind (ia,10,iseven) << std::endl;

    std::cout << superfind (da,10,is444) << std::endl;

    //======== supercount =======
    //!!!!
    std::cout << supercount (ia,10,iseven) << std::endl;

    //======== Students =======

    Student students[] = {{42860,"Kalin Georgiev",4.67},
                           {85234,"Georgi Kalinov",6.57},
                           {83233,"Ivan Petrov",7.00}};

    std::cout << supercount (students,3,isExcellent) << std::endl;

    std::cout << supercount (students,3,isKalin) << std::endl;

    //======== Filter =======

    intarray filtered = filter ({ia,10},iseven);
    printArray (filtered.buffer, filtered.n);
    delete filtered.buffer;

    

    return 0;
}