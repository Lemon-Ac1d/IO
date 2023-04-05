#include<bits/stdc++.h>

using namespace std;

long long m,n;

int dp [102][10004]={0};

int a[102];

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m;//菜  钱  

    for(int i=1;i<=n;i++)    cin >> a[i];

    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==a[i]) dp[i][j]=dp[i-1][j]+1;
            else if(j < a[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i]];
        }
    }

    cout << dp[n][m];
    return 0;
}