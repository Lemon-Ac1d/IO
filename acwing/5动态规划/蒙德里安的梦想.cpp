#include<iostream>
#include<cstring>

using namespace std;
const int N = 12, M = 1 << N;
int n, m;
bool st[M];
long long f[N][M];
int main(){

    while(cin >> n >> m, n || m){
        for(int i = 0; i < 1 << n; i++){
            int cnt = 0;
            st[i]= true;//假设他是成立的
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }
                else cnt ++;
            }
            if(cnt & 1) st[i] = false;
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 1; i <= m; i++){ //所有列
            for(int j = 0; j < 1 << n; j++) //所有状态
                for(int k = 0; k < 1 << n; k++) // i-1列所有的状态
                    if((j & k) == 0 && st[j | k])
                        f[i][j] += f[i-1][k];
        }
        cout << f[m][0] << endl;
    }




    return 0;
}