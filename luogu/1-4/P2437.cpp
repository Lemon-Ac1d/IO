#include<bits/stdc++.h>

using namespace std;

long long ans[3][301];

void add ( int i ){

}

int main(){
    ios::sync_with_stdio(false);

    long m,n;
    cin >> m;
    cin >> n; 
    n -= (m-1);

    memset(ans,0,sizeof(ans));
    ans[1][300] = 1;
    ans[2][300] = 1;

    for(int i=3; i <= n ; i++){
        int k=0;//进位标识符
        for(int j=300 ; j ;j--){
            ans[i%3][j] = ans[(i-1)%3][j] + ans[(i-2)%3][j] + k;
            k = ans[i%3][j]/10;
            ans[i%3][j] %= 10;
        }
    }
    int i = 0; 
    while(!ans[n%3][i++]);
    i--;
    while( i!= 301) cout << ans[n%3][i++];
    return 0;
}