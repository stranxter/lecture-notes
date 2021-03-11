#include "vector.h"

void IntVector::add(int data)
{
    //contents: буфер в паметта, съдържащ size на брой числа,
    //вмъкнати до момента чрез add
    //size: броя на числа в буфера

    int *newContents = new int [size+1];

    for (size_t i = 0; i < size; ++i)
    {
        newContents[i] = contents[i];
    }

    newContents[size] = data;
    ++size;

    delete []contents;
    contents = newContents;
    
}
