#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int,int> PII;
PII a[20];
int n, res = 0x3f3f3f;

void dfs(int x, int s, int b, int tt){
    // 层数 总酸度 总苦度 已经添加了多少种
    if(x == n && tt > 0){
        res = min(res, abs(s-b));
        return;
    }
    if(x > n)   return;
    // 添加
    dfs(x+1, s * a[x].first, b + a[x].second, tt + 1);
    dfs(x+1, s, b, tt);
}

int main(){
    
    cin >> n;
    
    for(int i = 0; i < n; i++)  cin >> a[i].first >> a[i].second;

    dfs(0, 1, 0, 0);

    cout << res << endl;

    return 0;
}