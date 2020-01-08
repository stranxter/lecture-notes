#include <iostream>
#include <cstring>
#include <cassert>


char* _concatenate (const char *s1, const char *s2)
{
    //strlen (s1), strlen (s2), stcpy, strcat

    char *newBuffer = new char[strlen(s1) + strlen(s2) + 1];

    strcpy (newBuffer,s1);
    strcat (newBuffer, s2);

    return newBuffer;
}

struct intarray
{
    int *pa;
    size_t size;
};

void add_unique (intarray &result, intarray a)
{
    for (size_t i = 0; i < a.size; ++i)
    {
        //a1[i] се среща в result или не?
        size_t ri = 0;
        while (ri < result.size && a.pa[i] != result.pa[ri])
        {
            ++ri;
        }
        //сигурно ли е, че a[i] не се среща в result?
        if (ri == result.size)
        {
            result.pa[result.size] = a.pa[i];
            ++result.size;
        }
    }    
}

void printAll (intarray a)
{
    std::cout << "[";
    for (int i = 0; i < a.size-1; i++)
        std::cout << a.pa[i] << ",";
    if (a.size > 0)
        std::cout << a.pa[a.size-1];
    std::cout << "]" << std::endl;
}

//a1 <- a2, n елемента
void copy (int a1[], int a2[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        a1[i] = a2[i];
    }
}


intarray _union (intarray a1, intarray a2)
{

    intarray result;
    result.pa = new int [a1.size+a2.size];
    result.size = 0;

    add_unique (result,a1); 
    add_unique (result,a2);

    int *end_result = new int [result.size];
    copy (end_result,result.pa,result.size);

    delete []result.pa;
    
    result.pa = end_result;

    return result;

}


void push (intarray &a, int x)
{
    //a.pa = {1,2,3,4};
    //s.size = 4;
    //x = 5;

    int *newarray = new int [a.size + 1];
    copy (newarray,a.pa,a.size);
    newarray[a.size] = x;

    delete a.pa;
    ++a.size;
    a.pa = newarray;
}

void remove (intarray &a, size_t index)
{
    assert (index < a.size);

    int *newarray = new int [a.size - 1];

    copy (newarray,a.pa,index);
    copy (newarray+index,a.pa+index+1,a.size-index-1);

    delete a.pa;
    --a.size;
    a.pa = newarray;


}


/*
_strduplicate (const char *s)
{

}
*/

int main ()
{

    char *s = _concatenate ("Hello ", "world!");

    std::cout << s << std::endl;
    delete s;

    int _a1[] = {1,2,5,9,10};
    int _a2[] = {3,4,9,8,7};

    intarray a1{_a1,5};
    intarray a2{_a2,5};

    intarray un = _union (a1,a2);

    printAll (un);
    delete un.pa;

    
    intarray test {new int[0],0};

    push (test,20);
    push (test,30);
    push (test,40);
    push (test,50);
    push (test,60);
    push (test,70);

    printAll (test);

    remove (test,0);
    printAll (test);
    remove (test,4);
    printAll (test);
    remove (test,2);
    printAll (test);


    



    return 0;
}