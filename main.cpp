

#include <iostream>
#include <vector>
#include <list>

using namespace std;




main(){
    int nodes,edges,n1,n2,val;
    cin>>nodes>>edges;
    //-------vector(nodes)//list(connected nodes)//pair(no of node connected,weight)----
    //vector< vector< pair<int,int> > > adj_list( nodes, vector< pair <int, int> > ());       //using vector of vectors 
    vector< list< pair<int,int> > > adj_list( nodes, list< pair <int, int> > ());        //using vector of lists
    for(int i=0;i<edges;i++){
        cin>>n1>>n2>>val;
        adj_list[n1].push_back({n2,val});
        adj_list[n2].push_back({n1,val});

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