#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <memory>


#include "doctest.h"
#include "graph.hpp"
#include "graph_test.cpp"

void printDotty (std::ostream& out, const Graph<std::string,double> &g)
{
    out << "digraph G{\n";

    for (uint vertex : g)
    {
        out << "   " << vertex << "[label=\"" << g.getVertex(vertex) << "\"];\n";
        for (uint neighbour : g.neighbours(vertex))
        {
            out << "   " 
                << vertex
                << "->"
                << neighbour
                << "[label=\""
                << g.getEdge (vertex,neighbour)
                << "\"];\n";
        }
    }

    out << "}";
}

/*
Граф от обекти, свързани с указатели
*/
struct vertex
{
    std::string label;
    std::set<std::shared_ptr<vertex>> neigh;

    vertex (const std::string& l):label(l)
    {std::cerr << "Creating " << label << "\n";}

    ~vertex ()
    {std::cerr << "Destroying " << label << "\n";}

};

std::shared_ptr<vertex> testPointerGraph ()
{
    std::shared_ptr<vertex> sofia (new vertex ("Sofia"));
    std::shared_ptr<vertex> plovdiv (new vertex ("Plovdiv"));
    std::shared_ptr<vertex> pleven (new vertex ("Pleven"));
    std::shared_ptr<vertex> dragoman (new vertex ("Dragoman"));

    sofia->neigh.insert (plovdiv);
    plovdiv->neigh.insert (pleven);
    sofia->neigh.insert (pleven);
    dragoman->neigh.insert (sofia);

    return dragoman;
}

void testDeletion ()
{
    std::shared_ptr<vertex> v = testPointerGraph ();
    std::cout << "PAUSE 1";
    std::cin.get();

    std::shared_ptr<vertex> belgrade (new vertex ("Belgrade"));
    belgrade->neigh.insert (v);

}

int main ()
{

    testDeletion();
    std::cout << "PAUSE 2";
    std::cin.get();


    // пускане на тестовете
    doctest::Context().run();    
 
    printDotty (std::cerr, createGraph());
}