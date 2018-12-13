#include "hmap.cpp"
#include <iostream>
#include <cassert>


size_t stringHash (const std::string& key, size_t tablesize)
{

  size_t hcode = 0;
  for (size_t i = 0; i < key.size(); i++)
  {
    hcode += key[i];
  }
  return hcode % tablesize;
}

void testHashMap ()
{
  HashMap<std::string,std::string> dict(2,stringHash);

  dict.update ("cat","A small cute animal.");
  dict.update ("dog","A bigger cute animal.");
  dict.update ("piglet","A small pink animal.");

  assert (dict.hasKey ("cat"));
  assert (dict.hasKey ("dog"));
  assert (dict.hasKey ("piglet"));
  assert (!dict.hasKey ("tac"));

  assert (dict.get("cat")=="A small cute animal.");

  dict.update ("cat","A small furry animal.");
  assert (dict.get("cat")=="A small furry animal.");

  dict.remove ("cat");
  assert (!dict.hasKey ("cat"));
}

void testIndexOperator ()
{
  /*
  HashMap<std::string,std::string> dict;

  dict["cat"] = "A small cute animal.";
  dict["dog"] = "A bigger cute animal.";

  assert (dict.hasKey ("cat"));
  assert (dict.hasKey ("dog"));
  assert (!dict.hasKey ("tac"));

  assert (dict["cat"]=="A small cute animal.");

  dict["cat"] = "A small furry animal.";
  assert (dict["cat"]=="A small furry animal.");

*/
}

void testHashMapIterator ()
{
  HashMap<std::string,std::string> dict(10,stringHash);

  dict.update ("piglet","A small pink animal.");
  dict.update ("cat","A small cute animal.");
  dict.update ("tac","Forcing a collison.");
  dict.update ("dog","A bigger cute animal.");


  HashMapIterator<std::string,std::string> it = dict.begin();

  for (;it != dict.end(); ++it)
  {
      std::cout << *it
                << ":"
                << dict.get (*it)
                << std::endl;

  }

}



int main ()
{
  testHashMap();
  testHashMapIterator();


  return 0;
}
