// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
	int V;    // No. of vertices
	int E;
public:
	list<pair<int, int>> *adj;
	Graph(int V,int E);  // Constructor 
	void addEdge(int u,int v, int wt);
	int BFS(int s);
	void print();
	//int size(int s);
};
Graph::Graph(int V,int E)
{
	this->V = V;
	this->E = E;
	adj = new list<pair<int, int>>[V,E];
}
void Graph::addEdge(int u,int v, int wt)
{
	//cin >> u >> v >> wt;
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

int Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	int count = 0;
	visited[s] = true;
	pair<int, int>b;
	for (auto i = adj[s].begin(); i != adj[s].end(); ++i)	
	{
		b = *i;
		if (!visited[b.first])
		{
			visited[b.first] = true;
	    	count++;		
		}
	}
	return count;
}
/* void Graph::print() {
	for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
	{
		b = *i;
	}
}
*/
int main()
{
	int v, e,u,b,w,f[1000];
	cin >> v >> e;
	Graph g(v,e);
	for (int i = 0;i < e;i++) {
		cin >> u >> b >> w;
		g.addEdge(u, b, w);
	}
	for (int i = 0;i < v;i++) {
		f[i] = g.BFS(i);
		cout << f[i] << endl;
	}
		
	//cout<< g.BFS();
	//g.adj[i]
	return 0;
}