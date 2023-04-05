#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
const int N = 510, M = 10010;
struct Edge
{
    int a, b, c;
} edges[M];
int n, m, x, y, z, k;
int dist[N], back_up[N];
void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++)
    {
        memcpy(back_up, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], back_up[e.a] + e.c);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }

    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);
    return 0;
}