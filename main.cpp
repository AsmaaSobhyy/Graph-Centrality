
#include <iostream>
#include <vector>
#include <list>
#include <limits>


using namespace std;

void Closeness(int n,vector<vector<pair<int,int> > > adj_list)
{

   int sum;
   float ans;
   vector <int> dis;
   for (int i = 0; i< n; i++)
   {
       sum=0;
       dis=shortest_distance(i,adj_list);
       for (int j = 0; j< n; j++)
       {
           sum+=dis[j];
           
       }
       ans=(float)(n-1)/(float)sum;
       cout << ans << endl;
   }
   
   
}  


void Degree(vector<vector<pair<int,int> > > adj_list,int nodes){

	//to get degree 
    for(int i=0;i<nodes;i++)
		cout << adj_list[i].size() << endl;

}




//-----------------------------------------betweenness------------------------------------

//a recurssive function that find all pathes between 2 nodes ,
// count the shortest pathes, and the pathes which passed by the "between" node.
float Bforpath(int finish,int src,int target,int between,int n,
						vector<vector<pair<int,int> > > adj_list, bool visited[], 
						int path[], int &index, int &weight,int &oldw,int &shortcount,int &passed){
	visited[src] = true; 
	// collect recent path.
	path[index] = src; 
	index++; 
	
	float x;

	if (src == target) // now path[] contains  nodes from finish to target
	{ 
		// decides if the available path is shorter than the current one.
		if (weight<oldw){
			oldw=weight;
			shortcount=1;
			passed=0;
			// decides if this path passed by the desired node or not.
			for (int i = 1; i<index; i++) {
				if(path[i]==between){
					passed++;
				}
			}

		}
		// if it have the same weight of the current shortest path increase number of short pathes "shortcount".
		else if(weight==oldw){
			shortcount++;
			for (int i = 1; i<index+1; i++) {
				if(path[i]==between){
					passed++;
				}
			}


		}	
	} 

	else // if the current node is not the target.
	{ 
		// loop through all connected nodes and search through them.
		for (int i = 0; i <adj_list[src].size(); i++) {
			int next=adj_list[src][i].first;// the next node.
			if(!visited[next]){
				weight+=adj_list[src][i].second;// add it's weight to the current path.
				x = Bforpath(finish,next,target,between,n,adj_list,visited,path,index,weight,oldw,shortcount,passed);
				weight-=adj_list[src][i].second;// remove it's weight to try different pathes.
			}
		}

			
	} 
	
	visited[src] = false;
	index--; 
	// if this is the first function called from outside not recurssuvely
	if(finish==src){
		float ans =(float)passed/(float)shortcount;
		return ans;
		
	}
	// not used
	 return x;//don't need a return value while searching for target.


	}
//----------------------function to be called from main-----------------------------
	void Betweenness(int n,
				vector<vector<pair<int,int> > > adj_list){
	// variables used in the Bforpath function.
	bool *visited = new bool[n]; 
	int *path = new int[n]; 
	int index,weight,shortcount,passed,oldw;

	float betweenness; 

	for (int i = 0; i < n; i++)
		visited[i] = false; 

	//loop through all nodes to get their betweenness
	for(int between=0; between < n; between ++){
		betweenness=0; 
		// get pathes between all nodes 
		for(int i =0;i<n;i++){
			if(i != between){
				for(int j=i+1;j<n;j++){
					if( j != i && j!= between){
						//initialize values each use.
						weight =0;
						index=0;
						shortcount=1;
						passed=0;
						oldw=numeric_limits<int>::max();
						// add betweenness for each path to the whole node betwenness.
						betweenness+= Bforpath(i,i,j,between,n,adj_list,visited, path,index,weight,oldw,shortcount,passed);
						

					}
				}
			}
		}
		//print current betweennes for node "between" .. betweenness of adj_list[between].
		cout << betweenness<< endl;
	}


	}
//-------------------------------------------------------------------------------------------


//-------------------------------------------------------
vector<int> shortest_distance(int src,
	vector<vector<pair<int,int> > > adj_list){

	int n = adj_list.size();
	vector<int>	dis(n, numeric_limits<int>::max());
	
	dis[src] = 0;
	for(int it=0; it<n-1; it++){
	
		for(int u=0; u<n; u++)
		{
			for(int e=0; e<adj_list[u].size(); e++)
			{
				int v = adj_list[u][e].first;
				int w = adj_list[u][e].second;
				
				if(dis[u] + w < dis[v])
				{
					dis[v] = dis[u] + w;
				}
			}
		}
	}
	
	
	return dis;
}
//--------------------------------------------------------------------------------------





main(){
	//----------- taking input--------------------------
    int nodes,edges,n1,n2,val;
    cin>>nodes>>edges;

    vector< vector< pair<int,int> > > adj_list( nodes, vector< pair <int, int> > ());       //using vector of vectors 
    //vector< list< pair<int,int> > > adj_list( nodes, list< pair <int, int> > ());        //using vector of lists
    for(int i=0;i<edges;i++){
        cin>>n1>>n2>>val;
        adj_list[n1].push_back({n2,val});
        adj_list[n2].push_back({n1,val});

    }


    //-----------to get degree ----------------------------
	//Degree(adj_list,nodes);
    

	//-----------to get betweenness------------------------
	//Betweenness(nodes, adj_list);

	//------------to get closeness-------------------------
	//Closeness(adj_list,nodes);
	
	
}
