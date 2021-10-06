  int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                       greater<pair<int,int>> > pq;
        // code here
        
        int s=0;
        pq.push({0,0});
        vector<int>vis(V,0);
       // vis[0]=1;
        while(!pq.empty())
        {
           int node=pq.top().second;
           int wt=pq.top().first;
           pq.pop();
           if(vis[node]==0)
           {
             s+=wt;
             vis[node]=1;
            
            for(auto e:adj[node])
            {
                if(vis[e[0]]==0)
                {
                    pq.push({e[1],e[0]});
                   
                }
                
            }
            
         }    
        }
        return s;
    }
