#include<bits/stdc++.h>

using namespace std;
long long n,dp[20];

int main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    dp[0]=1;dp[1]=1;dp[2]=2;
    for(int i = 3; i <= n; i++){
        dp[i]=0;
        for(int j = 1; j <= i ; j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
        
    }
    cout<< dp[n];

    return 0;
}