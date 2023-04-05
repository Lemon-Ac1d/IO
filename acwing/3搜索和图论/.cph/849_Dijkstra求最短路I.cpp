#include<iostream>
#include<cstring>
using namespace std;

const int N = 510;

int g[N][N], dist[N];
int n, m, x, y, z;
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;

    }
    if(dist[n] == 0x3f3f3f3f)   return -1;
    return dist[n];

}


int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    cout << dijkstra();

    return 0;
}