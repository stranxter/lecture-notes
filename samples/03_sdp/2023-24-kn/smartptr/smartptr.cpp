#include "smartptr.h"


template <typename Ptr>
myptr<Ptr>::myptr(Ptr _mem)
{
    ref = new ref_counter{_mem,1};
}
template <typename Ptr>
myptr<Ptr>::myptr(const myptr &other)
{
    ref = other.ref;
    ++ref->counter;   
}

template <typename Ptr>
myptr<Ptr>& myptr<Ptr>::operator=(const myptr<Ptr> &other)
{
    if(this != &other)
    {
        release_ref();
        ref = other.ref;
        ++ref->counter; //новата динамична памет, която сочим
    }
    return *this;
}

template <typename Ptr>
void myptr<Ptr>::release_ref()
{
    --ref->counter; 
    if(ref->counter == 0)
    {
        if(ref->memory != nullptr)
        {
            delete ref->memory;
        }
        delete ref;
    }

}

template <typename Ptr>
myptr<Ptr>::~myptr()
{
    release_ref();
}
