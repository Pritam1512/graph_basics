#include<bits/stdc++.h>
using namespace std;

void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    
}
void showGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << "" << endl;
    }
}
void bfsRec(vector<int> adj[],int s,vector<bool> &visited)
{
    cout << s << " ";
    visited[s] = true;
    for(auto x : adj[s])
    {
        if(visited[x] == false)
        {
            bfsRec(adj,x,visited);
        }
    }
}
void bfs(vector<int> adj[],int s,int v)
{
    vector<bool> visited(v ,false);

    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
        {
            bfsRec(adj,i,visited);
        }
    }
}

int main()
{
    vector<int> adj[7];
    addEdge(0,1,adj);
    addEdge(1,2,adj);
    addEdge(1,3,adj);
    addEdge(2,6,adj);
    addEdge(3,4,adj);
    addEdge(4,5,adj);
    //showGraph(adj,6);


    bfs(adj,0,6);
    return 0;
}