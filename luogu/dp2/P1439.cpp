#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], b[N], map[N];
int f[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        map[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        f[i] = 0x7fffffff;
    }
    f[0] = 0;
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[len] < map[b[i]]) f[++len] = map[b[i]];
        else
        {
            int l = 0, r = len, mid;

            while (l < r)
            {
                int mid = l + r >> 1;
                if (f[mid] > map[b[i]])
                    r = mid;
                else
                    l = mid + 1;
            }
            f[l] = min(map[b[i]], f[l]);
        }
    }
    printf("%d", len);


    return 0;
}