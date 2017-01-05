#include <iostream>
#include <cassert>
#include <set>
#include <string>
#include "graph.cpp"


string stringOfLabels (int start, 
	 				   int end, 
	 				   const Graph<int,char> g,
	 				   set<int>& visited)
{
	if (start == end)
		return "";
	
	visited.insert (start);

	for (const pair<int,char>& edge : g.edgesFrom (start))
	{
		if (visited.count (edge.first) == 0)
		{
			string nextString 
			   = stringOfLabels (edge.first,end,g,visited);

			if (!nextString.empty())
			{
				return edge.second + nextString;
			}
			if (edge.first == end)
			{
				string result;
				result += edge.second;
				return result;
			}
		}
	}

	return "";

}

string stringOfLabels (int start, 
	 				   int end, 
	 				   const Graph<int,char> g)
{
	set<int> visited;
	return stringOfLabels (start,end,g,visited);
}


bool hasPath (int start, const char *str, const Graph<int,char> g)
{
	if (*str == 0)
		return true;
	for (const pair<int,char>& edge : g.edgesFrom (start))
	{
		if (edge.second == *str && 
			hasPath (edge.first,str+1,g))
		{
			return true;
		}
	}
	return false;
}


void testGraph ()
{
	Graph<int,char> g;

	g.addEdge (0,1,'a');
	g.addEdge (2,0,'c');

	g.addEdge (1,4,'b');
	g.addEdge (1,2,'b');
	g.addEdge (1,3,'b');

	g.toDotty (cout);

	assert (hasPath(0,"abc",g));
	assert (!hasPath (1,"abc",g));
	assert (hasPath(1,"bca",g));
	assert (hasPath(0,"abcabcabcabc",g));

	string res = stringOfLabels (2,4,g);
	cout << "str = " << res << endl;
}


int main ()
{
	testGraph();

	return 0;
}