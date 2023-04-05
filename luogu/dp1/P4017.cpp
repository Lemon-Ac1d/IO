#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int MOD = 80112002, N = 5010, M = 5e5 + 10;

int n, m, a, b, dp[N];
bool eat[N][N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        eat[b][a] = 1;
    }


    

    return 0;
}