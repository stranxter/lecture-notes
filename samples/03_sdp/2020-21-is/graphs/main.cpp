#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

#include "graph.cpp"


TEST_CASE("Basic Test")
{
    Graph<std::string, double> airports;

    airports.addVertex ("Sofia");
    airports.addVertex ("New York");
    airports.addVertex ("Milan");

    airports.addEdge("Sofia","Milan",20);
    airports.addEdge("Milan","Sofia",25);

    airports.addEdge("Milan","New York",650);
    airports.addEdge("New York","Milan",800);


    CHECK(airports.hasVertex ("Sofia"));
    CHECK(airports.hasVertex ("Milan"));
    CHECK(!airports.hasVertex ("Paris"));

    CHECK(airports.hasEdge("Sofia","Milan"));
    CHECK(!airports.hasEdge("Sofia","New York"));

    CHECK(airports.getCost("Sofia","Milan")==20);
    CHECK(airports.getCost("New York","Milan")==800);

    unsigned int count = 0;
    for (auto neighbor : airports.neighbors("Milan"))
    {
        CHECK((neighbor.first == "Sofia" || neighbor.first == "New York"));
        ++count;
    }
    CHECK(count == 2);
    
    count = 0;
    for (std::string airport : airports)
    {
        CHECK((airport == "Sofia" || airport == "New York" || airport == "Milan"));
        ++count;
    }
    CHECK(count == 3);

}


Graph<std::string,double> testGraph()
{
    Graph<std::string, double> airports;

    airports.addVertex ("Sofia");
    airports.addVertex ("New York");
    airports.addVertex ("Milan");
    airports.addVertex ("Naples");
    airports.addVertex ("Los Angelis");
    airports.addVertex ("Dan Francisko");
    airports.addVertex ("Boston");

    airports.addEdge("Sofia","Milan",20);
    airports.addEdge("Milan","Sofia",25);

    airports.addEdge("Milan","New York",650);
    airports.addEdge("New York","Milan",800);

    airports.addEdge("Milan","Naples",100);
    airports.addEdge("Naples","Naples",15);

    airports.addEdge("New York", "Boston",20);
    airports.addEdge("New York","Los Angelis",200);
    airports.addEdge("New York","Dan Francisko",120);
    airports.addEdge("Dan Francisko","Los Angelis",60);

    return airports;
}

void exportDot()
{
 
    Graph<std::string, double> airports = testGraph();

    std::ofstream dot ("test.dot");
    
    exportToDot(airports,dot);
 
}

template <class VertexType, class CostType>
void way (const Graph<VertexType,CostType>&g, 
          const VertexType &v1, 
          const VertexType &v2,
          std::vector<VertexType>& path,
          std::vector<VertexType> &bestPath)
{
    path.push_back(v1);
    if(v1 == v2)
    {
        std::cout << "Path found:";
        for (std::string city : path)
        {
            std::cout << city << " ";
        }
        std::cout << std::endl;
        if (bestPath.size() == 0 || path.size() < bestPath.size())
            bestPath = path;
    } else 
    {

        for (auto n : g.neighbors(v1))
        {
            if (std::find(path.begin(),path.end(),n.first)==path.end())
            {
                way(g,n.first,v2,path,bestPath);  
            }
        }
    }

    path.pop_back();

}

template <class VertexType, class CostType>
bool waybfs (const Graph<VertexType,CostType>&g, 
             const VertexType &v1, 
             const VertexType &v2)
{
    std::queue<std::pair<VertexType,bool>> q;
    std::set<VertexType> visited;    

    q.push(std::make_pair(v1,true));
    visited.insert(v1);
    q.push(std::make_pair(VertexType(),false));

    std::unordered_map<VertexType,VertexType> reverse;

    unsigned int levelCount = 0;

    while (!q.empty() && q.front().first != v2)
    {
       std::pair<VertexType,bool> current = q.front(); q.pop();

       if(current.second == false)
       {
           if (!q.empty())
           {
               q.push(std::make_pair(VertexType(),false));
           }
           ++levelCount;
       } else 
       {

            std::cout << current.first << ":" << levelCount << std::endl;

            for (auto n : g.neighbors(current.first))
            {
                if (visited.count(n.first) == 0)
                {
                        q.push(std::make_pair(n.first,true));
                        reverse[n.first] = current.first;
                        visited.insert(n.first);
                }
                
            } 
       }
    }

    if (!q.empty())
    {
        VertexType current = v2;
        while (current != v1)
        {
            std::cout << current << ", ";
            current = reverse[current];
        }
        std::cout << v1 << std::endl;
    }

    return !q.empty();
}

int main ()
{

    //exportDot();

 /*   std::vector<std::string> path, bestPath;
    way<std::string,double> (testGraph(),"Sofia","Los Angelis",path, bestPath);

    for (std::string city : bestPath)
    {
        std::cout << city << std::endl;
    }
*/

    std::cout << waybfs<std::string,double> (testGraph(),"New York","Sofia") << std::endl;

    // пускане на тестовете
    doctest::Context().run();

    return 0;
}