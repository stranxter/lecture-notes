#ifndef __DFSA_
#define __DFSA_

#include <vector>
#include <map>
#include <iostream>
#include <cassert>

class DFSA
{

private:
  struct state;
  struct transitionProxy
  {
    transitionProxy (state*,char);
    void operator = (unsigned int);
    operator unsigned int () const;
  private:
    state *s;
    char symbol;
  };

  struct state
  {
    bool isFinal;
    int label;
    //table[i] -> редът на състоянието i в таблицата
    //table[i]['a'] -> целево състояние при преход от i с 'a'
    std::map<char,unsigned int> transitions;

    transitionProxy operator [] (char);
    state (DFSA *);

    DFSA *a;
  };

public:

  DFSA (unsigned int=0);

  std::vector<char> getSymbolsFrom (unsigned int);

  void setFinalState (unsigned int);
  void addTransition (unsigned int, unsigned int, char);

  state& operator [] (unsigned int);

  unsigned int toState (unsigned int, char);

  bool hasSymbol (unsigned int, char);

private:

  std::vector<state> table;
  //label[L] е пореден номер (индекс) на състоянието с
  //етикет L
  std::map<int,int> labelToIndex;
  unsigned int initialState;

  unsigned int indexof (unsigned int);
  unsigned int labelof (unsigned int);
};

std::vector<char> DFSA::getSymbolsFrom (unsigned int labelFrom)
{
  unsigned int indexFrom = indexof (labelFrom);

  std::map<char,unsigned int> &transations
     = table[indexFrom].transitions;

  std::vector<char> result;

  for (std::map<char, unsigned int>::iterator it = transations.begin();
       it != transations.end();
       it++)
   {
     result.push_back (it->first);
   }

   return result;
}



DFSA::DFSA (unsigned int _initialState)
{
  initialState = indexof(_initialState);
}


DFSA::transitionProxy::operator unsigned int () const
{
  assert (s->transitions.count (symbol) > 0);
  return s->a->labelof(s->transitions[symbol]);
}

DFSA::transitionProxy::transitionProxy (state *_s, char _symbol)
    :s(_s),symbol(_symbol){}

void DFSA::transitionProxy::operator = (unsigned int label)
{
  s->a->addTransition (s->label,label,symbol);
}

DFSA::state& DFSA::operator [] (unsigned int label)
{
  return table[indexof(label)];
}


DFSA::state::state(DFSA *_a):a(_a),isFinal (false){}

DFSA::transitionProxy DFSA::state::operator [] (char symbol)
{
  return transitionProxy (this,symbol);
}

void DFSA::setFinalState (unsigned int s)
{
  unsigned ix = indexof (s);

  table[ix].isFinal = true;
}

unsigned int DFSA::labelof (unsigned int ix)
{
  assert (ix < table.size());
  return table[ix].label;
}


unsigned int DFSA::indexof (unsigned int L)
{
  if (labelToIndex.count (L) == 0)
  {

    //в този момент постъпва ново състояние за автомата
    labelToIndex[L] = table.size();
    state newState (this);
    newState.label = L;
    table.push_back (newState);

  }
  return labelToIndex[L];
}

void DFSA::addTransition (unsigned int from,
                          unsigned int to,
                          char symbol)
{
    unsigned int ixfrom = indexof (from);
    unsigned int ixto = indexof (to);
    table[ixfrom].transitions[symbol] = ixto;

#ifdef _debug
    std::cerr << "Adding "
              << from
              << "("
              << ixfrom
              << "):"
              << symbol
              << ":"
              << to
              << "("
              << ixto
              << ")"
              << std::endl;
#endif
}

unsigned int DFSA::toState (unsigned int from, char s)
{
  return labelof (table[from].transitions[s]);
}

bool DFSA::hasSymbol (unsigned int label, char symbol)
{
  if (labelToIndex.count(label) == 0)
    return false;
  return table[indexof(label)].transitions.count (symbol) > 0;
}



#endif
