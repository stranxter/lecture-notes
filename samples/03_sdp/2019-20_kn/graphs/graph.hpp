#ifndef __GRAPH_HPP
#define __GRAPH_HPP

#include "graph.h"
#include <cassert>

template<class VertexValue, class Weight>
 Graph<VertexValue,Weight>::Graph ()
 {

 }

template<class VertexValue, class Weight>
Graph<VertexValue,Weight>& Graph<VertexValue,Weight>::addVertex (uint v, const VertexValue &value)
{
    vertexes.insert (v);
    vertexValues[v] = value;
    neigh[v];
    return *this;
}
template<class VertexValue, class Weight>
Graph<VertexValue,Weight>& Graph<VertexValue,Weight>::addEdge (uint v1, uint v2, Weight weight)
{
    neigh[v1].insert(v2);
    weights[std::make_pair(v1,v2)] = weight;
    return *this;
}
template<class VertexValue, class Weight>
bool Graph<VertexValue,Weight>::hasVertex (uint v) const
{
    return vertexes.count(v) > 0;
}
template<class VertexValue, class Weight>
bool Graph<VertexValue,Weight>::hasEdge (uint v1, uint v2) const
{
    return neigh.count(v1) > 0 && neigh.find(v1)->second.count(v2) > 0;
}
template<class VertexValue, class Weight>
Weight& Graph<VertexValue,Weight>::getEdge (uint v1, uint v2)
{
    return weights[std::make_pair(v1,v2)];
}
template<class VertexValue, class Weight>

Weight Graph<VertexValue,Weight>::getEdge (uint v1, uint v2) const
{
    assert (weights.count(std::make_pair(v1,v2)) > 0);
    return weights.find(std::make_pair(v1,v2))->second;
}

template<class VertexValue, class Weight>
VertexValue& Graph<VertexValue,Weight>::getVertex (uint v)
{
    return vertexValues[v];
}

template<class VertexValue, class Weight>
VertexValue Graph<VertexValue,Weight>::getVertex (uint v) const
{
    assert (vertexValues.count(v) > 0);
    return vertexValues.find(v)->second;
}


template<class VertexValue, class Weight>
const std::set<uint>& Graph<VertexValue,Weight>::neighbours (uint v) const
{
    assert (neigh.count(v) > 0);
    return neigh.find(v)->second;
}

template<class VertexValue, class Weight>
typename std::set<uint>::const_iterator Graph<VertexValue,Weight>::begin () const
{
    return vertexes.begin();
}
template<class VertexValue, class Weight>
typename std::set<uint>::const_iterator Graph<VertexValue,Weight>::end () const
{
    return vertexes.end();
}

#endif