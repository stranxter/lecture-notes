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
    map["Plvodiv"]["Stara Zagora"] = 20;
    map["Plovdiv"]["Sofia"] = 15;
    map["Plovdiv"]["Varna"] = 15;
    map["Varna"]["Stara Zagora"] = 10;


    for(const auto& [neighbor, cost] : map["Plovdiv"])
    {

    }
  

    Graph<std::string> country;
    country["Plovdiv"].insert("Sofia");
    country["Plovdiv"].insert("Varna");
    country["Plovdiv"].insert("Stara Zagora");
    country["Krichim"].insert("Plovdiv");
    country["Varna"].insert("Plovdiv");
    country["Varna"].insert("Sofia");
    country["Sofia"].insert("Plovdiv");
    country["Sofia"].insert("Varna");

    std::cout << way<std::string>(country,"Sofia","Stara Zagora") << std::endl;
    std::cout << way<std::string>(country,"Krichim","Sofia") << std::endl;
    std::cout << way<std::string>(country,"Sofia","Krichim") << std::endl;



    return 0;
}