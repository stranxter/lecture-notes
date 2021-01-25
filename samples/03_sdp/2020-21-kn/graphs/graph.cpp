#ifndef __GRAPH_CPP
#define __GRAPH_CPP

#include "graph.h"
#include <cassert>

template <class Verteces, class Costs>
void Graph<Verteces,Costs>::addVertex(const Verteces &v)
{
    assert(!hasVertex(v));
    graph[v];
}
template <class Verteces, class Costs>
void Graph<Verteces,Costs>::addEdge(const Verteces &v1, const Verteces &v2, const Costs &c)
{
    assert(hasVertex(v1));
    assert(hasVertex(v2));
    graph[v1][v2]=c;
}
template <class Verteces, class Costs>
bool Graph<Verteces,Costs>::hasVertex(const Verteces &v) const
{
    return graph.count(v) > 0;
}
template <class Verteces, class Costs>
bool Graph<Verteces,Costs>::hasEdge(const Verteces &v1, const Verteces &v2) const
{
    return hasVertex(v1) && hasVertex(v2) && graph.at(v1).count(v2) > 0;
}
template <class Verteces, class Costs>
typename Graph<Verteces,Costs>::Row Graph<Verteces,Costs>::operator[](const Verteces &v1) const
{
    return Row(graph.at(v1));
}

template <class Verteces, class Costs>
Graph<Verteces,Costs>::Iterator::Iterator (const typename Graph<Verteces,Costs>::OriginalIter &_it):it(_it){}

template <class Verteces, class Costs>
typename Graph<Verteces,Costs>::Iterator&  Graph<Verteces,Costs>::Iterator::operator++()
{
    ++it;
    return *this;
}

template <class Verteces, class Costs>
bool Graph<Verteces,Costs>::Iterator::operator !=(const typename Graph<Verteces,Costs>::Iterator &other) const
{
    return it != other.it;
}


template <class Verteces, class Costs>
Verteces Graph<Verteces,Costs>::Iterator::operator *() const
{
    return it->first;
}

template <class Verteces, class Costs>
Graph<Verteces,Costs>::Row::Row (const std::map<Verteces,Costs> &_row):matrixRow(_row){}

template <class Verteces, class Costs>
Costs Graph<Verteces,Costs>::Row::operator[](const Verteces &v) const
{
    return matrixRow.at(v);
}

template <class Verteces, class Costs>
typename Graph<Verteces,Costs>::Iterator Graph<Verteces,Costs>::begin()
{
    return typename Graph<Verteces,Costs>::Iterator(graph.begin());
}

template <class Verteces, class Costs>
typename Graph<Verteces,Costs>::Iterator Graph<Verteces,Costs>::end()
{
    return typename Graph<Verteces,Costs>::Iterator(graph.end());
}

template <class Verteces, class Costs>
typename Graph<Verteces,Costs>::Row::RowIterator Graph<Verteces,Costs>::Row::begin()
{
    return matrixRow.begin();
}

template <class Verteces, class Costs>
typename Graph<Verteces,Costs>::Row::RowIterator Graph<Verteces,Costs>::Row::end()
{
    return matrixRow.end();
}


#endif