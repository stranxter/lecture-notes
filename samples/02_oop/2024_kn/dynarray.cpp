#include <iostream>

template <typename T>
class DynArray
{
    public:

    T *arr;
    size_t size;

    DynArray() //конструктор
    {
        arr = new T[0];
        size = 0;

        std::cout << "I AM BORN!n";
    }

    DynArray(T x) //конструктор
    {
        arr = new T[1];
        size = 1;
        arr[0] = x;
    }

    void copy(const DynArray& other)
    {
        this->size = other.size;

        this->arr = new T[this->size];

        for(int i = 0; i < this->size; ++i)
        {
            this->arr[i] = other.arr[i];
        }
    }

    
    DynArray(const DynArray& other)
    {
        std::cout << "COPY CONSTRUCTOR\n";          
        copy(other);
    }
    
    DynArray<T>& operator=(const DynArray& other)
    {
        //a=b | &a->this, b->other

        if(this != &other)
        {
            delete arr;
            copy(other);
        }

        //c = (a = b)
        return *this;
    }

    DynArray& operator+=(const T& x)
    {
        //arr[size] = x;
        //arr------>[1] [3] [1] [5] +[x]

        T *newArr = new T[size+1];
        //newArr --------> [?] [?] [?] [?] [?]

        for(int i = 0; i < size; ++i)
        {
            newArr[i] = arr[i];
        }
        //newArr --------> [1] [3] [1] [5] [?]

        newArr[size] = x;
        //newArr --------> [1] [3] [1] [5] [x]

        //arr---------> [1] [3] [1] [5]
        //newArr -----> [1] [3] [1] [5] [x]

        delete arr;
        //arr---------> ~~~~~~~~~~~~~~~~~~~~~~~~
        //newArr -----> [1] [3] [1] [5] [x]
        
        arr = newArr;
        //arr------\    ~~~~~~~~~~~~~~~~~~~~~~~~~~
        //newArr -----> [1] [3] [1] [5] [x]

        ++size;

        return *this;
    }

    DynArray operator+(const DynArray& other) const
    {
        DynArray result;
        result.init();

        for(int i = 0; i < this->size; ++i)
        {
            result += this->arr[i];
        }

        for(int i = 0; i < other.size; ++i)
        {
            result += other.arr[i];
        }

        return result;

    }

    bool operator==(const DynArray& other)
    {
        if (this->size != other.size)
            return false;

        for(int i = 0; i < this->size; ++i)
        {
            if(this->arr[i] != other.arr[i])
            {
                return false;
            } 
        }

        return true;
    }

    ~DynArray()
    {
        std::cout << "DESTRUCTOR!\n";
        delete arr;
    }

};

template<typename T>
std::ostream& operator<<(std::ostream& out, const DynArray<T>& da)
{
    out << "{";
    for (int i = 0; i < da.size; ++i)
    {
        std::cout << da.arr[i] << " ";
    }
    out << "}";

    return out;
}

void printSize(DynArray<int> arr)
{
    std::cout << "size = " << arr.size;
    arr += 30;
    std::cout << arr;
}


DynArray<int> createSuperArray()
{
    DynArray<int> superArray;
    superArray += 0; superArray += 0; superArray += 0;

    return superArray;
}

int main()
{

    DynArray<int> a,b,c;
    DynArray<int> newArrayCopyOfOtherArray(a);

    a += 10;
    a += 20;

    b = a;
    std::cout << a;
    std::cout << b;

    a.arr[0] = 40;
    std::cout << a;
    std::cout << b;

    DynArray<double> *parray = new DynArray<double>[10];
    delete []parray;
    //DynArray<double> arrays[10];

/*
    DynArray<int> a,b;
    DynArray<int> c(10);

    DynArray<double> *parray = new DynArray<double>[10];

    std::cout << *parray;

    
    std::cout << a;
    a += 1;
    a += 2;
    b += 3;
    b += 4;

    std::cout << a;

    a = b + b; //{1,2,3,4,3,4}

    std::cout << a;

    if (a == b)
    {
        std::cout << "Yes!";
    }
   */

    //a = b;
     
}