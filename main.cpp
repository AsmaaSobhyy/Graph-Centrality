
#include <iostream>
#include <vector>
#include <list>
#include <limits>


using namespace std;

//to do 

void Degree(vector<vector<pair<int,int> > > adj_list);
void Closeness(vector<vector<pair<int,int> > > adj_list);
void Betweenness(vector<vector<pair<int,int> > > adj_list);



//-------------------------------------------------------
vector<int> shortest_distance(int src,
	vector<vector<pair<int,int> > > adj_list){

	int n = adj_list.size();
	vector<int>	dis(n, numeric_limits<int>::max()); 
	//vector<int> p(n, -1);
	
	dis[src] = 0;
	for(int it=0; it<n-1; it++){
		// Loop over all edges
				// Loop over all edges
		for(int u=0; u<n; u++)
		{
			for(int e=0; e<adj_list[u].size(); e++)
			{
				int v = adj_list[u][e].first;
				int w = adj_list[u][e].second;
				
				if(dis[u] + w < dis[v])
				{
					dis[v] = dis[u] + w;
					//p[v] = u;
				}
			}
		}
	}
	
	return dis;
    //return p;
}
//--------------------------------------------------------------



main(){
    int nodes,edges,n1,n2,val;
    cin>>nodes>>edges;
    //-------vector(nodes)//list(connected nodes)//pair(no of node connected,weight)----
    vector< vector< pair<int,int> > > adj_list( nodes, vector< pair <int, int> > ());       //using vector of vectors 
    //vector< list< pair<int,int> > > adj_list( nodes, list< pair <int, int> > ());        //using vector of lists
    for(int i=0;i<edges;i++){
        cin>>n1>>n2>>val;
        adj_list[n1].push_back({n2,val});
        adj_list[n2].push_back({n1,val});

    }

    vector<int> x = shortest_distance(0,adj_list);
    for(int i =0;i<nodes;i++){
        cout<<x[i]<<endl;
    }
    
    //--------testing----------------
    //vector of vectors
    // int i =2;
    // cout<<"using vector  "<<i<<endl;
	// 	for(int j=0; j<adj_list[i].size(); j++){
	// 		cout<<"(node: "<<adj_list[i][j].first<<" , weight: "<<adj_list[i][j].second<<") ";
	// 	}
    
    //i=1;
    //pair<int,int> b;

    //vector of lists
    // cout<<endl<<"using list "<<i<<endl;
    //     for (list<pair<int,int> >::iterator it = adj_list[i].begin(); it != adj_list[i].end(); it++)
    //        { b =*it;
    //         cout <<"(node: "<< b.first <<" , weight: "<<b.second;
    //        }
	
}