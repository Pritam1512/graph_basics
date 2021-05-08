#include<bits/stdc++.h>
using namespace std;

// detect cylce in undirected graph
// using bfs traversal

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

bool isCycle(vector<int> adj[] ,int s, int parent,vector<bool> &isVisited)
{
    queue<pair<int,int>> q;
    q.push({s,parent});

    while(q.size()!=0)
    {
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int pare = p.second;

        for(auto u :adj[x])
        {
            if(isVisited[u] == false)
            {
                q.push({u,x});
                isVisited[u] = true;
            }
            else if(u != pare)
            {
                return true;
            }
        }
        
    }
    return false;
}
bool detectCycle(vector<int> adj[],int v)
{
    vector<bool> isVisited(v,false);

    for(int i=0;i<v;i++)
    {
        
        if(isVisited[i] == false)
        {
            if(isCycle(adj,i,-1,isVisited) == true)
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
    
    //showGraph(adj,6);


    cout << detectCycle(adj,7);
    return 0;
}