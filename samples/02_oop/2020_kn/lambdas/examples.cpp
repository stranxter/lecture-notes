#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <cmath>


template<class T>
void map (std::vector<T>& arr, std::function<void(T&)> op)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        op(arr[i]);
    }
}

void f (int& x)
{
    std::cout << x << std::endl;
    ++x;

}


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

using doublefn = std::function<double(double)>;

doublefn squared (doublefn f)
{
    return [f](double x)->double{return f(x)*f(x);};
}

template<class T>
std::function<T(T)> composesimple (std::function<T(T)> f, 
                                   std::function<T(T)> g) // \x->f(g(x))
{
    return [f,g](T x)->T{return f(g(x));};
}

doublefn compose (std::vector<doublefn> functions) //f,g,h -> f(g(h(x)))
{
    if (functions.size() == 0)
    {
        return [](double x)->double{return x;};
    }

    return [functions](double x)->double
      {
          double result = x;
          for (int i = functions.size()-1; i >= 0; --i)
          {
              result = functions[i](result);
          }
          return result;
      };
}

template<class T>
T id (T x){return x;};

doublefn compose2 (std::vector<doublefn> functions) //f,g,h -> f(g(h(x)))
{
    return reduce<doublefn,doublefn> 
        (functions,
         [](doublefn res, doublefn crr)
               ->doublefn{return [res,crr](double x)->double{return crr(res(x));};},id<double>);
}

//f^k(x) = f(f(f....(x)))
doublefn repeated (doublefn f, unsigned int k)
{
    return [f,k](double x)->double
    {
        double result = x;
        for (int i = 0; i < k; ++i)
        {
            result = f (result);
        }
        return result;        
    };
}

doublefn repeated2 (doublefn f, unsigned int k)
{
    if (k == 0)
    {
        return [](double x)->double{return x;};
    }

    return composesimple (f,repeated2(f,k-1));

    /*
    if (k == 1)
    {
        return f;
    }

    //doublefn fkm1 = repeated2(f,k-1); //f(f(f(...x...))) k-1 пъти
    return [f,k](double x)->double
    {
        //return f(fkm1(x));
        return f(repeated2(f,k-1)(x));
    };
    */
}

doublefn pwr (double exp)    //x^exp
{
    return [exp](double x)->double{return pow(x,exp);};
}

class pwr2
{
    public:
    pwr2 (double _exp):exp(_exp){};

    double operator()(double x)
    {
        return pow(x,exp);
    }

    private:
    double exp;
};


//"fiufrefilurbvuiarvbudsbvluiseVBsluevbsdkuyvgsdykuvgsdkyauvskudyvbj" i->s[i]

std::function<char(unsigned int)> strindex (const std::string& s)
{
    return [s](unsigned int i)->char{return s[i];};
}

std::function<double()> makeconstfn (double x)
{
    return [x]()->double{return x;};
}


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

    std::cout << reduce<int,int> (a,5,[](int x, int y)->int{return x+y;},0) << std::endl;   
    std::cout << reduce<int,int> (a,5,[](int x, int y)->int{return x+y*y;},0) << std::endl;   

    
    std::function<double(double)>  f1 = [](double x)->double{return x;},
                                   f2 = [](double x)->double{return 2*x;},
                                   f3 = [](double x)->double{return x*x;},
                                   s;

    s = squared(f1);

    std::cout << s(2) << std::endl;

    s = squared(f2);

    std::cout << s(2) << std::endl;

    std::cout << composesimple(f1,f2)(2) << std::endl;

    std::cout << compose({f1,f2,f3})(2) << std::endl;

    std::cout << repeated (f3,3)(2) << std::endl;

    
    doublefn cube = pwr(3);
    doublefn p8 = pwr(8);

    std::cout << strindex ("Hello Word!")(2) << std::endl;

    pwr2 p8(8);
    std::cout << p8(2) << std::endl;

    std::function<double()> const1 = makeconstfn(1);

    std::cout << const1() << std::endl;


    return 0;
}