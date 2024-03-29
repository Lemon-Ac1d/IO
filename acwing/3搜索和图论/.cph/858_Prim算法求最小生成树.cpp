#include<iostream>
#include<cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N];
bool st[N];
int n, m, u, v, w;

int prime()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        if(i && dist[t] == INF) return INF;

        if(i)   res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}


int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }

    int t = prime();
    if (t == INF)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}