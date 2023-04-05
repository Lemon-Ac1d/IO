#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 31e5 + 10;

int n, x;
int son[M][2], a[N], idx;

void insert(int x)
{
    int p = 0;
    for(int i = 30; ~i; i--)
    {
        int u = x >> i & 1;
        if(!son[p][u])  son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int search(int x)
{
    int p = 0, res = 0;
    for(int i = 30; ~i; i-- )
    {
        int s = x >> i & 1;
        if(son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, search(a[i]));
    cout << res;

    return 0;
}