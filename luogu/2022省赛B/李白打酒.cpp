#include<iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 110;
int n, m;
int dp[N * 2][N][N];

int main(){
    cin >> n >> m;
    dp[0][0][2] = 1;
    
    for(int i = 0; i < m + n; i ++)
    //位置
    {
        for(int j = 0; j < m; j++){
            // 花
            for(int k = 0; k <= m; k++){
                if(dp[i][j][k]) {
                    if(k > 0) dp[i + 1][j + 1][k - 1] = (dp[i][j][k] + dp[i + 1][j + 1][k - 1]) % MOD;
                    if(k <= 50) dp[i + 1][j][k * 2] = (dp[i + 1][j][k * 2] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    cout << dp[n + m][m][0];
    return 0;
}