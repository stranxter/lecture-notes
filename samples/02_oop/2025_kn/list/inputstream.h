template <typename T>
struct InputStream //чете поредни елементи от стандартния вход
                   //до достигане на определен брой
{

    using value_type = T;

    class Iterator
    {
        public:
        Iterator(unsigned);
        T operator*();
        Iterator& operator++();
        bool operator!=(const Iterator&);
        private:
        unsigned remaining;
        bool hasbuffered = false;
        T buffered;
    };

    Iterator begin();
    Iterator end();

    InputStream(unsigned);

    private:
    unsigned count;
};