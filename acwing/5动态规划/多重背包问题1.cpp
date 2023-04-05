#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n, m;
int s[N], v[N], w[N], dp[N][N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] * k] + w[i] * k);
            }
        }
    }
    cout << dp[n][m];

    return 0;
}