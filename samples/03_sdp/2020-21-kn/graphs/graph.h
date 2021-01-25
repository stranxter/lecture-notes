#ifndef __GRAPH_H
#define __GRAPH_H


#include <unordered_map>
#include <map>

template <class Verteces, class Costs>
class Graph
{
    public:

    void addVertex(const Verteces&);
    void addEdge(const Verteces&, const Verteces&, const Costs&);

    bool hasVertex(const Verteces&) const;
    bool hasEdge(const Verteces&,const Verteces&) const;

    class Row
    {
        public:
        Row (const std::map<Verteces,Costs>&);
        Costs operator[](const Verteces&) const;
        
        using RowIterator = typename std::map<Verteces,Costs>::const_iterator;

        RowIterator begin();
        RowIterator end();

        private:
        const std::map<Verteces,Costs>& matrixRow;
    };

    Row operator[](const Verteces&) const;

    private:

    using OriginalIter = typename std::unordered_map<Verteces,std::map<Verteces,Costs>>::const_iterator;

    public:

    class Iterator
    {
        public:
        Iterator (const OriginalIter&);

        Iterator& operator++();
        bool operator !=(const Iterator&) const;

        Verteces operator *() const;

        private:
        OriginalIter it;

        

    };

    Iterator  begin();
    Iterator end();

    private:
    std::unordered_map<Verteces,std::map<Verteces,Costs>> graph;


};

#endif