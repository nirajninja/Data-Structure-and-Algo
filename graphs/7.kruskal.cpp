
struct util{
	    int v;
	    int u;
	    int wt;
	    
	};
	
//
//saari edges ko sort karo
// min weitght waali edges ko add kro,jb tak cycle nhi bnti

//greedy approach h bro.

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	static bool comp(util a, util b)
	{
	    return a.wt<b.wt;
	}
	
  //find funciton to find parent of a node.
	int find (int x,vector<int>& parent)
	{
	    if(parent[x]==x)
	    {
	        return x;
	    }
	    return find( parent[x],parent);
	}
	
  //union to join two components
	void unio(int x, int y,vector<int>&parent )
	{
	    int u=find(x,parent);
	    int v=find(y,parent);
	    
	    parent[u]=v ;
	    
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        //apne util wale data type ka ek graph le, aur usme element daal de
        vector<util>graph;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                graph.push_back({ i,it[0],it[1]});
            }
        }
        
        sort(graph.begin(),graph.end(),comp);
        vector<int>parent(V);
      
        //INITIALLY saare node alag alag component h, isliye sbke parent wo khud honge,
        for(int i=0;i<V;i++)
        parent[i]=i;
        
        int ans=0;
        
      //min weight waala node le, aur usem apne ans graph me add kr, agar uska comp alag h toh, agar same h toh cycle bna dega vo, isliye use ignore krde.  
      for(int i=0;i<graph.size();i++)
        {
            
            int x=find(graph[i].u,parent);
            int y=find(graph[i].v, parent);
            if(y==x) continue;
            ans+=graph[i].wt;
            unio(x,y,parent);
            
            
            
            
        }
        return ans;
    }
