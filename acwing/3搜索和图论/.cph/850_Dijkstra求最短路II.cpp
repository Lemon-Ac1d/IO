#include<iostream>
#include<cstring>
#include<queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

int h[N], dist[N], e[N], idx, ne[N], w[N];
int m, n, x, y, z;
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if(st[ver] )    continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }

    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    
    memset(h, -1, sizeof h);

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    cout << dijkstra() << endl;

    return 0;
}