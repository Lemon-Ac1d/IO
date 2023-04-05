#include<bits/stdc++.h>

using namespace std;
int dp [1000007];
int g [1000007];
const int mod = 10000;
int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    dp [1] = 1;dp [0] =1;
    g[1] = 1 ; 
    for(int i=2;i<=n;i++){
        dp [ i ] = (dp [i-1]%mod + dp [i-2]%mod + g[i-2]*2 % mod )% mod;
        g[i] = (g[i-1] + dp[i-1] ) % mod ;
    }    
    
    cout << dp[n];
    
    return 0;
}