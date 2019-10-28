#ifndef __SEQUENCE_HPP
#define __SEQUENCE_HPP

template <class Iterator>
class Sequence
{
    public:
        Sequence (const Iterator &b, 
                  const Iterator &e):_begin(b), _end (e){}

        Iterator begin()
        {
            return _begin;
        }
        Iterator end()
        {
            return _end;
        }
    private:
        Iterator _begin;
        Iterator _end;
};

#endif
