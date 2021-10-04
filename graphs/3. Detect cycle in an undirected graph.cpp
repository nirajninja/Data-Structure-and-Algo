//DFS approach

bool cycle(int i, vector<int>&vis, vector<int> adj[],int parent)
    {
        vis[i]=1;
        for(auto e:adj[i])
        {
            if(vis[e]==0)
            {  
                if( cycle(e,vis, adj, i))
                {
                    return true;
                }
                
            }
            else if(e!=parent)
            {
            return true;    
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            
            if(vis[i]==0)
            {
                if(cycle(i, vis, adj,-1))
                {
                    return true;
                }
            }
            
        }
        
        return false;
        
    }
