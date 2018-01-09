#include <cassert>
#include <iostream>
#include "fsa.cpp"
#include <string>

DFSA makeTestA ()
{
  DFSA a;

  a.setFinalState (1000);

  a[0]['a'] = 1000;
  a[0]['b'] = 500;
  a[0]['c'] = 5000;

  a[500]['u'] = 5000;
  a[5000]['v'] = 1000;

  return a;
}

void testSimple ()
{

  DFSA a = makeTestA();

  assert (a[0]['a'] == 1000);
  assert (a[0]['b'] == 500);
  assert (a[0]['c'] == 5000);

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

std::string findLongestWord (const DFSA& a, uint fromState)
{

  std::string longest = "";

  for (char symbol : a[fromState])
  {
    std::string found = symbol + findLongestWord (a,a[fromState][symbol]);
    if (found.size () > longest.size())
    {
      longest = found;
    }
  }


  return longest;

}

void longestWord ()
{
  DFSA a = makeTestA();

  std::cout << "Longest word = " << findLongestWord (a,0) << std::endl;
}

int main ()
{
  testSimple();
  dottyPrint (std::cerr);
  longestWord();
  return 0;
}
