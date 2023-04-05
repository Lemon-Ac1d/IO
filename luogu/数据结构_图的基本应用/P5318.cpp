#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m, x, y;
vector<int> a[N];
bool vis[N];
void dfs(int x, int cur)
{
    vis[x] = true;
    cout << x << " ";
    if (cur == n)
        return;
    for (int i = 0; i < a[x].size(); i++)
        if (!vis[a[x][i]])
            dfs(a[x][i], cur + 1);
}

void bfs()
{
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << ' ';
        for (int i = 0; i < a[t].size(); i++)
        {
            if (!vis[a[t][i]])
            {
                vis[a[t][i]] = true;
                q.push(a[t][i]);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end()); // 标准vector排序

    dfs(1, 0);
    puts("");
    bfs();
    return 0;
}