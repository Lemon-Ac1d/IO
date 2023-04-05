#include<iostream>

using namespace std;
const int N = 1e3 + 10, M = 5e3 + 10;
int h[N], cnt[N];

int find(int x)
{
    return h[x] == x ? h[x] : find(h[x]);
}

int main(){
    int n, m, p, q, ans = 0;
    cin >> n >> m;
    char op;
    
    for(int i = 1; i <= 2 * n; i++) h[i] = i;

    while(m--){
        cin >> op >> p >> q;
        if(op == 'F'){
            h[find(p)] = find(q);
        }
        else{
            h[find(p + n)] = find(q);
            h[find(q + n)] = find(p);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (h[i] == i)
            ans++;
    }
    cout << ans << endl; // 祖先数就是团伙数
    return 0;
}