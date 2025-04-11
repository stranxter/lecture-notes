#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "list.cpp"

#include <string>
#include <vector>
#include <set>

#include "range.cpp"
#include "inputstream.cpp"


template <typename Container>
void print(Container c)
{
   std::cout << "{";
   for(typename Container::value_type i : c)
   {
      std::cout << i << " ";
   }

   std::cout << "}" << std::endl;

}

int main()
{

   std::string s = "Hello world!", s1 = s, s2;

   s2 = s + s1;
   if(s2 < s){}

   std::vector<int> v = {1,2,3,4,5};
   std::vector<char> s3 = {'h','e','l','l','o'};

   v.push_back(6);

   for(int i = 0; i < v.size(); ++i)
   {
      std::cout << v[i];
   }

   for(int i = 0; i < s.size(); ++i)
   {
      std::cout << s[i];
   }

   std::set<int> set;

   set.insert(0);
   set.insert(1);
   set.insert(2);

   for(int element : v)
   {
      std::cout << element;
   }

   for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
   {
      std::cout << *i;
   }

   List<int> mylist;
   mylist.push(0);
   mylist.push(1);
   mylist.push(3);

   
   std::cout << "My list iteration 1:\n";

   for(int element : mylist)
   {
      std::cout << element;
   }

   std::cout << "My list iteration 2:\n";

   for(ListIterator<int> i = mylist.begin(); i != mylist.end(); ++i)
   {
      std::cout << *i;
   }

   print(mylist);
   print(v);
   print(s);

   std::vector<std::string> strings = {"Hello", "World", "Have", "a", "nice", "day!"};
   print(strings);


   print(Range<int>{1,10});


   print(InputStream<int>{12});


}
