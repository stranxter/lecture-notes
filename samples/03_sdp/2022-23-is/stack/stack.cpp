#include "stack.h"
#include <cassert>

template <typename T>
Stack<T>::Stack():count(0)
{
    head = nullptr;
}
template <typename T>
Stack<T>::Stack(const Stack &other)
{
    head = copy(other.head);
}
template <typename T>
Stack<T>& Stack<T>::operator= (const Stack &)
{
    
}
template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
T Stack<T>::top()
{
    assert(head != nullptr);
    return head->data;
}
template <typename T>
void Stack<T>::pop()
{
    assert(head != nullptr);
    Stack<T>::box *save = head;
    head = head->next;

    delete save;
    --count;
    
}
template <typename T>
void Stack<T>::push(const T &x)
{
    head = new Stack<T>::box {x,head};
    ++count;
}
template <typename T>
bool Stack<T>::empty()
{
    return head == nullptr;
}
template <typename T>
size_t Stack<T>::size()
{
    return count;
}

template <typename T>
typename Stack<T>::box* Stack<T>::copy(typename Stack<T>::box *other_head)
{   
    if (other_head == nullptr)
    {
        return nullptr;
    }

    return new Stack<T>::box {other->data,copy(head->next)};        
}

