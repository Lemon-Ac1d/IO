#include<iostream>

using namespace std;
const int N = 1e3 + 10;
int n, x;
int los[N], win[N], use[N];
long long  dp[N][N]; //
int main(){
    cin >> n >> x; // 人数 药数
    for(int i = 1; i <= n; i++){
        cin >> los[i] >> win[i] >> use[i];
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){ // 赢的人数
        for(int j = 0; j < use[i]; j++){
            dp[i][j] = dp[i-1][j] + los[i];
        }
        for(int j = use[i]; j <= x; j++){    // 药
            dp[i][j] = max(dp[i - 1][j] + los[i], dp[i - 1][j - use[i]] + win[i]);
        }
    }
    cout << dp[n][x] * 5;
    return 0;
}