#include <iostream>
#include <cstring>

/*

    arr1.da_print();
    arr2.da_print();


*/

template <typename T>
class DynArray   //DynArray<int>, DynArray<char>
{
    private:

    T *arr;
    unsigned size;

    /*
    arr1.print();
    arr2.print();
    */

    public:

    DynArray()
    {
        arr = nullptr;
        size = 0;
    }

    DynArray(const DynArray<T>& original)
    {
        this->arr = new T[original.size];
        this->size = original.size;

        for (int i = 0; i < size; ++i)
        {
            this->arr[i] = original.arr[i];
        }

    }

    DynArray (const char *original)
    {
        size = strlen(original);
        arr = new T[size];
        for(int i = 0; i < size; ++i)
        {
            arr[i] = original[i];
        }
    }
    
    DynArray(unsigned n)
    {
        arr = new T[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = 0;
        }
        size = 50;
    }
    

    void print(/*DynArray *this*/)
    {
        for(int i = 0; i < this->size; ++i)
        {
            std::cout << this->arr[i] << " ";
        }
        std::cout << std::endl;
    }

    /* намалява броя на елементите на масив до число n*/
    // приемаме, че a.size > n */
    void trim(unsigned n)
    {   
        if(n >= size)
            return;
        
        T* new_array = new T[n];

        for(int i = 0; i < n; ++i)
        {
            new_array[i] = arr[i];
        }
        delete arr;
        arr = new_array;
        size = n;

    }

    void insert(T x)
    {
        T *new_array = new T[this->size+1];
        for (int i = 0; i < this->size; ++i)
        {
            new_array[i] = this->arr[i];
        }
        new_array[this->size] = x;
        ++this->size;
        
        delete arr;
        arr = new_array;
    }

    /*

        arr1.input();
        arr2.input();

    */
    void input()
    {
        T x;
        do
        {
            std::cout << "Моля, въведете елемент:";
            std::cin >> x;
            std::cin.ignore();

            this->insert(x);

            std::cout << "Ще въвеждате ли още елементи?";
        } while (std::cin.get()=='y');
    }

    DynArray<T> operator+(DynArray<T> a2)
    {
        DynArray<T> result;// = {new T[this->size + a2.size], //result.arr
                        //this->size + a2.size}; //result.size 
        result.arr = new T[this->size + a2.size];
        result.size = this->size + a2.size;


        for(int i = 0; i < this->size; ++i)
        {
            result.arr[i] = this->arr[i];
        }

        for(int i = 0; i < a2.size; ++i)
        {
            result.arr[this->size+i] = a2.arr[i];
        }
            
        return result;
    }

};

void f(DynArray<double> d)
{
    //cwenhjkfwenlk
}

int main()
{

    /*
    DynArray<double> arr1 = input_array<double>();
    DynArray<double> arr2 = input_array<double>();
    */

    DynArray<double> arr1, arr2;

    f("Hello");

    arr1.insert(1);
    arr1.insert(2);
    arr1.insert(3);
    arr1.insert(4);
    arr1.insert(5);

    arr2.insert(9);
    arr2.insert(8);
    arr2.insert(7);
    arr2.insert(6);
    arr2.insert(5);
    arr2.insert(4);
  
    arr1.trim(2);

    arr1.print();
    arr2.print();

    //da_concat(arr1,arr2).print();
    (arr1+arr2).print();
    arr1.operator+(arr2).print();

    DynArray<double> arr3 = arr2;

    std::cout << "ARR2 \n";
    arr2.print();

    arr3.insert(100);

    std::cout << "ARR2 \n";
    arr2.print();

    DynArray<double> strange = "Hello world!";
    
    strange.print();

    //strange.operator=(arr2);


}














