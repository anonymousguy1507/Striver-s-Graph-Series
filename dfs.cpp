#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[],int s,vector<bool> &visited,vector<int> &ans)
    {
        visited[s] = true;
        ans.push_back(s);
        for(auto it : adj[s])
        {
            if(visited[it] == false)
              DFS(adj,it,visited,ans);
             
        }
        
    }
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V,false);
        DFS(adj,0,vis,ans);
        return ans;
    }
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main()
{
    vector<int> adj[5];
    
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,0);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,1);
    addEdge(adj,3,2);
    addEdge(adj,3,4);
    addEdge(adj,4,2);
    addEdge(adj,4,3);
   vector<int> ans = dfsOfGraph(5,adj);
   for(auto x: ans)
     cout<<x<<" ";
    
}
