#include<iostream>

using namespace std;
const int N = 35;
int g[N][N], b[N][N];
int n;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if(x < 0 || x > n + 1|| y < 0 || y > n + 1 || b[x][y])  return;
    b[x][y] = 1;
    for(int i = 0; i < 4; i++)  dfs(x + dx[i], y + dy[i]); 
}



int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if(!g[i][j]) b[i][j] = 0;
            else b[i][j] = 2;
        }

    dfs(0,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (b[i][j] == 0)
                cout << 2 << ' '; // 如果染过色以后i，j那个地方还是0，说明没有搜到，就是周围有墙，当然就是被围住了，然后输出2
            else
                cout << g[i][j] << ' '; // 因为被染色了，本来没有被围住的水和墙都染成了1，所以就输出b[i][j]
        cout << '\n';                   // 换行
    }

    return 0;
}