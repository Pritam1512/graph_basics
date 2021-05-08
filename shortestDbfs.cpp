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

void shortestPath(vector<int> adj[],int s,int v)
{
    vector<bool> visited(v , false);
    vector<int> shortestD(v, INT_MAX);

    shortestD[0]=0;
    queue<int> q;
    q.push(s);
    visited[s]=true;

    while(q.size()!=0)
    {
        int u = q.front();
        q.pop();

        for(auto x: adj[u])
        {
            if(visited[x] == false)
            {
                shortestD[x]=shortestD[u]+1;
                visited[x] = true;
                q.push(x);
            }
        }
    }

    for(auto x :shortestD)
    {
        cout << x << " ";

    }
}
int main()
{
    vector<int> adj[6];
    addEdge(0,1,adj);
    addEdge(1,2,adj);
    addEdge(2,5,adj);
    addEdge(5,4,adj);
    addEdge(4,3,adj);
    addEdge(3,1,adj);
    showGraph(adj,6);
    cout << "" << endl;

    shortestPath(adj,0,6);
    return 0;
}