#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int N = 310;
typedef pair<pair<int,int>,int> PII;

int f[N][N], m, x, y, tmp, u, v;
int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
bool vis[N][N];
int main(){
    cin >> m;
    memset(f,-1,sizeof(f));
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < m; i++){
        cin >> x >> y >> tmp;
        if(tmp < f[x][y] || f[x][y] == -1)
            f[x][y] = tmp;

        for(int i = 0; i < 4; i++)
        {
            u = x + dx[i], v = y + dy[i];
            if (u >= 0 && v >= 0 && (tmp < f[u][v] || f[u][v] == -1))
            {
                f[u][v] = tmp;

            }
        }

    }


      
    queue<PII> q;
    q.push({{0,0},0});
    vis[0][0] = 1;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        int xx = t.first.first, yy = t.first.second, tt = t.second;
        for(int i = 0; i < 4; i++)
        {
            u = xx + dx[i], v = yy + dy[i];
            if (u >= 0 && v >= 0 && (f[u][v] == -1 || tt + 1 < f[u][v]) && !vis[u][v])
            {
                q.push({{u,v},tt+1});
                vis[u][v] = 1;
                if (f[u][v] == -1)
                {
                    cout << tt + 1;
                    return 0;
                }
            }
        }
    }

    cout << -1 <<endl;
    return 0;
}