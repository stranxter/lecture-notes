#include <iostream>
#include <assert.h>
#include <cstring>


using namespace std;


void map (int arr[], size_t size, int (*f)(int))
{
  for (size_t c = 0; c < size; c++)
  {
    arr[c] = f(arr[c]);
  }
}


class CharSet
{
private:
  bool contents[26];

public:
  bool empty () //!!!
  {
    for (int i = 0; i < 26; i++)
      if (contents[i])
        return false;
    return true;
  }

  void makeempty()
  {
    //map (contents,26,[](bool b){return false});
    for (int count = 0; count < 26; count ++)
    {
      contents[count] = false;
    }
  }

  CharSet ()
  {
    makeempty();
  }



  CharSet (char c)
  {
    makeempty();
    addChar (c);
  }

  void addChar (char c)
  {
    assert (c >= 'a' && c <= 'z');
    contents[c-'a'] = true;      
  }

  bool member (char c)
  {
    return c >= 'a' && 
           c <= 'z' && 
           contents[c-'a'] == true;
  }

  CharSet (const char *s)
  {
    makeempty();
    int strsize = strlen(s);
    for (int count = 0; count < strsize; count++)
    {
      addChar(s[count]);   
    }
  }

  CharSet operator | (CharSet other)
  {
    CharSet result;
    for (int i = 0; i < 26; i++)
      result.contents[i] = contents[i] || 
                           other.contents[i];
    return result;
  }

  CharSet operator & (CharSet other)
  {
    CharSet result;
    for (int i = 0; i < 26; i++)
      result.contents[i] = contents[i] && 
                           other.contents[i];
    return result;
  }

  void print ()
  {
    cout << "{";
    for (char symbol = 'a'; symbol <= 'z'; symbol++)
    {
      if (member(symbol))
        cout << symbol << " ";
    }
    cout << "}" << endl;
  }

};

int main ()
{
  CharSet s1="abcddd",
          s2="adz";


  CharSet s3 = s1 | s2,
          s4 = s1 & s2;

  s3.print();
  s4.print();

}