
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <iomanip>
#include <cstdio>


using namespace std;


//----------------------------------------Degree------------------------------------
void Degree(vector<vector<pair<int,int> > > adj_list,int nodes){

	//to get degree 
    for(int i=0;i<nodes;i++)
		cout << adj_list[i].size() << endl;

}



//----------------------------------------closeness------------------------------------
vector<int> DijkstraSP(vector< vector<pair<int, int> > > &adjList, int &start)
    {
   
    vector<int> dist;
    
    // Initialize all source->vertex as infinite.
    int n = adjList.size();
    for(int i = 0; i < n; i++)
        {
        dist.push_back(1000000007); // Define "infinity" as necessary by constraints.
        }
        
    // Create a PQ.
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    
    // Add source to pq, where distance is 0.
    pq.push(make_pair(start, 0));
    dist[start] = 0;
    
    // While pq isn't empty...
    while(pq.empty() == false)
        {
        // Get min distance vertex from pq. (Call it u.)
        int u = pq.top().first;
        pq.pop();
        
        // Visit all of u's friends. For each one (called v)....
        for(int i = 0; i < adjList[u].size(); i++)
            {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;
            
            // If the distance to v is shorter by going through u...
            if(dist[v] > dist[u] + weight)
                {
                // Update the distance of v.
                dist[v] = dist[u] + weight;
                // Insert v into the pq. 
                pq.push(make_pair(v, dist[v]));
                }
            }
        }
    
    return dist;
    }

void Closeness(int n,vector<vector<pair<int,int> > > adj_list)
{

   int sum;
   float ans;
   vector <int> dis;
   for (int i = 0; i< n; i++)
   {
       sum=0;
       dis=DijkstraSP(adj_list,i);
       for (int j = 0; j< n; j++)
       {
           sum+=dis[j];
           
        }
       ans=(float)(n-1)/(float)sum;
       cout << ans << "\n";
   }
   
   
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
		
		if (weight < oldw){
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
			for (int i = 1; i<index; i++) {
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
				
				if(weight<=oldw){
					x = Bforpath(finish,next,target,between,n,adj_list,visited,path,index,weight,oldw,shortcount,passed);
				}
				weight-=adj_list[src][i].second;// remove it's weight to try different pathes.
			}
		}

			
	} 
	
	visited[src] = false;
	index--; 
	// if this is the first function called from outside not recurssuvely
	if(finish==src){
		//cout << src << " "<< between<<"  "<< target <<" : "<< passed <<" / "<< shortcount<<endl;
		float ans =(float)passed/(float)shortcount;
		return ans;
		
	}
	// not used
	 return 1;//don't need a return value while searching for target.


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
						// shortcount=1;
						// passed=0;
						oldw=1000000007;
						// add betweenness for each path to the whole node betwenness.
						betweenness+= Bforpath(i,i,j,between,n,adj_list,visited, path,index,weight,oldw,shortcount,passed);
						

					}
				}
			}
		}
		//print current betweennes for node "between" .. betweenness of adj_list[between].
		cout << betweenness<< "\n";
	}


	}

//-------------------------------------------------------





main(){
	//----------- taking input--------------------------
	 freopen("input.txt", "r", stdin);// read from file
    int nodes,edges,n1,n2,val;
    cin>>nodes>>edges;
	std::cout << std::fixed << std::setprecision(7);
    vector< vector< pair<int,int> > > adj_list( nodes, vector< pair <int, int> > ());       //using vector of vectors 
    //vector< list< pair<int,int> > > adj_list( nodes, list< pair <int, int> > ());        //using vector of lists
    for(int i=0;i<edges;i++){
        cin>>n1>>n2>>val;
        adj_list[n1].push_back({n2,val});
        adj_list[n2].push_back({n1,val});

    }
	fclose (stdin);

	// to output to a file 
	freopen ("output.txt","w",stdout);

    //-----------to get degree ----------------------------
	cout<<"Degree Centrality : \n";
	Degree(adj_list,nodes);
    
	//------------to get closeness-------------------------
	cout<<"\nCloseness Centrality : \n";
	Closeness(nodes,adj_list);

	//-----------to get betweenness------------------------
	cout<<"\nBetweenness Centrality : \n";
	Betweenness(nodes, adj_list);

	
	fclose (stdout);// close file

	
	
}
