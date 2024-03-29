#include <iostream>

using namespace std;
const int N = 110;
int n, m;
int s[N], v[N][N], w[N][N], dp[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];

        for (int j = 1; j <= s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= s[i]; k++)
            {
                if (v[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << dp[m];
    return 0;
}