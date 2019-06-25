// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
	int V;    // No. of vertices
	int E;

	// Pointer to an array containing adjacency 
	// lists 
	list<pair<int,int>> *adj;
public:
	Graph(int V,int E);  // Constructor 

	// function to add an edge to graph 
	void addEdge(int u,int v, int wt);

	// prints BFS traversal from a given source s 
	int BFS(int s);
	void print();
	int size(int s);
};
Graph::Graph(int V,int E)
{
	this->V = V;
	this->E = E;
	adj = new list<pair<int, int>>[V,E];
}
void Graph::addEdge(int u,int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

int Graph::BFS(int s)
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS 
	//list<int> queue;
	int count = 0;
	visited[s] = true;
	//queue.push_back(s);

	//while (!queue.empty())
	//{
		// Dequeue a vertex from queue and print it 
		//s = queue.front();
		//cout << s << " ";
		//queue.pop_front();
		pair<int, int>b;
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			b = *i;
			if (!visited[b.first])
			{
				visited[b.first] = true;
				count++;
				//queue.push_back(b.first);
			}
		//}
	}
	return count;
}
/*void Graph::size(int s) {
	for(auto i = adj[s].begin(); i != adj[s].end(); ++i)
	         n=adj[s].size();
	return n;
}*/

int main()
{
	Graph g(6,9);
	g.addEdge(3, 0, 2);
	g.addEdge(0, 1,1);
	g.addEdge(0, 2,3);
	g.addEdge(2, 1,5);
	g.addEdge(2, 1,3);
	g.addEdge(4, 3, 10);
	g.addEdge(5, 4, 13);
	g.addEdge(0, 4, 32);
	g.addEdge(3, 2,3);
	cout<<g.BFS(3);

	return 0;
}
