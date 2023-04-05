#include<iostream>

using namespace std;

const int N = 1e3 + 10;
int dp[N][N], a[N][N];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }

    dp[1][1] = a[1][1];

    for(int i = 1; i < n; i++){
        int k = 2;
        dp[i + 1][1] = dp[i][1] + a[i + 1][1];
        dp[i + 1][i + 1] = dp[i][i] + a[i + 1][i + 1];
        for(int j = 1; j <= i; j++){
            dp[i + 1][k] = max(dp[i][j],dp[i][j + 1]) + a[i+1][k];
            // if (i == 3){
            //     cout << dp[i][j] << ' ' << dp[i][j + 1] << endl;
            // }
            k++;
        }
    }

    
    int max = 0;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++)
    //     cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++){
        if(dp[n][i] > max)  max = dp[n][i];
    }
    cout << max;

    return 0;
}