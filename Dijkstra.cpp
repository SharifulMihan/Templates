#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[1005];
int dis[1005];
void dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty())
    {
        pair<int,int> par = pq.top();
        pq.pop();
        int parNode = par.second;
        int parDis = par.first;
        for(auto child:adj_list[parNode]){
            int childNode = child.first;
            int childDis = child.second;
            if(childDis+parDis < dis[childNode]){
                dis[childNode] = childDis+parDis;
                pq.push({dis[childNode],childNode});
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