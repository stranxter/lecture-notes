#ifndef __SEQUENCE_HPP
#define __SEQUENCE_HPP

template <class Iterator>
class Sequence
{
    public:
    Sequence (Iterator b, Iterator e):_begin(b),_end(e){}

    Iterator begin () {return _begin;}
    Iterator end() { return _end; }

    size_t size ()
    {
        Iterator current = _begin;
        size_t count = 0;
        while (current != _end)
        {
            ++current;
            count++;
        }
        return count;
    }

    private:
    Iterator _begin;
    Iterator _end;
};

#endif
