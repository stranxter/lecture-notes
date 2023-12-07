#pragma once



template <typename Ptr>
class myptr
{

    public:

    myptr(Ptr _mem);
    myptr(const myptr&);

    myptr& operator=(const myptr&);

    ~myptr();

    private:

    struct ref_counter
    {
            Ptr memory;
            unsigned int counter;
    };

    ref_counter* ref;

    void release_ref();

};