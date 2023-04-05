#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], cnt[N], w[N], idx, dist[N];
int n, m, x, y, z;
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa()
{   
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n)
                    return true;

                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");

    return 0;
}