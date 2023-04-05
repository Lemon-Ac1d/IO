#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int n, a[N];
int vis[N], path[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        vis[a[i]]++;
        while (j < i && vis[a[i]] > 1)
        {
            path[j] = a[j];
            vis[a[j++]]--;
        }
        ans = max(ans, i - j + 1);
    }

    cout << ans;
    return 0;
}