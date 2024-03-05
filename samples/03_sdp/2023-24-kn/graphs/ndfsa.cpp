#include "ndfsa.h"


void printDotty (std::ostream &out, const NDFSA &a)
{
    //"100 -> 200[label=\"a\"]"

    out << "Digraph G{\n";

    for(NDFSA::State fromState : a.getStates())
    {
        for (NDFSA::StateTransitions t : a.transitions(fromState))
        {
            for(NDFSA::State toState : t.second)
            {
                out << fromState
                    << "->"
                    << toState
                    << "[label=\""
                    << t.first
                    << "\"]\n";
            }
        }

        if(a.isFinal(fromState))
        {
            out<<fromState<<"[shape=\"doublecircle\"]\n";
        }
    }

    out << "}";

}

void NDFSA::setStart(State s)
{
    starts.insert(s);
}

void NDFSA::setFinal(State s)
{
    finals.insert(s);
}

void NDFSA::addTransition(State from,char s,State to)
{
    a[from][s].insert(to);
}

NDFSA::States const& NDFSA::getStates() const
{
    return states;
}

NDFSA::States const& NDFSA::getFinals() const
{
    return finals;
}
NDFSA::States const& NDFSA::getStarts() const
{
    return starts;
}

NDFSA::Transitions NDFSA::emptyTransitions;
NDFSA::States NDFSA::emptyStates;


NDFSA::Transitions const& NDFSA::transitions (State s) const
{
    if(a.count(s) > 0)
    {
        return a.at(s);
    }

    return emptyTransitions;   
}
    
bool NDFSA::isFinal(State s) const
{
    return finals.count(s) > 0;
}


void NDFSA::clear()
{
    starts.clear();
    finals.clear();
    states.clear();
    a.clear();
}

void NDFSA::addState(State s)
{
    states.insert(s);
}


std::istream& operator>>(std::istream &in, NDFSA &a)
{
    int nStates;
    in >> nStates;
    for(int i = 0; i < nStates; ++i)
    {
        NDFSA::State state;
        in >> state;
        a.addState(state);
    }
    in >> nStates;
    for(int i = 0; i < nStates; ++i)
    {
        NDFSA::State state;
        in >> state;
        a.setStart(state);
    }
    in >> nStates;
    for(int i = 0; i < nStates; ++i)
    {
        NDFSA::State state;
        in >> state;
        a.setFinal(state);
    }

    int nTranstions;
    in >> nTranstions;

    for(int i = 0; i < nTranstions; ++i)
    {
        NDFSA::State from, to;
        char c;

        in >> from >> c >> to;
        a.addTransition(from,c,to);

    }

    return in;
}

NDFSA::States const& NDFSA::delta(NDFSA::State s, char c) const
{
    if (a.count(s) < 1 || a.at(s).count(c) < 1)
    {
        return emptyStates;
    }
    return a.at(s).at(c); //a[s][c]
}

bool NDFSA::accept(const std::string &s) const
{
    NDFSA::States current = getStarts();

    for(char c: s)
    {
        NDFSA::States next;
        for(NDFSA::State state : current)
        {
            for(State toState : delta(state,c))
            {
                next.insert(toState);   
            }
        }
        current = std::move(next);
    }

    for(NDFSA::State state : current)
    {
        if(isFinal(state))
        {
            return true;
        }
    }
    return false;
}

