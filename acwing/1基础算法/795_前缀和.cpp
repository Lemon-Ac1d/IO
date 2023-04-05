#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int l, r, n, m, a[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) a[i] += a[i-1];

    while(m--){
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }


    return 0;
}