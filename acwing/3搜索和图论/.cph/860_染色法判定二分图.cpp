#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N], e[N * 2], ne[N * 2], idx;
int color[N];
void add(int k, int x)
{
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++ ;
}

bool dfs(int u, int c)
{
    color[u] = c;
    
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j, 3 - c))  return false;
        }
        else if(color[j] == c ) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)    puts("Yes");
    else puts("No");

    return 0;
}