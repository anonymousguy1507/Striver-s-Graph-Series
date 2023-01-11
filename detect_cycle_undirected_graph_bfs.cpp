bool detect(int src, vector<int> adj[],vector<int>  &vis)
    {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
          
             // go to all adjacent nodes
             for(auto it : adj[node]){
                // if adjacent node is unvisited
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                    
                }
                else if(parent != it)
                  return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis) == true)
                  return true;
            }
        }
        return false;
    }
