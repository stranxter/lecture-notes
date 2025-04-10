template <typename T>
struct box
{
    T data;
    box *next;
};

template <typename T>
class ListIterator
{
    public:
    ListIterator(box<T>*);
    ListIterator& operator++(); 
    T& operator*();
    bool operator!=(const ListIterator<T>&);
    private:
    box<T> *current;
};

template <typename T>
class List
{
    public:

    using value_type = T;
    using iterator = ListIterator<T>;

    List();
    List(const List& other);
    bool empty() const;
    unsigned count() const;
    void push(T);
    void insertAfter(T x, unsigned i);

    T& operator[](unsigned i);
    T operator[](unsigned i) const;
    void operator=(const List& other);

    ~List();
    void clear();

    ListIterator<T> begin();
    ListIterator<T> end();

    private:
    box<T> *first = nullptr;

    box<T>* pointerTo(unsigned i) const;
    void copyfrom(box<T>*);
};