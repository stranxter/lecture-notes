#include <iostream>
#include <cstring>
#include <fstream>

template <typename T>
using BinOp = T(*)(T,T);


template <typename T>
class DynArray   //DynArray<int>, DynArray<char>
{
    private:

    template <typename T2>
    friend void operator<<(std::ostream&, const DynArray<T2>&);

    T *arr;
    unsigned size;

    public:

    DynArray()
    {
        arr = nullptr;
        size = 0;
    }

    DynArray(const DynArray<T>& original)
    {
        copy(original);
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
    
    DynArray(T singleton)
    {
        arr = new T[1];
        arr[0] = singleton;
        size = 1;
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
        delete []arr;
        arr = new_array;
        size = n;
    }

    DynArray<T>& insert(T x)
    {
        T *new_array = new T[this->size+1];
        for (int i = 0; i < this->size; ++i)
        {
            new_array[i] = this->arr[i];
        }
        new_array[this->size] = x;
        ++this->size;
        
        delete []arr;
        arr = new_array;
        return *this;
    }

    DynArray<T>& input()
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

        return *this;
    }

    DynArray<T>& operator=(const DynArray<T>& original)
    {
        if(this != &original)
        {
            delete []this->arr;
            copy(original);            
        }
        return *this;
    }

    DynArray<T>& operator+=(DynArray<T> a2)
    {
        *this = (*this + a2);
        return *this;
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
            
        return result;  //(a+b)
    }

    T& operator[](unsigned index)
    {
        return arr[index];
    }

    unsigned lenght() const
    {
        return size;
    }

    ~DynArray()
    {
        delete []arr;        
    }

    //агрегиране на елементите на масив чрез двуместна операция
    //(събиране, умножеснир и др.)
    T reduce(BinOp<T> op, T null_val)
    {
        T result = null_val;
        for (int i = 0; i < this->size; ++i)
        {
            result = op(result,this->arr[i]);
        }

        return result;
    }



    private:

    void copy(const DynArray<T>& original)
    {
        this->arr = new T[original.size];
        this->size = original.size;

        for (int i = 0; i < size; ++i)
        {
            this->arr[i] = original.arr[i];
        }
    }
};

template <typename T>
void operator<<(std::ostream& out, const DynArray<T>&d)
{
    out << "{";
    for(int i = 0; i < d.size; ++i)
    {
        out << d.arr[i] << " ";
    }
    out << std::endl;
    out << "}";
    
}


void f(DynArray<double> d)
{
    //
}


std::function<double(double)> maxf(std::function<double(double)>f, 
                         std::function<double(double)>g)
{
    return [f,g](double x)->double {return std::max(f(x),g(x)); };
}

std::function<double(double)> maxall(DynArray<std::function<double(double)>> functions)
{
    std::function<double(double)> result = functions[0];
    for(int i = 1; i < functions.lenght(); ++i)
    {
        result = maxf(functions[i],result);
    }

    return result;

}




int main()
{
    /*
    DynArray<double> arr1 = input_array<double>();
    DynArray<double> arr2 = input_array<double>();
    */
    DynArray<double> arr1 = 20, arr2;

    arr1.insert(1).insert(2).insert(3).insert(4).insert(5);

    arr2.insert(0);

    arr1.print();
    arr2.print();

    arr2 = arr1;

    arr2.insert(6);

    arr2.print();
    arr1.print();

    DynArray<double> *p = new DynArray<double>[10];
    delete []p;

    DynArray<double> arr3(5);

    //arr3 = arr2 = arr1;
    //arr3.operator=(arr2.operator=(arr1));


    std::ofstream f("data.txt");

    f << (arr1 += arr2).insert(10).insert(20).insert(30);

    //arr3.input().print();

    //std::cout << arr1;

    std::cout << arr1[10];

    arr1[10] = 7;


    DynArray<std::function<double(double)>> fs;

    fs.insert([](double x)->double{return x*x;});
    fs.insert([](double x)->double{return x*x*x;});
    fs.insert([](double x)->double{return x;});

    std::cout << fs[1](10) << std::endl;

    std::cout << maxall(fs)(10) << " " << maxall(fs)(0.5) << std::endl;

    std::function<double(double)> maxf2 = fs.reduce(maxf,fs[0]);

    std::cout << maxf2(10) << " " << maxf2(0.5) << std::endl;


}

