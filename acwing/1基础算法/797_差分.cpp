#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, l, r, c;
int s[N], a[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) s[i] = a[i] - a[i-1];


    while(m--){
        cin >> l >> r >> c;
        s[l] += c;
        s[r + 1] -= c;
    }

    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + s[i];
        cout << a[i] << " ";
    }

    return 0;
}