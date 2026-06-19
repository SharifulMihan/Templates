#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
int r,c;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j){
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}


void bfs(int si,int sj,int di,int dj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj]++;

    
    while (!q.empty())
    {
        pair<int,int> par = q.front();

        int par_i = par.first;
        int par_j = par.second;
        // cout<<par_i<<" "<<par_j<<endl;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
            
        }
        
    }
    

    
}

int main()
{
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    
    cin>>r>>c;
    for (int i = 0; i < r ; i++){
        for (int j = 0; j < c; j++){
            cin>>grid[i][j];
        }
    }

    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    bfs(si,sj,di,dj);
    cout<<level[di][dj]<<endl;
    
}