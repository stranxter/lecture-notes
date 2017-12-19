#include <cassert>
#include "fsa.cpp"


void testSimple ()
{
  DFSA a;

  a.setFinalState (0);
  a.setFinalState (1000);
  a.setFinalState (500);

  a[0]['a'] = 1000;
  a[0]['b'] = 500;
  a[0]['c'] = 5000;

  assert (a[0]['a'] == 1000);
  assert (a[0]['b'] == 500);
  assert (a[0]['c'] == 5000);

  assert (a.hasSymbol (0,'a'));
  assert (!a.hasSymbol (0,'z'));

  std::vector<char> symbols = a.getSymbolsFrom(0);

  assert (std::find(symbols.begin(),symbols.end(),'a') != symbols.end());
  assert (std::find(symbols.begin(),symbols.end(),'z') == symbols.end());

  std::cout << "Symbols from 0:";
  for (char c : a.getSymbolsFrom(0))
  {
    std::cout << c;
  }
  std::cout << std::endl;

}


int main ()
{
  testSimple();
}
