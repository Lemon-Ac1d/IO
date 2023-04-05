#include<iostream>
#include<cstring>

using namespace std;
const int N = 1e5 + 10;

int n, a, b;
int h[N], e[N * 2], ne[N * 2], idx;
bool st[N];

int ans = N;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dfs(int u)
{
    st[u] = true;
    int size = 0, sum = 1;
    // size 表示去除当前点后最大的 子串的连通块，最后再与根节点去除包括当前节点的所有树的比较大小
    // sum 表示子树中包括了多少个点
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(st[j])   continue;
        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum);
    ans = min(ans, size);
    return sum;
}


int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);
    cout << ans;
    return 0;
}