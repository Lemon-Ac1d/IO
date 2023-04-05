#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1510;
int n, m;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool g[N][N];
int stx, sty;
char ch;
int vis[N][N][3];
bool f1;

void dfs(int x, int y, int lx, int ly){
    if(f1)  return;
    if(vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly)){
        f1 = true;
        return;
    }
    vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;
    for(int i = 0; i < 4; i++){
        int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
        int lxx = lx + dx[i], lyy = ly + dy[i];
        if(!g[xx][yy]){
            if(vis[xx][yy][1] != lxx || vis[xx][yy][2] != lyy || !vis[xx][yy][0])
                dfs(xx, yy, lxx, lyy);
        }
    }
}

int main(){

    while(cin >> n >> m){
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        f1 = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> ch;
                if(ch == '#')   g[i][j] = 1;
                if (ch == 'S'){
                    stx = i; sty = j;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // puts("");
        dfs(stx, sty, stx, sty);

        if (f1)
            puts("Yes");
        else
            puts("No");
    }




    return 0;
}