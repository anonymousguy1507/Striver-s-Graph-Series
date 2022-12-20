#include<bits/stdc++.h>
using namespace std;

vector<int> bfsofGraph(int V,vector<int> adj[])
{
    vector<int> vis(V,0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    
    vector<int> bfs;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        bfs.push_back(temp);
        
        for(auto it : adj[temp]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
    
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
   vector<int> ans = bfsofGraph(5,adj);
   for(auto x: ans)
     cout<<x<<" ";
    
}
