#include <iostream>

/*
 - Динамичен масив с цели числа

 - Добавяне на число
 - *Премахване
 - Проверка за принадлежност

 - Сравнение за равенство
 - Присвояване
 - Скаларно произведение []
 - Конкатенация

 - извеждане на стандартния изход
*/

class DynArray 
{ public:
    int *first;
    unsigned size;

    void print()
    //DynArray* this
    {
        std::cout << "{";
        for(int i = 0; i < size; ++i)
        {
            std::cout << first[i] << " ";  //<=> *(a.first+i)
        }
        std::cout << "}:" << size << std::endl;
    }

    void operator+=(int x)
    {
        int *newBuffer = new int[size+1];
    
        for(int i = 0; i < size; ++i)
        {
            newBuffer[i] = first[i];
        }
    
        newBuffer[size] = x;
    
        ++size;
    
        delete first;
        first = newBuffer;
    }

    DynArray operator+(DynArray b)
    {
        DynArray result;
        result.first = new int [size + b.size];
        result.size = size + b.size;
    
        for(int i = 0; i < size; ++i)
        {
            result.first[i]=first[i];
        }
        for(int i = size; i < size + b.size; ++i)
        {
            result.first[i]=b.first[i-size];
        }
    
        return result;
    }

    bool member(int x)
    {
        for(int i = 0; i < size; ++i)
        {
            if(first[i] == x)
            {
                return true;
            }
        }
        return false;
    }
        

};



bool eq(DynArray a, DynArray b)
{
    if(a.size != b.size)
    {
        return false;
    }

    for(int i = 0; i < a.size; ++i)
    {
        if(a.first[i] != b.first[i])
        {
            return false;
        }
    }

    return true;
}


int main()
{
    DynArray array = {nullptr,0},
             array2 = {nullptr,0};


    array += 10;
    
    array += 10;
    array += 20;
    array += 30;
    array += 40;
    array2 += 30;
    array2 += 60;
    array2 += 90;

    array.print();
    array2.print();

    array.operator+(array2).print();

    (array + array2).print();
    
    array=array+array2;
    

    //if(eq(concat(array,array),concat(array,array)))
    if(array.member(10))
    {
        std::cout << "Yes!";
    }


}