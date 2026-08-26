#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[1005];
int dis[1005];
void dijkstra(int src){
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        int parNode = par.first;
        int parDis = par.second;
        for(auto child:adj_list[parNode]){
            int childNode = child.first;
            int childDis = child.second;
            if(childDis+parDis < dis[childNode]){
                dis[childNode] = childDis+parDis;
                q.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for (int i = 0; i < 1005; i++)
        dis[i] = INT_MAX;
    
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    dijkstra(0);
    for(int i=0;i<n;i++){
        cout<<i<<" -> "<<dis[i]<<endl;
    }
    return 0;
}