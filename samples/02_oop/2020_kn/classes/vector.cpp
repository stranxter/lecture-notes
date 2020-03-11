#include <cstdlib>

class IntVector
{
    public:
    //1 2 3
    //10 1 2 3 4 5
    //
    //4
    int *data;
    size_t size;

    IntVector ()
    {
        data = nullptr;
        size = 0;
    }

    void to_end (int x)
    {
        
        //[1,2] + 3
        
//-----> data = [1 2]
        int *bigger_buffer = new int [size+1];
//-----> bigger_buffer ------->  [X X X]
        for (size_t i = 0; i < size; i++)
        {
            bigger_buffer[i] = data[i];
        }
//-----> bigger_buffer ------->  [1 2 X]
        bigger_buffer[size] = x;
//-----> bigger_buffer ------->  [1 2 3]
        ++size;

//-----> data = *1 2*

        int *save = new int[size];

        delete data;
        data = bigger_buffer;

    }

    void push (int x);

    IntVector operator + (IntVector);

    void print();

};

int main ()
{
    IntVector v;

    v.to_end (1);
    v.to_end (2);
    v.to_end (3);
    v.push (4);

    v.print (); //4 1 2 3
    (v+v).print();
}