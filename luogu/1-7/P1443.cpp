#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 410;
typedef pair<int,int> PII;
int n, m, x, y, f[N][N];
bool vis[500][500]; // 走没走过
void bfs(){
    queue<PII> q;     
    q.push({x,y});
    const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    const int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
    while(!q.empty()){
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int u = xx + dx[i], v = yy + dy[i];
            if(u < 1 || u > n || v < 1 || v > m || vis[u][v])
                continue;
            vis[u][v] = 1;
            q.push({u,v});

            f[u][v] = f[xx][yy] + 1;
            // if(u==2 && v==2){
            //     cout << xx << " "<< yy << endl;
            // }

        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         printf("%-5d", f[i][j]);
        //     }
        //     printf("\n");
        // }
        // cout << endl;
    }
}

int main(){

    cin >> n >> m >> x >> y;

    memset(f,-1,sizeof(f));
    memset(vis, false, sizeof(vis));
    vis[x][y] = true;
    f[x][y] = 0;
    bfs();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%-5d", f[i][j]);
        }
        printf("\n");
    }

    return 0;
}