#ifndef __FILTERITERATOR_HPP
#define __FILTERITERATOR_HPP

template <class Element>
using filterfn = bool (*)(const Element &);

template <class Iterator, class Element>
class FilterIterator
{
    public:
        FilterIterator(const Iterator &_or, 
                       const Iterator &_end,
                       filterfn<Element> _p) : original(_or), end (_end), p(_p) 
        {
            findNext();
        }

        Element operator *()
        {
            return *original;
        }

        FilterIterator<Iterator,Element>& operator ++()
        {
            ++original;
            findNext();
            return *this;
        };
        bool operator==(FilterIterator<Iterator, Element> &it)
        {
            return original == it.original;
        }
        bool operator!=(FilterIterator<Iterator, Element> &it)
        {
            return original != it.original;
        }
    
    private:
        Iterator original;
        Iterator end;
        filterfn<Element> p;

        void findNext ()
        {
            while (original != end && !p(*original))
            {
                ++original;
            }
        }
};

#endif
