#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int N = 1e5 + 10;
vector<int> a[N];
int n, m, u, v;
bool vis[N];
int dp[N];
void dfs(int x, int d){
    if(dp[x])   return;
    dp[x] = d;
    for(int i = 0; i < a[x].size(); i++)
        dfs(a[x][i], d);
}

int main(){
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        a[v].push_back(u);
    }
    for (int i = n; i; i--)
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        printf("%d ", dp[i]);
    return 0;
}