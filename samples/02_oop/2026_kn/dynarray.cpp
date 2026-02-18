#include <iostream>

template <typename T>
struct DynArray   //DynArray<int>, DynArray<char>
{
    T *arr;
    unsigned size;
};

/* намалява броя на елементите на масив до число n*/
// приемаме, че a.size > n */
template <typename T>
void da_trim(DynArray<T> &a, unsigned n)
{   
    if(n >= a.size)
        return;
    
    T* new_array = new T[n];

    for(int i = 0; i < n; ++i)
    {
        new_array[i] = a.arr[i];
    }
    delete a.arr;
    a.arr = new_array;
    a.size = n;

}

template <typename T>
DynArray<T> da_concat(DynArray<T> a1, DynArray<T> a2)
{
    DynArray<T> result = {new T[a1.size + a2.size], //result.arr
                       a1.size + a2.size}; //result.size 

    for(int i = 0; i < a1.size; ++i)
    {
        result.arr[i] = a1.arr[i];
    }

    for(int i = 0; i < a2.size; ++i)
    {
        result.arr[a1.size+i] = a2.arr[i];
    }
          
    return result;
}

template <typename T>
void da_insert(DynArray<T> &a, T x)
{
    T *new_array = new T[a.size+1];
    for (int i = 0; i < a.size; ++i)
    {
        new_array[i] = a.arr[i];
    }
    new_array[a.size] = x;
    ++a.size;
    
    delete a.arr;
    a.arr = new_array;
}

template <typename T>
void da_print(DynArray<T> a)
{
    for(int i = 0; i < a.size; ++i)
    {
        std::cout << a.arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
DynArray<T> input_array()
{
    DynArray<T> user_input = {nullptr, 0};

    T x;
    do
    {
        std::cout << "Моля, въведете елемент:";
        std::cin >> x;
        std::cin.ignore();

        da_insert(user_input,x);

        std::cout << "Ще въвеждате ли още елементи?";
    } while (std::cin.get()=='y');

    return user_input;
}

int main()
{

    DynArray<int> iarr = input_array<int>();


    DynArray<double> arr1 = input_array<double>();
    DynArray<double> arr2 = input_array<double>();
    //DynArray arr1 = {{1,2,3,4,5},5};
    
    DynArray<double> c = da_concat(arr1,arr2);    
    delete arr1.arr;
    delete arr2.arr;

    da_print<double>(c);
    delete c.arr;

}