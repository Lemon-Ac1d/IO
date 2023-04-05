#include<iostream>

using namespace std;
const int N = 1e3 + 10, MOD = 998244353, M = 2e4 + 10;
long long a[N], f[N][M*2];

int main(){
    int n; 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans++;
        for(int j = i-1; j; j--){
            f[i][a[i]- a[j] + M] += f[j][a[i] - a[j] + M] + 1;
            f[i][a[i] - a[j] + M] %= MOD;
            ans += f[j][a[i] - a[j] + M] + 1;
            ans %= MOD;
        }
    }
    cout << ans;
    

    return 0;
}