  void dfs(vector<int>&vis, vector<int>adj[], vector<int>&df, int n)
    {
        df.push_back(n);
        vis[n]=1;
        for(auto e:adj[n])
        {
            if(vis[e]==0)
            {
                dfs(vis,adj,df,e);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>df;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(vis,adj,df,i);
            }
        }
        
        return df;
        
    }
};
