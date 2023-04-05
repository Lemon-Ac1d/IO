#include<iostream>

using namespace std;

int n, tmp;
int a[22], dp[22];
bool con[22][22], ans[22];
int h[22];
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
        h[i] = i;
    }

    for(int i = 1; i < n; i++){
        for(int j  = i + 1; j <= n; j++){
            cin >> tmp;
            if(tmp)
                con[i][j] = 1;
        }
    }


    for(int i = n - 1; i > 0; i--){
        int max = 0;
        for(int j = i + 1; j <= n; j++){
            if(con[i][j] && dp[j] > dp[max]){
                max = j;
            }
        }
        if(max){
            dp[i] += dp[max];
            h[i] = max;
        }
    }
    int max = 1;
    for(int i = 2; i <= n; i++){
        if(dp[i] > dp[max]) max = i;
    }
    int i = max;
    cout << i << " ";
    while(h[i] != i){
        cout << h[i] << ' ';
        i = h[i];
    }
    puts("");
    cout << dp[max];

    return 0;
}