#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>* adj;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);

	void addEdge(int v, int w);
	int NumberOfconnectedComponents();
};

int Graph::NumberOfconnectedComponents()
{

	// Mark all the vertices as not visited
	bool* visited = new bool[V];

	// To store the number of connected components
	int count = 0;
	for (int v = 0; v < V; v++)
		visited[v] = false;

	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {
			DFSUtil(v, visited);
			count += 1;
		}
	}

	return count;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;

	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int main()
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	cout << g.NumberOfconnectedComponents();

	return 0;
}

