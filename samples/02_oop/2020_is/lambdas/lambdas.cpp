#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <cmath>

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

template <typename ResT,typename ElemT>
ResT reduce (std::vector<ElemT> arr,
             std::function<ResT(ResT,ElemT)> f, 
             ResT null_val)
{
  ResT result = null_val;

  for (int i = 0; i < arr.size(); i++)
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

std::function<double(double)> squared (std::function<double(double)> f) //f=f2
{
    return [f](double x)->double{return f(x)*f(x);};
}

template<class T>
std::function<double(double)> composesimple (std::function<T(T)> f, 
                                             std::function<T(T)> g)
                                       //x->f(g(x))
{
    return [f,g](double x)->double{return f(g(x));};
}


template<class T>
std::function<double(double)> operator* (std::function<T(T)> f, 
                                         std::function<T(T)> g)
                                       //x->f(g(x))
{
    return [f,g](double x)->double{return f(g(x));};
}

std::function<double(double)> compose (std::vector<std::function<double(double)>> functions)
//functions = f1, f2, ..., fk -> f1(f2,..)
{
    /*
    return [functions](double x)->double
    {
       double result = x;
       for (int i = functions.size()-1; i >= 0; --i)
       {
           result = functions[i](result);
       }
       return result;
    };
    */
    
   /* 
   std::function<double(double)> result = [](double x)->double{return x;};

   for (int i = 0; i < functions.size(); ++i)
   {
       result = composesimple(result, functions[i]); //result . function[i]
   }

   return result;
   */

  return reduce<std::function<double(double)>,std::function<double(double)>>
            (functions,composesimple<double>,[](double x)->double{return x;});
}

std::function<double(double)> repeated(std::function<double(double)> f, unsigned int k)
{
   if (k == 0)
   {
       return [](double x)->double{return x;};
   } 

   return f * repeated (f,k-1);
}

//sdjbcdsijcbdscjuvbdsjkvbdsjvbdslvbsdlivbsdlbvlsdubvliudbvzdsbvAsde
//int->char

std::function<char(unsigned int)> toFunction (const std::string& s)
{
    return [s](unsigned int i)->char {return s[i];};
}

std::function<double(double)> pwr(double exp) //x->x^exp
{
    return [exp](double x)->double{return pow(x,exp);};
}

class power
{
    public:
    power (double e):exp(e){}

    double operator()(double x)
    {
        return pow(x,exp);
    }

    private:
    double exp;  
};

std::function<double(double)> derive (std::function<double(double)> f, double delta)
{
    return [f,delta](double x)->double{return (f(x+delta)-f(x))/delta;};

}

std::function<double(double,double)> 
    integrate (std::function<double(double)> f, double delta)
{
    
    return[](double a, double b)->double
    {
        return 0;
    };

}


int main ()
{

    power _cube(3),
          _p8(8);

    std::cout << _cube(2) << std::endl << _p8(2) << std::endl;
    
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

    std::cout << reduce<int,int> (a,5,[](int x, int y)->int{return x+y;},0) << std::endl;   

    std::function<double(double)> f1 = [](double x)->double{return x;},
                                  f2 = [](double x)->double{return 2*x;},
                                  f3 = [](double x)->double{return x*x;};

    std::function<double(double)> s = squared (f1);

    std::cout << s(2) << std::endl;

    s = squared (f2);

    std::cout << s(2) << std::endl;

    std::cout << composesimple(f2,f3)(3) << std::endl; //(f2(f3(3)))

    std::cout << compose({f1,f2,f3})(2) << std::endl;

    std::cout << repeated(f3,3)(2) << std::endl;

    std::function<char(unsigned int)> strfn = toFunction ("Hello world!");

    std::cout << strfn(4) << std::endl;

    std::function<double(double)> cube = pwr(3),
                                  p8 = pwr(8);

    std::cout << cube(2) << std::endl << p8(2) << std::endl;


    //f1,f2,f3,cube,p8


    s = derive(p8,0.001);

    std::cout << s(2) << std::endl;
                

    return 0;
}