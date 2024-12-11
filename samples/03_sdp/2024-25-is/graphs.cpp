#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include <map>
#include <string>
#include <set>

template<typename V,typename C>
using WGraph = std::unordered_map<V,std::map<V,C>>;

template<typename V>
using Graph = std::unordered_map<V,std::set<V>>;


template<typename V>
bool way_helper(const Graph<V> &g, const V &from, const V &to,std::unordered_set<V>& visited)
{
    if(from == to)
    {
        return true;
    }

    visited.insert(from);
    for(const V& neigh : g.at(from))
    {
        if(!visited.count(neigh) && way_helper(g,neigh,to,visited))
        {
            return true;
        }
    }
    return false;

}

template<typename V>
bool way(const Graph<V> &g, const V &from, const V &to)
{
    std::unordered_set<V> visited;
    return way_helper(g,from,to,visited);
}

template<typename V, typename C>
struct path_cost
{
    std::vector<V> path;
    C c;  
};

template<typename V, typename C>
bool operator<(const path_cost<V,C>& p1, const path_cost<V,C>& p2)
{
    return p2.path.emty() || p1.c < p2.c;
}

template<typename V, typename C>
std::vector<V> best_path_dfs_helper(const WGraph<V,C> &g, 
                                    const V &from, 
                                    const V &to,
                                    path_cost<V,C> &current_path,
                                    path_cost<V,C> &best_path_found)
{

}


template<typename V, typename C>
std::vector<V> best_path_dfs(const WGraph<V,C> &g, const V &from, const V &to) 
{
    return {};
}

int main()
{

    WGraph<std::string,double> map;

    map["Sofia"]["Plovdiv"] = 20;
    map["Sofia"]["Ruse"] = 10;
    map["Ruse"]["Varna"] = 2;
    map["Plvodiv"]["Stara Zagora"] = 20;
    map["Plovdiv"]["Sofia"] = 15;
    map["Plovdiv"]["Varna"] = 15;
    map["Varna"]["Stara Zagora"] = 10;
    map["Sofia"]["Varna"] = 50;


    std::cout << "Neighbours of Plovdiv:\n";
    for(const auto& [neighbor, cost] : map["Plovdiv"])
    {
        std::cout << neighbor << std::endl;
    }
  
    std::cout << "Best path from Sofia to Varna:\n";
    for(std::string v : best_path_dfs<std::string,double>(map,"Sofia","Varna"))
    {
        std::cout << v << std::endl;
    }

    std::cout << "================\n";


    Graph<std::string> country;
    country["Plovdiv"].insert("Sofia");
    country["Plovdiv"].insert("Varna");
    country["Plovdiv"].insert("Stara Zagora");
    country["Krichim"].insert("Plovdiv");
    country["Varna"].insert("Plovdiv");
    country["Varna"].insert("Sofia");
    country["Sofia"].insert("Plovdiv");
    country["Sofia"].insert("Varna");
    country["Stara Zagora"];

    std::cout << "Neighbours of Plovdiv:\n";
    for(const std::string& neighbor : country["Plovdiv"])
    {
        std::cout << neighbor << std::endl; 
    }


    std::cout << way<std::string>(country,"Sofia","Stara Zagora") << std::endl;
    std::cout << way<std::string>(country,"Krichim","Sofia") << std::endl;
    std::cout << way<std::string>(country,"Sofia","Krichim") << std::endl;



    return 0;
}