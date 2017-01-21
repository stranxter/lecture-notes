#include <iostream>
#include <cassert>
#include <set>
#include <string>
#include "graph.cpp"
#include <stack>
#include <map>
#include <queue>


string stringOfLabels (int start, 
	 				   int end, 
	 				   const Graph<int,char>& g,
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


string getPathIter1 (int start, 
	 				int end, 
	 				const Graph<int,char> g)
{

	//key:child, value:parent>
	map<int,int> history;
	stack<int> s;

	s.push (start);
	history[start] = start;


	while (!s.empty() && s.top() != end)
	{
		int v = s.top();
		s.pop();

		for (const pair<int,char>& edge : g.edgesFrom (v))
		{
			const int &neigh = edge.first;

			if (history.count(neigh) == 0)
			{
				s.push (neigh);
				history[neigh] = v;
			}
			
		}

	}

	if (s.empty())
		return "";

	string result;

	int current = end;
	while (current != start)
	{
		int &parent = history[current];

		result += g.getLabel (parent,current);
		current = parent;
	}

	return result;

}



bool hasPathIter (int start, 
	 				int end, 
	 				const Graph<int,char> g)
{

	set<int> visited;
	stack<int> s;

	s.push (start);
	visited.insert (start);

	
	while (!s.empty() && s.top() != end)
	{
		int v = s.top();
		s.pop();

		for (const pair<int,char>& edge : g.edgesFrom (v))
		{
			const int &neigh = edge.first;

			if (visited.count(neigh) == 0)
			{
				s.push (neigh);
				visited.insert (neigh);
			}
			
		}

	}

	return !s.empty();
}


string getPathIter2 (int start, 
	 				int end, 
	 				const Graph<int,char> g)
{

	set<int> visited;
	stack<pair<int,string>> s;

	s.push (pair<int,string>(start,""));
	visited.insert (start);

	
	while (!s.empty() && s.top().first != end)
	{
		//vertex and history
		pair<int,string> vh = s.top();
		s.pop();

		int &v = vh.first;
		string &hist = vh.second;

		for (const pair<int,char>& edge : g.edgesFrom (v))
		{
			const int &neigh = edge.first;
			const char &label = edge.second;

			if (visited.count(neigh) == 0)
			{
				s.push (pair<int,string>(neigh,hist+label));
				visited.insert (neigh);
			}
			
		}

	}

	if (s.empty())
		return "";

	return s.top().second;

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

bool hasPathBFS (int start, 
	 				int end, 
	 				const Graph<int,char> g)
{

	set<int> visited;
	queue<int> q;

	q.push (start);
	visited.insert (start);

	
	while (!q.empty() && q.front() != end)
	{
		int v = q.front();
		q.pop();

		for (const pair<int,char>& edge : g.edgesFrom (v))
		{
			const int &neigh = edge.first;

			if (visited.count(neigh) == 0)
			{
				q.push (neigh);
				visited.insert (neigh);
			}
			
		}

	}

	return !q.empty();
}


void testGraph ()
{
	Graph<int,char> g;

	g.addEdge (0,1,'a');
	g.addEdge (2,0,'c');

	g.addEdge (1,4,'b');
	g.addEdge (1,2,'b');
	g.addEdge (1,3,'b');
	g.addEdge (4,3,'x');
	g.addEdge (3,4,'z');

	assert (g.getLabel (0,1) == 'a');
	assert (g.getLabel (3,4) == 'z');
	assert (g.getLabel (4,3) == 'x');
	assert (g.getLabel (1,3) == 'b');

	g.toDotty (cout);

	assert (hasPath(0,"abc",g));
	assert (!hasPath (1,"abc",g));
	assert (hasPath(1,"bca",g));
	assert (hasPath(0,"abcabcabcabc",g));

	assert (hasPathIter(2,4,g));
	assert (!hasPathIter(3,1,g));
	assert (hasPathIter(1,1,g));
	assert (!hasPathIter(4,2,g));


	assert (hasPathBFS(2,4,g));
	assert (!hasPathBFS(3,1,g));
	assert (hasPathBFS(1,1,g));
	assert (!hasPathBFS(4,2,g));


	string res = stringOfLabels (2,3,g);
	cerr << "str = " << res << endl;

	res = getPathIter1 (2,3,g);
	cerr << "str = " << res << endl;

	res = getPathIter2 (2,3,g);
	cerr << "str = " << res << endl;

}


int main ()
{
	testGraph();

	return 0;
}