#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int r,c;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j){
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}


void dfs(int si,int sj){
    cout<<si<<" "<<sj<<endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci,cj;
        ci = si + d[i].first;
        cj = sj + d[i].second;
        
        if(valid(ci,cj) && !vis[ci][cj])
            dfs(ci,cj);
    }
}

int main()
{
    memset(vis,false,sizeof(vis));
    
    cin>>r>>c;
    for (int i = 0; i < r ; i++){
        for (int j = 0; j < c; j++){
            cin>>grid[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;
    dfs(si,sj);
    
}