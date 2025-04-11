template <typename T>
struct Range
{
    T a;
    T b;

    using value_type=T;

    class Iterator
    {
       public:
       Iterator(const T&);
       Iterator& operator++(); 
       T operator*();
       bool operator!=(const Iterator&) const;
       private:
       T current;

    };

    Iterator begin();
    Iterator end();
};