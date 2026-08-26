#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
bool cycle=false;
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout<<par<<endl;
        for(int child:adj_list[par]){
            if(vis[child] && parent[par]!=child){
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) bfs(i);
    }
    if(cycle) cout<<"Detected Cycle\n";
    else cout<<"No Cycle\n";
    return 0;
}