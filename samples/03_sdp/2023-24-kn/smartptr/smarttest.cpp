#include <iostream>
#include "smartptr.cpp"


struct box
{

    box(int _data, myptr<box*> _tail):data(_data),next(_tail)
    {
        std::cout << "+[" << data << "]";
    }

    ~box()
    {
        std::cout << "-[" << data << "]";
    }

    int data;
    myptr<box*> next; //box* next
};

myptr<box*> cons(int x, myptr<box*> tail)
{
    std::cout << "\ncons:\n";
    return myptr<box*> (new box(x,tail));
}

myptr<box*>make_list()
{
    std::cout << "\nmake_list:\n";
    return cons(1,cons(2,cons(3,nullptr))); //myptr<box*>(nullptr)
}

myptr<box*> use_list()
{
    std::cout<<"\nassigning list:\n";
    myptr<box*> list = make_list();
    std::cout<<"\nassigning list2:\n";
    myptr<box*> list2 = cons(5,list);
    std::cout<<"\nassigning list3:\n";
    myptr<box*> list3 = cons(6,list);

    //....

    std::cout<<"\nreturning from use_list:\n";
    return list3;

}


int main()
{
    std::cout<<"\ncalling use_list:\n";
    myptr<box*> mainlist = use_list();
    std::cout<<"\nafter use_list:\n";
    //printlist
    

}