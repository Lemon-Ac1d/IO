#include<iostream>

using namespace std;
#define int long long
const int N = 1e4 + 10, M = 1e7 + 10;
int dp[M], w[N], v[N];
int t, m;

signed main()
{
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> v[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = w[i]; j <= t; j++){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[t];
    return 0;
}