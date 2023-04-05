#include<iostream>
#include<cstring>
using namespace std;
const int N = 2e3 + 10;
int f[N][N];
char a[N], b[N];


int main(){
    cin >> a+1 >> b + 1;
    int n = strlen(a+1), m = strlen(b+1);

    for(int i = 0; i <= n; i++)   f[i][0] = i;
    for(int i = 0; i <= m; i++)   f[0][i] = i;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
            f[i][j] = min(f[i][j], f[i-1][j-1] + (a[i]!=b[j]));
        }
    }
    cout << f[n][m] << endl;
    return 0;
}