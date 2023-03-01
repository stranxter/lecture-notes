#include <iostream>
#include <string>

template <typename R>
using Operator = R(*)(R,R);

template <typename E, typename R>
using F = R(*)(E);


struct Student
{
  std::string name;
  double grade;
};

template <typename E, typename R>
R reduce(E arr[],
         unsigned int n,
         R null_val,
         Operator<R> op,
         F<E,R> f)
{
       
  R accum = null_val;
  for (int i = 0; i < n; ++ i)
  {
      //accum = accum + a[i];
      accum = op(accum,f(arr[i]));
  }
 
  return accum;
}

template <typename E>
E plus(E a, E b)
{
    return a + b;
}

template <typename E>
E id (E x)
{
    return x;
}

template <typename E>
E sq (E x)
{
    return x*x;
}

double getGrade(Student s)
{
    return s.grade;
}

int main()
{
 /*
E reduce(E arr[],
       unsigned int n,
       E null_val,
       E(*op)(E,E),
       E(*f)(E))
*/
  double arr[] = {1,2.5,3.5,6,5,1,7};
 
  std::cout << reduce<double,double>(arr,
                                     7,
                                     0,
                                     plus<double>,
                                     sq<double>) << std::endl;
 
  Student students[] = {{"Kalin",4.50},{"Stanislav", 6.00}};
 
  std::cout << reduce<Student,double>(students,
                                      2,
                                      0,
                                      plus<double>,
                                      getGrade) << std::endl;
                                     
    return 0;                    
 
}