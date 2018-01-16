#include <cassert>
#include <iostream>
#include "fsa.cpp"
#include <set>
#include <string>
#include <queue>
#include <limits.h>

DFSA makeTestA ()
{
  DFSA a;

  a.setFinalState (1000);

  a[0]['a'] = 1000;
  a[0]['b'] = 500;
//  a[0]['c'] = 5000;

  a[500]['u'] = 5000;
  a[5000]['v'] = 1000;
  a[1000]['x'] = 8;
  a[8]['x'] = 9;

  a[5000]['x'] = 8;
  a[1000]['c'] = 0;

  return a;
}

void testSimple ()
{

  DFSA a = makeTestA();

  assert (a[0]['a'] == 1000);
  assert (a[0]['b'] == 500);
  //assert (a[0]['c'] == 5000);

  assert (a.hasSymbol (0,'a'));
  assert (!a.hasSymbol (0,'z'));

  for (char c : a[0])
  {
    std::cout << "Transition from 0 with symbol " << c << std::endl;
  }
  std::cout << std::endl;

  for (int label : a)
  {
    std::cout << "state = " << label << std::endl;

  }
}

void dottyPrint (std::ostream &out)
{

  DFSA a = makeTestA();

  out << "digraph G{" << std::endl;

  for (int state : a)
  {
    for (char symbol : a[state])
    {
      out << "   "
          << state
          << "->"
          << a[state][symbol]
          << "[label=\""
          << symbol
          << "\"];\n";
    }

    if (a[state].final())
    {
      out << "   " << state << "[shape=\"doublecircle\"];\n";
    }
  }


  out << "}" << std::endl;

}

/*
Result:
  nullptr: няма думи през това състояние
  != nullptr: указател към най-дългата дума през това с-е
*/

std::string* findLongestWord (const DFSA& a,
                              uint fromState,
                              std::set<uint> visited)
{

  if (visited.count(fromState) > 0)
  {
    return nullptr;
  }
  visited.insert (fromState);

  std::string* longest = nullptr;

  for (char symbol : a[fromState])
  {
    std::string* found = findLongestWord (a,a[fromState][symbol],visited);
    if (found != nullptr)
    {
      *found = symbol + *found;
    }

    std::string *tmp;
    if ((longest == nullptr && found != nullptr) ||
        (found != nullptr && found->size () > longest->size()))
    {
      tmp = longest;
      longest = found;
      delete tmp;//mоже да nullptr
    } else {
      delete found;//mоже да nullptr
    }
  }

  if (longest != nullptr)
  {
    return longest;
  }

  if (a[fromState].final())
  {
    return new std::string;
  } else {
    return nullptr;
  }

}

#define SENTINEL INT_MAX

bool hasKWords (const DFSA& a, uint k)
{
  std::queue<uint> q;

  q.push (0);
  q.push (SENTINEL);

  uint level = 0;

  while (!q.empty() && level < k)
  {
    uint state = q.front(); q.pop();

    if (state != SENTINEL)
    {
      for (char symbol : a[state])
      {
        //  std::cout << "*" << state << ":" << symbol << "\n";
        q.push (a[state][symbol]);
      }

    } else if (!q.empty()){
      level++;
      q.push (SENTINEL);
    }
  }

  while (!q.empty())
  {
    uint state = q.front(); q.pop();
    if (state != SENTINEL && a[state].final())
    {
      return true;
    }
  }

  return false;

}


void longestWord ()
{
  DFSA a = makeTestA();

  std::set<uint> v;
  std::string *lw = findLongestWord (a,0,v);
  std::cout << "Longest word = " << *lw << std::endl;
  delete lw;
}

void printLanguage (const DFSA& a, uint k)
{
  std::vector<std::pair<uint,std::string>> q;

  q.push_back (std::make_pair(0,""));
  q.push_back (std::make_pair(SENTINEL,""));

  uint level = 0;

  while (!q.empty() && level < k)
  {
    std::pair<uint,std::string> qel = q[0]; q.erase(q.begin());

    const uint &state = qel.first;
    const std::string &word = qel.second;

    if (state != SENTINEL)
    {
      for (char symbol : a[state])
      {
        q.push_back (std::make_pair(a[state][symbol],word+symbol));
      }

    } else if (!q.empty()){
      level++;
      for (const std::pair<uint,std::string> qel : q)
      {
        if (a[qel.first].final())
        {
          std::cout << qel.second << std::endl;
        }
      }
      q.push_back (std::make_pair(SENTINEL,""));
      /*
        print level
      */
    }
  }

}

void testKWords ()
{
  DFSA a = makeTestA();


  std::cout << "4-words: " << hasKWords (a,4) << std::endl;
  std::cout << "7-words: " << hasKWords (a,7) << std::endl;
  std::cout << "11-words: " << hasKWords (a,11) << std::endl;
}

void testPrintLanguage ()
{
  DFSA a = makeTestA();
  printLanguage (a,20);

}

int main ()
{
  testSimple();
  dottyPrint (std::cerr);
  longestWord();
  testKWords();
  testPrintLanguage();
  return 0;
}
