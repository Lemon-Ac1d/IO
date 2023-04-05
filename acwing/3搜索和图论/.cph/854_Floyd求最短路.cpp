#include<iostream>

using namespace std;
const int N = 210, M = 2e4 + 10, INF = 1e9;
int dist[N][N];
int n, m, k, x, y, z;

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}


int main(){
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        dist[x][y] = min(dist[x][y], z);
    }

    floyd();

    while(k--)
    {
        cin >> x >> y;
        int t = dist[x][y];
        if (t > INF / 2)
            puts("impossible");
        else
            printf("%d\n", t);
    }

    return 0;
}