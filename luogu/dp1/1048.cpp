#include <iostream>
#include<cstring>

using namespace std;
const int M = 105;

int t, m;
int dp[1005], v[M], w[M];

int main()
{   
    
    cin >> t >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    dp[0] = 0;
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (w[i] <= j)
            {
                dp[j] = max(dp[j - w[i]] + v[i],  dp[j]); 
            }
        }

    }
    cout << dp[t];
    return 0;
}