#include <iostream>
#include <fstream>


template <typename T>
class DynArray
{
    private:
    T *arr;
    unsigned int size;

    public:

    int getSize() const
    {
        return size;
    }
    DynArray()
    {
        std::cout << "DynArray()\n";
        init();
    }

    DynArray(int i)
    {
        std::cout << "DynArray(int)\n";
        this->size = i;
        this->arr = new T[i];
    }

    DynArray(int ia[], int size)
    {
        std::cout << "DynArray(ia[])\n";        
        this->size = size;
        this->arr = new T[size];
        for(int count=0; count <  size; ++count)
        {
            this->arr[count] = ia[count];
        }
    }
   
    DynArray(const DynArray<T>& other)
    {

        std::cout << "DynArray(DynArray&)\n";
        copy(other);
    }

    void copy(const DynArray<T>& other)
    {
        this->size = other.size;
        this->arr = new T[this->size];
        for(int count=0; count <  this->size; ++count)
        {
            this->arr[count] = other.arr[count];
        }    
    }

    DynArray<T>& operator=(const DynArray<T>& other)
    {
        if(this != &other)
        {
            clear();
            copy(other);
        }
        return *this;
    }

    void init()
    {
        this->size = 0;
        this->arr = nullptr;    
    }

    void push_back(const T& x)
    {
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 3
            }
        */
    T* tmp = new T[this->size+1];
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 3
            }
            tmp ----------------> [13134] [756] [12313] [464745]
        */
    for(int i = 0; i < this->size; ++i)
    {
        tmp[i] = this->arr[i];
    }
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 3
            }
            tmp ----------------> [1] [2] [3] [464745]
        */
    tmp[this->size] = x;
    this->size++;
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 4
            }
            tmp ----------------> [1] [2] [3] [x]
        */
        delete []this->arr;
        this->arr = tmp;
        /*
            a:{
                arr --------\ ~~~~~~~~~~~~~~~~~~~
                size: 4      \
            }              |
            tmp ----------------> [1] [2] [3] [x]
        */
    }

    //c=a+b
    DynArray<T> operator+(const DynArray<T>& b) const
    {
        DynArray<T> result;
        result.init();
        (result += *this) += b;

        return result;
    }

    DynArray<T>& operator+=(const T& x)
    {
        push_back(x);
        return *this;
    }

    //(a += b)
    DynArray<T>& operator+=(const DynArray<T>& b)
    {
        /*
            a:{
                arr -------------> [1] [2] [3] [4] [5] [+1] [+2] [+3]
                size: 5
            }
            b:{
                arr -------------> [1] [2] [3]
                size: 3
            }
        */

        T* tmp = new T[this->size+b.size];
        for(int i = 0; i < this->size; ++i)
        {
            tmp[i] = this->arr[i];
        }
        for(int i = this->size; i < this->size+b.size; ++i)
        {
            tmp[i] = b.arr[i-this->size];
        }

        this->size = this->size + b.size;
        delete []this->arr;
        this->arr = tmp;

        return *this;
    }

    bool operator!=(const DynArray<T>& b) const
    {
        return !(*this == b);
    }
    bool operator==(const DynArray<T>& b) const
    {
        if(this->size != b.size)
        {
            return false;
        }
        for(int i = 0; i < this->size; ++i)
        {
            if(this->arr[i] != b.arr[i])
            {
                return false;
            }
        }
        return true;
    }

    T operator[](unsigned int i) const
    {
        return this->arr[i];
    }

    T& operator[](unsigned int i)
    {
        return this->arr[i];
    }

    void clear()
    {
        delete arr;
    }

    ~DynArray()
    {
        clear();
        std::cout << "Game over!\n";
    }

};

template<typename T>
std::ostream& operator<<(std::ostream& out,const DynArray<T>& arr)
{   //DynArray<T>* this;
    out << "{";
    for(int i = 0; i < arr.getSize(); ++i)
    {
        out << arr[i] << " ";
    }
    out << "}";

    return out;
}

/*
    T& operator[](unsigned int i) const
    {
        return this->arr[i];
    }
*/
void set0(DynArray<int>& dai)
{
    for(int i = 0; i < dai.getSize(); ++i)
    {
        dai[i]= 0;
    }
}

DynArray<int> makeZeros(unsigned int n)
{
    DynArray<int> result(n);
    for(int i = 0; i < n; ++i)
    {
        result[i] = 0;
    }
    return result;
}

int main()
{

    int ia[] = {1,2,3,4,5};
    DynArray<int> a2(ia,5); 
    std::cout << "a2=" << a2 << std::endl;

    set0(a2);
    std::cout << "a2=" << a2 << std::endl;

    DynArray<int> *matrix = new DynArray<int>[3];

    delete []matrix;

    std::cout << makeZeros(20) << std::endl;

    DynArray<int> a;

    DynArray<int> a1(5);

    set0(a2);
    std::cout << "a2=" << a2 << std::endl;

    DynArray<int> a3(a2);
    std::cout << "a3=" << a3 << std::endl;
    a3[2] = 10;

    std::cout << "a2=" << a2 << std::endl;
    std::cout << "a3=" << a3 << std::endl;

    a2+=10;
    std::cout << "a2=" << a2 << std::endl;
    std::cout << "a3=" << a3 << std::endl;

    a3=a2;
    a2[0]=400;
    std::cout << "======ASSIGNMENT=====\n";
    std::cout << "a2=" << a2 << std::endl;
    std::cout << "a3=" << a3 << std::endl;

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);

    //a.arr = 0;

    std::cout << a;

    //remove_element(a,3);
    //printArray(a);

    DynArray<int> b;

    ((b+=10)+=20)+=30;
    int x = 0, y =5;

    std::cout << ((a += b) += 30);

    std::cout << (a == b) << std::endl;
    std::cout << (a == a) << std::endl;

    DynArray<int> c;
    c.push_back(10);
    c.push_back(20);
    c.push_back(30);
    std::cout << b;
    std::cout << c;
    std::cout << (b == c) << std::endl;

    c.push_back(10);
    std::cout << (b == c) << std::endl;

    DynArray<int> z;

    return 0;

    z = a + b;

    std::cout << "a=" << a << " thank you and good bye!\n";
    std::cout << b;
    std::cout << z;

    std::ofstream f("kalin.txt");

    f << z;

    std::cout << "\n\n\n\n\n";

    DynArray<DynArray<int>> m;
    std::cout << (((m+=a)+=b)+=c);

}