class Solution {
public:
void DFS(vector<int> adjls[],int s,vector<int> &vis)
  {
       vis[s] = 1;
      for(auto it: adjls[s]){
          if(!vis[it]){
              DFS(adjls,it,vis);
          }
      }
  }

int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> adjls[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 and i != j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        int cnt = 0;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                DFS(adjls,i,vis);
            }
        }
        return cnt;

        
    }
};
