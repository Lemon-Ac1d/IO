#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int mod = 80112002, N = 5e3 + 10, M = 5e5 + 10;
int n, m, a, b, ans;
vector<int> g[N];
int in[N], out[N], num[N];
queue<int> q;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        in[b]++;    
        out[a]++;
    }

    for(int i = 1; i <= n; i++)
        if(!in[i]){
            q.push(i);
            num[i] = 1;
        }


    while(!q.empty()){
        int t = q.front();
        q.pop();
        int len = g[t].size();
        for (int i = 0; i < len; i++)
        {
            int tmp = g[t][i];
            in[tmp]--;
            num[tmp] = (num[tmp] + num[t]) % mod;
            if (!in[tmp])   q.push(g[t][i]);
        }
    }

    for(int i = 1; i <= n; i++)
        if(!out[i])
            ans = (ans + num[i]) % mod;
    cout << ans;

    return 0;
}