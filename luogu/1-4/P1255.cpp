#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int f[3][201];
    memset(f,0,sizeof(f));
    f[1][200]=1;f[2][200]=2;f[0][200]=3;

    for(int i =4;i<=n;i++){
        int g=0;
        for(int j=200;j;j--){
        //for(int j=200;f[(i+1)%3][j]||f[(i+2)%3][j]||g;j--){
        //错误原因：存在10009+10000  运算到第二位 条件分别是 0 0 0提前停止了
            f[i%3][j]=( f[(i+1)%3][j]+f[(i+2)%3][j] +g) % 10;
            g=( f[(i+1)%3][j]+f[(i+2)%3][j] +g) / 10;
        }
    }
    int i=0;
    while(!f[n%3][++i]);

    while(i<201)
        cout << f[n%3][i++];

    return 0;;
}