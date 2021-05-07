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

void dfs(vector<int> adj[],int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++) visited[i]=false;
    stack<int> st;
    st.push(s);
    visited[s]=true;

    while(st.size()!=0)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";

        for(auto x: adj[u])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                st.push(x);
            }
        }
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


    dfs(adj,6,0);
    return 0;
}