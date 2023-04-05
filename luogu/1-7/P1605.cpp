#include<iostream>
#include<cstring>
using namespace std;


int n, m, t, sx, sy, fx, fy, tmpx, tmpy;
long long res = 0;
int vis[10][10];
int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};


void dfs(int x, int y)
{
    if(x == fx && y == fy)
    {
        res++;
        return;
    }
    
   for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if(vis[xx][yy] != 0 || xx <= 0 || yy <= 0 || xx > n || yy >m) continue;
        vis[xx][yy] = 1;
        dfs(xx,yy);
        vis[xx][yy] = 0;
    }
}

int main(){
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;

    memset(vis,0,sizeof(vis));
    vis[sx][sy] = 1;
    for(int i = 0; i < t; i++)
    {
        cin >> tmpx >> tmpy;
        vis[tmpx][tmpy] = -1;
    }

    dfs(sx, sy);

    cout << res;
    return 0;
}