// proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int nodes, edges;
vector< list< pair<int,int> > > adj_list( nodes, list< pair <int, int> > ());        //using vector of lists
int BFS(int s)
{
	bool *visited = new bool[nodes];
	for (int i = 0; i < nodes; i++)
		visited[i] = false;
	int count = 0;
	visited[s] = true;
	pair<int, int>b;
	for (auto i = adj_list[s].begin(); i != adj_list[s].end(); ++i)
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
int main()
{
	int n1, n2, val,f[1000];
	cin >> nodes >> edges;
    for(int i=0;i<edges;i++){
        cin>>n1>>n2>>val;
        adj_list[n1].push_back({n2,val});
        adj_list[n2].push_back({n1,val});
    }
	//cout<< adj_list[1].size();
	for (int i = 0;i < nodes;i++) {
		f[i] = BFS(i);
		cout << f[i] << endl;
	}
}

