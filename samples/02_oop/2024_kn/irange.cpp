#include "irange.h"


IRange::Iterator::Iterator(int crr, int _finish,std::function<bool(int)> _filter)
        :current(crr),finish(_finish),filter(_filter){}

typename IRange::Iterator& IRange::Iterator::operator++()
{
    do
    {
        ++current;
    } while (current < finish && !filter(current));
    
    return *this;
}

int IRange::Iterator::operator*()
{
    return current;
}

bool IRange::Iterator::operator!=(const Iterator &other)
{
    return current != other.current;
}

typename IRange::Iterator IRange::begin()
{
    return IRange::Iterator(start, finish, filter);
}

typename IRange::Iterator IRange::end()
{
    return IRange::Iterator(finish+1, finish, filter);   
}


IRange::IRange(int _start,int _finish, std::function<bool(int)> _filter):start(_start), finish(_finish), filter(_filter)
{

}
