#include<iostream>

using namespace std;
int l, n, m, tmp,ans;
const int N = 5e4 + 10;
int q[N], hq[N];

bool check(int x){
    int tt = 0;
    int i = 0; // i代表下一块石头的编号
    int now = 0; // now代表模拟跳石头的人当前在什么位置
    while(i < n + 1){
        i++;
        if(q[i] - q[now] < x)
            tt++;
        else now = i;
    }

    return tt <= m;
}

int main(){

    cin >> l >> n >> m;
    for(int i = 1; i <= n; i++) cin >> q[i];
    q[n+1] = l;

    int left = 1, right = l, mid;

    while(left <= right){
        mid = left + right >> 1;
        if(check(mid)){
            ans = mid;
            left = mid + 1;
        }
        else    right = mid - 1;
        
    }
    cout << ans;

    return 0;
}