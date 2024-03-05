#include <iostream>

template <typename T>
class DynArray
{
    public:

    T *arr;
    size_t size;

    void init()
    {
        arr = new T[0];
        size = 0;
    }

    DynArray& operator+=(T x)
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

    DynArray operator+(DynArray other) const
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

    bool operator==(DynArray other)
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

};

template<typename T>
std::ostream& operator<<(std::ostream& out, DynArray<T> da)
{
    out << "{";
    for (int i = 0; i < da.size; ++i)
    {
        std::cout << da.arr[i] << " ";
    }
    out << "}";

    return out;
}


int main()
{
    DynArray<int> a,b;

    a.init(); b.init();

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


    //a = b;
     
}