#include <iostream>
#include <string>
#include <functional>

template <typename ResT,typename ElemT>
ResT reduce (ElemT arr[], 
             int arrsize, 
             std::function<ResT(ResT,ElemT)> f, 
             ResT null_val)
{
  ResT result = null_val;

  for (int i = 0; i < arrsize; i++)
    result = f (result,arr[i]);

  return result;
}

int count1 (int counter, std::string s)
{
    if (s.size() > 0 && s[0] >= 'a' && s[0] <= 'z')
    {
        return counter + 1;
    }
    return counter;
}

std::string takefirst (std::string result, std::string element)
{
    if (element.size() == 0)
    {
        return result;
    }
    return result + element[0];
}


int f (int x)
{
    return x + 1;
}

int g (int x)
{
    return x + 2;
}

class summator
{
    public:

    summator ():i(0){}

    int operator() (int x)
    {
        i += x;
        return i;
    }

    private:
    int i;
};


int main ()
{

    summator t;
    t(1);
    t(2);
    t(7);
    t(10);

    int (*fp) (int);    

    fp = f;
    fp(2);
    fp = g;
    fp(2);

    std::string strings[] = {"Hello", " ", "World", ", ", "have", " ", "a", "nice", "day"};

    std::cout << reduce<int, std::string> (strings, 9, count1 ,0) << std::endl;

    std::cout << reduce<std::string,std::string> (strings, 9, takefirst, "");

    int a[] = {1,2,3,4,5};

    std::cout << reduce<int,int> (a,5,[](int x, int y)->int{return x+y;},0);   

    return 0;
}