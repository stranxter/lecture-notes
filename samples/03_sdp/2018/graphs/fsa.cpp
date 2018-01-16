#ifndef __DFSA_
#define __DFSA_

#include <vector>
#include <map>
#include <iostream>
#include <cassert>

class DFSA
{

public:
  class StatesIterator
  {
  public:

    StatesIterator (DFSA const*,bool=false);
    int operator * () const;
    StatesIterator& operator ++ ();
    bool operator != (const StatesIterator&) const;

  private:
    DFSA const *a;
    int currentStateIndex;
  };

  private:
  struct state;
  public:
  class SymbolIterator
  {
  public:

    SymbolIterator (state const*,bool=false);
    char operator * () const;
    SymbolIterator& operator ++ ();
    bool operator != (const SymbolIterator&) const;

  private:
    std::map<char,unsigned int>::const_iterator transitionsIterator;
  };


private:
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
    friend class transitionProxy;
    friend class DFSA;
    transitionProxy operator [] (char);
    unsigned int operator [] (char) const;
    SymbolIterator begin() const;
    SymbolIterator end() const;
    bool final () const;

    private:
    state (DFSA *);
    bool isFinal;
    int label;
    //table[i] -> редът на състоянието i в таблицата
    //table[i]['a'] -> целево състояние при преход от i с 'a'
    std::map<char,unsigned int> transitions;
    DFSA *a;
  };

public:

  DFSA (unsigned int=0);

  void setFinalState (unsigned int);
  void addTransition (unsigned int, unsigned int, char);

  state& operator [] (unsigned int);
  const state& operator [] (unsigned int) const;

  unsigned int toState (unsigned int, char);

  bool hasSymbol (unsigned int, char);

  StatesIterator begin() const;
  StatesIterator end() const;

private:

  std::vector<state> table;
  //label[L] е пореден номер (индекс) на състоянието с
  //етикет L
  std::map<int,int> labelToIndex;
  unsigned int initialState;

  unsigned int indexof (unsigned int);
  unsigned int indexof (unsigned int) const;
  unsigned int labelof (unsigned int) const;
};



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

const DFSA::state& DFSA::operator [] (unsigned int label) const
{
  return table[indexof(label)];
}


DFSA::state::state(DFSA *_a):a(_a),isFinal (false){}

unsigned int DFSA::state::operator [] (char symbol) const
{
  return a->labelof(transitions.at(symbol));
}


DFSA::transitionProxy DFSA::state::operator [] (char symbol)
{
  return transitionProxy (this,symbol);
}

bool DFSA::state::final () const
{
  return isFinal;
}

void DFSA::setFinalState (unsigned int s)
{
  unsigned ix = indexof (s);

  table[ix].isFinal = true;
}

unsigned int DFSA::labelof (unsigned int ix) const
{
  assert (ix < table.size());
  return table[ix].label;
}

unsigned int DFSA::indexof (unsigned int L) const
{
  assert (labelToIndex.count (L) != 0);
  return labelToIndex.at(L);
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

DFSA::StatesIterator DFSA::begin() const
{
  return DFSA::StatesIterator (this);
}

DFSA::StatesIterator DFSA::end() const
{
  return DFSA::StatesIterator (this,true);
}


DFSA::StatesIterator::StatesIterator (DFSA const *_a, bool end):a(_a)
{
  if (!end)
  {
    currentStateIndex = 0;
  } else {
    currentStateIndex = a->table.size();
  }
}
int DFSA::StatesIterator::operator * () const
{
  assert (currentStateIndex < a->table.size());
  return a->table[currentStateIndex].label;
}

DFSA::StatesIterator& DFSA::StatesIterator::operator ++ ()
{
  assert (currentStateIndex < a->table.size());
  currentStateIndex++;
  return *this;
}

bool DFSA::StatesIterator::operator != (const DFSA::StatesIterator &o) const
{
  return a != o.a || currentStateIndex != o.currentStateIndex;
}


DFSA::SymbolIterator::SymbolIterator (state const *s,bool end)
{

  if (!end)
  {
    transitionsIterator = s->transitions.begin();
  } else {
    transitionsIterator = s->transitions.end();
  }
}
char DFSA::SymbolIterator::operator * () const
{
  return transitionsIterator->first;
}
DFSA::SymbolIterator& DFSA::SymbolIterator::operator ++ ()
{
  ++transitionsIterator;
  return *this;
}
bool DFSA::SymbolIterator::operator != (const DFSA::SymbolIterator &o) const
{
  return transitionsIterator != o.transitionsIterator;
}

DFSA::SymbolIterator DFSA::state::begin() const
{
  return DFSA::SymbolIterator (this);
}
DFSA::SymbolIterator DFSA::state::end() const
{
  return DFSA::SymbolIterator (this,true);
}


#endif
