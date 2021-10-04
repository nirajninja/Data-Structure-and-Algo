	void toplogical(int i, vector<int>&vis, vector<int>adj[], stack<int>&s)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                toplogical(it,vis,adj,s);
            }
        }
        s.push(i);
    }	

	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<int>v;
	    
	    stack<int>s;
	    vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            toplogical(i,vis,adj,s);
	        }
	    }
	    
	    
	    while(!s.empty())
	    {
	        v.push_back(s.top());
	        s.pop();
	    }
	    return v;
	    
	    // code here
	}
	
	
	
