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
bool way(const Graph<V> &g, const V &from, const V &to)
{
    
}

int main()
{

    WGraph<std::string,double> map;

    map["Sofia"]["Plovdiv"] = 20;
    map["Plovdiv"]["Sofia"] = 15;
    map["Plovdiv"]["Varna"] = 15;


    for(const auto& [neighbor, cost] : map["Plovdiv"])
    {

    }
  

    CityMap2 network;
    network.insert({"Sofia","Plovdiv",20});
    network.insert({"Plovdiv","Sofia",18});
    network.insert({"Plovdiv","Varna",15});




    return 0;
}