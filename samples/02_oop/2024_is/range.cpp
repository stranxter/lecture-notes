#include "range.h"


IntRange::Iterator::Iterator(int _start, 
                             int _finish,
                             std::function<bool(int)> _filter):
                             current(_start),finish(_finish),filter(_filter){}

int IntRange::Iterator::operator*() const
{
    return current;
}

typename IntRange::Iterator& IntRange::Iterator::operator++()
{
    do
        ++current;  
    while(current < finish && !filter(current));
    return *this;
}

bool IntRange::Iterator::operator!=(const typename IntRange::Iterator &other) const
{
    return current != other.current;
}

typename IntRange::Iterator IntRange::begin()
{
    return IntRange::Iterator(start, finish, filter);
}

typename IntRange::Iterator IntRange::end()
{
    return IntRange::Iterator(finish+1, finish, filter);
}
