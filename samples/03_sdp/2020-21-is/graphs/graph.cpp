#ifndef __GRAPH_CPP
#define __GRAPH_CPP

#include "graph.h"
#include <cassert>

template <class VertexType, class CostType>
void Graph<VertexType,CostType>::addVertex(const VertexType &v)
{
    graph[v];
}
template <class VertexType, class CostType>
bool Graph<VertexType,CostType>::hasVertex(const VertexType &v) const
{
    return graph.count(v) > 0;
}
template <class VertexType, class CostType>
void Graph<VertexType,CostType>::addEdge(const VertexType &v1, const VertexType &v2, const CostType &c)
{
    assert(hasVertex(v1));
    assert(hasVertex(v2));

    graph[v1][v2]=c;
}
template <class VertexType, class CostType>
bool Graph<VertexType,CostType>::hasEdge(const VertexType &v1, const VertexType &v2) const
{
    return hasVertex(v1) && hasVertex(v2) && graph.at(v1).count(v2) > 0;
}
template <class VertexType, class CostType>
CostType Graph<VertexType,CostType>::getCost(const VertexType &v1, const VertexType &v2) const
{
    assert(hasEdge(v1,v2));
    return graph.at(v1).at(v2);
}

template <class VertexType, class CostType>
const std::map<VertexType,CostType>& Graph<VertexType,CostType>::neighbors (const VertexType &v) const
{
    assert(hasVertex(v));
    return graph.at(v);
}

template <class VertexType, class CostType>
Graph<VertexType,CostType>::VertexIterator::VertexIterator (const typename Graph<VertexType,CostType>::MainIterator &_it):main_it(_it)
{}

template <class VertexType, class CostType>
typename Graph<VertexType,CostType>::VertexIterator& Graph<VertexType,CostType>::VertexIterator::operator++()
{
    ++main_it;
    return *this;
}

template <class VertexType, class CostType>
VertexType Graph<VertexType,CostType>::VertexIterator::operator*()
{
    return main_it->first;
}

template <class VertexType, class CostType>
bool Graph<VertexType,CostType>::VertexIterator::operator != (const typename Graph<VertexType,CostType>::VertexIterator &other) const
{
    return main_it != other.main_it;
}

template <class VertexType, class CostType>
typename Graph<VertexType,CostType>::VertexIterator Graph<VertexType,CostType>::begin() const
{
    return typename Graph<VertexType,CostType>::VertexIterator(graph.begin());
}

template <class VertexType, class CostType>
typename Graph<VertexType,CostType>::VertexIterator Graph<VertexType,CostType>::end() const
{
    return typename Graph<VertexType,CostType>::VertexIterator(graph.end());
}

template <class VertexType, class CostType>
void exportToDot(const Graph<VertexType,CostType> &g, std::ostream& out)
{
    out << "digraph G{\n";

    for (VertexType v : g)
    {
        out << "\"" << v << "\";\n";
        for (auto n : g.neighbors(v))
        {
            out << "\"" << v << "\"" << "->" << "\"" << n.first << "\"[label=\"" << n.second <<"\"];\n";
        }
    }

    out<< "}";
}



#endif