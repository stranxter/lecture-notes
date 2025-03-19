#include <iostream>

unsigned charCount(char ch, const char* str) {
    if (str == nullptr) {
        return 0;
    }
    unsigned cnt = 0;
    while (*str != '\0') {
        if (*str == ch) {
            cnt++;
        }
        str++;
    }
    return cnt;
}

template<typename T>
class DynArray 
{ 
private:
    unsigned size = 0;
    T* first = nullptr;

    void copyFrom(const DynArray& other) {
        size = other.size;

        first = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            first[i] = other.first[i];
        }
    }

    void free() {
        delete[] first;
        first = nullptr;
    }

public:
    DynArray() = default;

    explicit DynArray(unsigned n)
    {
        first = new T[n] {};
        size = n;
    }

    DynArray(const char* str) // ??????????? ???????????
    {
        if (str == nullptr) {
            return;
        }
        size = charCount(' ', str) + 1;
        first = new T[size];
        unsigned idx = 0;

        while (*str != '\0') {
            unsigned temp = 0;
            while (*str != ' ' && *str != '\0') {
                temp *= 10;
                temp += (*str - '0');
                str++;
            }
            first[idx] = temp;
            idx++;
            str++;
        }
    }

    DynArray(const DynArray& other) {
        copyFrom(other);
    }

    T& operator[](unsigned i)
    {
        return first[i];
    }

    DynArray& operator=(const DynArray& other) {
        if (this == &other) {
            free();
            copyFrom(other);
        }

        return *this;
    }

    ~DynArray() {
        free();
    }

    void print() const
    //DynArray* this
    {
        std::cout << "{";
        for(int i = 0; i < size; ++i)
        {
            std::cout << first[i] << " ";  //<=> *(a.first+i)
        }
        std::cout << "}:" << size << std::endl;
    }

    DynArray& operator+=(T x)
    {
        T *newBuffer = new T[size+1];
    
        for(int i = 0; i < size; ++i)
        {
            newBuffer[i] = first[i];
        }
    
        newBuffer[size] = x;
    
        ++size;
    
        delete[] first;
        first = newBuffer;
        return *this;
    }

    DynArray operator+(const DynArray& b)
    {
        DynArray result;
        result.first = new T [size + b.size];
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

    bool member(T x) const
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
       
    friend bool operator==(const DynArray& a, const DynArray& b);

};

template <typename T>
bool operator==(const DynArray<T>& a, const DynArray<T>& b)
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
    DynArray<int> arr1("13 7 0");

    DynArray<int> arr2(arr1);

    DynArray<int> arr[2]; 

    arr1.print();
    arr2.print();
    (arr1 += 10) += 20;

    arr1.print();
    arr2.print();

    std::cout << arr1[4]+arr2[5] << std::endl;

    arr1[4] = 0;

}