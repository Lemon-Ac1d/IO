#include<bits/stdc++.h>

using namespace std;
struct node{
    int l, w;
    bool operator < (const node &x) const {
        return l == x.l ? w > x.w : l > x.l;
    }
}a[5050];

int n, f[5050], ans = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].w;
    }
    sort(a + 1, a + n + 1);


    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(a[i].w > a[j].w) f[i] = max(f[i],f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans + 1 << endl;
    return 0;
}