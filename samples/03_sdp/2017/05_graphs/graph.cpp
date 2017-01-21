#ifndef __GRAPH__
#define __GRAPH__

#include <list>
#include <map>
#include <algorithm>
#include <ostream>

using namespace std;

template <class VT, class LT>
class Graph
{
public:

	void addVertex (const VT&);
	void addEdge (const VT&, const VT&, const LT&);

    list<pair<VT,LT>> edgesFrom (const VT&) const;

    LT getLabel (const VT&, const VT&) const;

	void toDotty (ostream&) const;
private:

	map<VT,list<pair<VT,LT>>> edges;

};

template <class VT, class LT>
void Graph<VT, LT>::addVertex (const VT &newVertex)
{
	edges[newVertex];	
}

template <class VT, class LT>
void Graph<VT, LT>::addEdge (const VT &outV, const VT &inV, const LT &lbl)
{
	addVertex (outV);
	addVertex (inV);

	edges[outV].push_back (pair<VT,LT>(inV,lbl));
}

template <class VT, class LT>
void Graph<VT, LT>::toDotty (ostream &out) const
{
/*
digraph G
{
	1->2[label="hello"];
	3->4;
	1;
}
*/
	out << "digraph G\n{\n";
	
	for (const pair<VT,list<pair<VT,LT>>>& mapEl : edges)
	{
		out << "\t" << mapEl.first << ";\n";

		for (const pair<VT,LT> &edge : mapEl.second)
		{
			out << "\t"
			    << mapEl.first 
			    << " -> "
			    << edge.first 
			    << "[label=\""
			    << edge.second
			    << "\"];\n";
		}
	}

	out << "}\n";

}

template <class VT, class LT>
list<pair<VT,LT>> Graph<VT,LT>::edgesFrom (const VT &out) const
{
	return edges.at(out);	
}

template <class VT, class LT>
LT Graph<VT,LT>::getLabel (const VT &out, const VT &in) const
{
	//map<VT,list<pair<VT,LT>>> edges;

	assert (edges.count(out) != 0);
	assert (edges.count(in) != 0);

	for (const pair<int,char>& edge : edgesFrom (out))
	{
		if (in == edge.first)
		{
			return edge.second;
		}
	}

	assert (false);

	LT dummy;
	return dummy;

}


#endif