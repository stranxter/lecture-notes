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
    bool empty();
    unsigned count();
    void push(T);
    void insertAfter(T x, unsigned i);

    T& operator[](unsigned i);

    private:
    box<T> *first = nullptr;

    box<T>* pointerTo(unsigned i);
};