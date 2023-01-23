#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <queue>


template<typename V, typename W>
using Multigraph=std::map<V,std::map<V,std::vector<W>>>;

template<typename V, typename W>
void toDotty(const Multigraph<V,W> &g, std::ostream &out)
{
    /*
        Sofia->Varna[label="100"]
        Sofia->Varna[label="12"]
    */
    out << "Digraph G{\n";

    for (const std::pair<V,std::map<V,std::vector<W>>> &edge : g)
    {
        //edge.first е ключа, т.е. възела, от който излизат дъгите
        //обхождаме всички наслединци на edge.first

        for (const std::pair<V,std::vector<W>> &child : edge.second)
        {
            //child.first е ключа на детето
            //child.second е вектор с тегла

            for (const W &weight : child.second)
            {
                out << edge.first 
                    << "->" 
                    << child.first 
                    << "[label=\"" 
                    << weight 
                    << "\"]\n";
            }
        }
    }
    out << "}";
}

template<typename V, typename W>
bool reachable(const Multigraph<V,W> &g,
               V start,
               V end,
               W budget,
               std::vector<V> currentPath)
{

    if(std::find(currentPath.begin(),
                 currentPath.end(),
                 start) != currentPath.end())
    {
        return false;
    }

    currentPath.push_back(start);

    if (budget < 0)
    {
        return false;
    }

    if (start==end)
    {
        for (const V &v : currentPath)
        {
            std::cout << v << "->";
        }
        std::cout << std::endl;
        return true;
    }

    if(g.count(start) == 0)
    {
        return false;
    }

    for (const std::pair<V,std::vector<W>> &child : g.at(start))
    {
        //child.first е детето
        //child.second е списъка с цените на дъгите
        for (const W & w: child.second)
        {
            if (reachable(g,child.first,end,budget-w,currentPath))
            {
                return true;
            }
        }
    }

    return false;
}

template<typename V, typename W>
int shortestPath(const Multigraph<V,W> &g,
                 V start,
                 V end)
{

    std::queue<std::pair<V,bool>> q;

    std::map<V,V> parents;

    q.push({start,true});
    q.push({V(),false});

    int count = 0;

    while(q.size() > 0)
    {
        std::pair<V,bool> front = q.front(); q.pop();
        V v = front.first;

        if (front.second == false)
        {
            count++;
            if (q.size()>0)
            {
                q.push({V(),false});
            }
        } else 
        {
            if(v==end)
            {
                std::cout << v;
                while(v != start)
                {                       
                    v = parents[v];
                    std::cout << "<-" << v;
                }
                return count;
            }
            if(g.count(v) > 0)
            {
                for (const std::pair<V,std::vector<W>> &child : g.at(v))
                {
                    //child.first е детето
                    //child.second е списъка с цените на дъгите        
                    q.push({child.first,true});
                    parents[child.first]=v;
                }
            }
        }
    }

    return -1;
}


int main()
{
    Multigraph<std::string, double> g;
    
    g["Sofia"]["Varna"]={100,200};
    g["Sofia"]["Plovdiv"]={30};
    g["Varna"]["Sofia"]={80, 10};
    g["Plovdiv"]["Varna"]={60};
    g["Plovdiv"]["Sofia"]={0};
    g["Plovdiv"]["Asenovgrad"]={15};
    g["Plovdiv"]["Pamporovo"]={10};
    g["Asenovgrad"]["Pamporovo"]={10};
    toDotty(g,std::cout);


    //std::cout << reachable<std::string,double>(g,"Sofia","Varna",90,std::vector<std::string>()) << std::endl;

    std::cout << shortestPath<std::string,double>(g,"Sofia","Pamporovo") << std::endl << std::endl;
}