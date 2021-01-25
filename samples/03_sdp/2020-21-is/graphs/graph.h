#ifndef __GRAPH_H
#define __GRAPH_H

#include <unordered_map>
#include <map>
#include <iostream>

template <class VertexType, class CostType>
class Graph
{
    public:

    void addVertex(const VertexType&);
    bool hasVertex(const VertexType&) const;

    void addEdge(const VertexType&, const VertexType&, const CostType&);
    bool hasEdge(const VertexType&, const VertexType&) const;
    CostType getCost(const VertexType&, const VertexType&) const;

    const std::map<VertexType,CostType>& neighbors (const VertexType&) const;

    private:
    using MainIterator = typename std::unordered_map<VertexType,std::map<VertexType,CostType>>::const_iterator;

    public:
    class VertexIterator
    {
        public:

        VertexIterator(const MainIterator&);

        VertexIterator& operator++();
        VertexType operator*();
        bool operator != (const VertexIterator&) const;
        private:
        MainIterator main_it;
    };


    VertexIterator begin() const;
    VertexIterator end() const;

    private:
    
    std::unordered_map<VertexType,std::map<VertexType,CostType>> graph;

};

template <class VertexType, class CostType>
void exportToDot(const Graph<VertexType,CostType> &g, std::ostream&);

#endif