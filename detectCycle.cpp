#include<bits/stdc++.h>
using namespace std;

// detect cylce in undirected graph
// using dfs traversal

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

bool detectRec(vector<int> adj[] ,int s,int parent,vector<bool> &visited)
{
    visited[s] = true;
    for(auto u: adj[s])
    {
        if(visited[u] == false)
        {
             if(detectRec(adj,u,s,visited) == true)
                return true;
        }
        else if(u != parent)
        {
            return true;
        }

    }
    return false;
}
bool detectCycle(vector<int> adj[],int s,int v)
{
    vector<bool> visited(v,false);

    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
        {
            if(detectRec(adj,i,-1,visited) == true)
                return true;
        }
    }
    return false;
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
    addEdge(5,6,adj);
    //showGraph(adj,6);


    cout << detectCycle(adj,0,6);
    return 0;
}