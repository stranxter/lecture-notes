template <typename T>
struct box
{
    T data;
    box *next;
};

template <typename T>
class List
{
    public:
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

    private:
    box<T> *first = nullptr;

    box<T>* pointerTo(unsigned i) const;
    void copyfrom(box<T>*);
};