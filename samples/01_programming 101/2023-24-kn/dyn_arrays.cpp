#include <iostream>

struct DynArray
{
    int *arr;
    size_t size;
};

/* Въвежда от стандартния вход размер на масива и 
   елементите му
*/
DynArray arr_input()
{

    DynArray result;

    std::cout << "Моля, въведете n=";
    std::cin >> result.size;

    result.arr = new int[result.size];

    for(size_t i = 0; i < result.size; ++i)
    {
        std::cout << "Моля, веведете a[" << i << "]=";
        std::cin >> result.arr[i];
    }

    return result;
}

bool arr_member(DynArray arr, int x)
{
    for(size_t i = 0; i < arr.size; ++i)
    {
        if(x==arr.arr[i])
        {
            return true;
        }
    }
    return false;
}

size_t arr_countCommon(DynArray a1, DynArray a2)
{
    size_t common = 0;
    for(size_t i = 0; i < a1.size; ++i)
    {
        if(arr_member(a2,a1.arr[i]))
        {
            ++common;
        }
    }
    return common;
}

DynArray arr_intersect(DynArray a1, DynArray a2)
{
    DynArray result;
    result.size = arr_countCommon(a1,a2);
    result.arr = new int[result.size];

    size_t count = 0;

    for(size_t i = 0; i < a1.size; ++i)
    {
        if(arr_member(a2,a1.arr[i]))
        {
            result.arr[count] = a1.arr[i];
            ++count;
        }
    }

    return result;
}

void arr_print(DynArray array)
{
    for(size_t i = 0; i < array.size; ++i)
    {
        std::cout << "a[" << i << "]=" << array.arr[i] << std::endl;
    }
}

void arr_inc(DynArray arr)
{
    for(size_t i = 0; i < arr.size; ++i)
    {
        ++arr.arr[i];
    }
}
/*
    Вмъква числото x в началото на масива a, 
    като за целта "рзширява" a
*/
void arr_push(DynArray &a, int x)
{
    int *newArray = new int[a.size + 1];

    newArray[0] = x;
    for(size_t i = 0; i < a.size; ++i)
    {
        newArray[i+1] = a.arr[i];
    }

    delete a.arr;
    a.arr = newArray;
    ++a.size;

}

void append(DynArray &a1, DynArray a2)
{
    int *newArray = new int[a1.size + a2.size];
    for(size_t i = 0; i < a1.size; ++i)
    {
        newArray[i] = a1.arr[i];
    }
    for(size_t i = 0; i < a2.size; ++i)
    {
        newArray[a1.size+i] = a2.arr[i];
    }

    delete a1.arr;
    a1.arr = newArray;
    a1.size = a1.size + a2.size;
}

DynArray concat(DynArray a1, DynArray a2)
{
    int *newArray = new int[a1.size + a2.size];
    for(size_t i = 0; i < a1.size; ++i)
    {
        newArray[i] = a1.arr[i];
    }
    for(size_t i = 0; i < a2.size; ++i)
    {
        newArray[a1.size+i] = a2.arr[i];
    }

    return {newArray,a1.size + a2.size};
}

int main()
{
    DynArray arr1 = arr_input();

    append(arr1,arr1);

    DynArray arr2 = concat(arr1,arr1);

    arr_print(arr2);

    delete arr1.arr;
    delete arr2.arr;
    //.......
}