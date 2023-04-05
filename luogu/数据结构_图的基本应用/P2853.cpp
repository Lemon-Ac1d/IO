#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
const int N = 1010, M = 1e4 + 10;
int k, n, m, tmp, a, b;
vector<int> g[N]; 
int h[110], mk[N];
bool vis[N];
void dfs(int x){
    vis[x] = true; mk[x] ++;
    for(int i = 0; i < g[x].size(); i++){
        if(!vis[g[x][i]])
            dfs(g[x][i]);
    }
}

int main(){
    cin >> k >> n >> m;

    for(int i = 1; i <= k; i++) {
        cin >> tmp;
        h[i] = tmp;
    }

    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= k; i++){
        memset(vis, 0, sizeof vis);
        dfs(h[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(mk[i] == k)  ans++;
    }
    cout << ans << endl;
    return 0;
}