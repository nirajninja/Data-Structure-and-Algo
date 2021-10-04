 
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>bfs;
        vector<int>vis(V,0);
        
            
               queue<int>q;
                q.push(0);
                vis[0]=1;
               
                while(!q.empty())
                {
                    int temp=q.front();
                     q.pop();
                    bfs.push_back(temp);
                  
                    
                    
                    for(auto e:adj[temp])
                    {
                        if(vis[e]==0)
                        {
                            vis[e]=1;
                            q.push(e);
                            
                        }
                    }
                }
                
                
                
            
        
        return bfs;
        
    }
};
