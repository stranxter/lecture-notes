#pragma once
#include <iostream>
#include <map>
#include <set>

class NDFSA
{

    public:
    
    using State = int;
    using States = std::set<State>;
    using StateTransitions = std::pair<char,States>;
    using Transitions = std::map<char,States>;

    void clear();

    void setStart(State);
    void setFinal(State);
    void addTransition(State,char,State);
    void addState(State);

    States const& getStates() const;
    States const& getFinals() const;
    States const& getStarts() const;

    Transitions const& transitions (State) const;
    bool isFinal(State s) const;

    private:
    std::map<int,Transitions>a;
    States states;
    States finals;
    States starts;

    static Transitions emptyTransitions;

};

std::istream& operator>>(std::istream&, NDFSA&);

void printDotty (std::ostream&, const NDFSA&);