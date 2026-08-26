#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
bool pathvis[1005];
bool cycle;

void dfs(int src)
{
    cout<<src<<endl;
    vis[src] = true;
    pathvis[src] = true;
    for(int child:adj_list[src])
    {
        if(vis[child] && pathvis[child]) 
            cycle = true;
        if(!vis[child])
        {
            dfs(child); 
        }
    }
    pathvis[src] = false;
}

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        // adj_list[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    cycle = false;
    for(int i=0;i<n;i++){
        if(!vis[i]) 
            dfs(i);
    }
    if(cycle) cout<<"Detected Cycle\n";
    else cout<<"No Cycle\n";
    return 0;
}