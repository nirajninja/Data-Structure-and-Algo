  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         priority_queue<pair<int,int>, vector<pair<int,int>>,
                                greater<pair<int,int>> > pqu;

        pqu.push({0,S});        
        vector<int>ans(V,0);
        vector<bool>visited(V,false);
        while(!pqu.empty())
        {
            auto pq=pqu.top();
            pqu.pop();
            
            int x=pq.second;
            int wt=pq.first;
            
            if(visited[x]==false)
            {
                visited[x]=true;
                ans[x]=wt;
                for(auto y:adj[x])
                {
                    if(visited[y[0]]==false)
                    {
                        pqu.push({wt+y[1],y[0]});
                    }
                }
            }
           
        }
         return ans;
         
                                 
       
    }
