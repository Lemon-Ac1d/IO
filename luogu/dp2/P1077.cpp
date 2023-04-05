#include<iostream>

using namespace std;
const int MOD = 1e6 + 7;
int n, m;
int a[110], f[110][110];

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];
    f[0][0] = 1;

    for(int i = 0; i <= m; i++){ // 花盆
        for(int j = 1; j <= n; j++){ // 花
            for(int k = 0; k <= min(a[j], i ); k++)
                    f[i][j] = (f[i][j] + f[i-k][j - 1]) % MOD;
        }
    }
    cout << f[m][n];

    return 0;
}