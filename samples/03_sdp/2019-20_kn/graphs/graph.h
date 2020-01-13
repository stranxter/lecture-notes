#ifndef __GRAPH_H
#define __GRAPH_H

#include <set>
#include <map>
#include <cstdint>

template <class VertexValue, class Weight>
class Graph
{
    public:
    Graph ();
    Graph& addVertex (uint v, const VertexValue &value);
    Graph& addEdge (uint v1, uint v2, Weight weight);
    bool hasVertex (uint v) const;
    bool hasEdge (uint v1, uint v2) const;
    Weight& getEdge (uint v1, uint v2);
    Weight getEdge (uint v1, uint v2) const;
    VertexValue& getVertex (uint v);
    VertexValue getVertex (uint v) const;
    const std::set<uint>& neighbours (uint v) const;

    typename std::set<uint>::const_iterator begin () const;
    typename std::set<uint>::const_iterator end () const;


    private:
    std::set<uint> vertexes;
    std::map<uint,VertexValue> vertexValues; 
    std::map<uint,std::set<uint>> neigh;
    std::map<std::pair<uint,uint>,Weight> weights;

};

#endif