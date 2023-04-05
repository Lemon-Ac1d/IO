#include<bits/stdc++.h>

using namespace std;



int main(){
    int sum=0;
    int n[4],s[22],dp[1300];
    int res=0;
    for(int i=0;i<4;i++)
        cin>>n[i];

    for(int i=0;i<4;i++){
        sum=0;
        memset(dp,0,sizeof(dp));
        for(int j=0;j<n[i];j++){
            cin>>s[j];
            sum+=s[j];
        }

        for(int j=0;j<n[i];j++){
            for(int k=sum/2;k>=s[j];k--){
                dp[k]=max(dp[k],dp[k-s[j]]+s[j]);
            }
        }
        res+=sum-dp[sum/2];

    }
    cout<<res;
    return 0;
}