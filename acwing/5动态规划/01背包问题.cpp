#include<iostream>

using namespace std;

const int N = 1e3 + 10;
int w[N], v[N],dp[N];
int n, V;
bool vis[N];
int main(){
    cin >> n >> V;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = V; j >= v[i]; j--){
            dp[j] = max(dp[j - v[i]] + w[i], dp[j]);
        }
    }
    
    cout << dp[V];
    
    return 0;
}