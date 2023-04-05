#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int n, m, x;
int a[N], b[N];

int main(){
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1, j = m ; i <= n; i++){
        while(j && a[i] + b[j] > x) j--;
        if(j >= 0 && a[i] + b[j] == x)
            cout << i-1 << ' ' << j-1 << endl;
    }

    return 0;
}