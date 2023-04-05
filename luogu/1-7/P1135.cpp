#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
const int N = 210;

int f[N];
int n, a, b;
bool vis[N];

int main(){

    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)  cin >> f[i];

    queue<PII> q;
    q.push({a,0});
    memset(vis,false,sizeof(vis));
    vis[a] = true;
    while(!q.empty()){
        auto t = q.front();
        int xx = t.first, step = t.second;
        q.pop();
        if(xx == b){
            cout << step;
            break;
        }
        int u = xx + f[xx], v = xx - f[xx];
        if(u <= n && !vis[u]){
            q.push({u,step+1});
            vis[u] = true;
        }
        if(v > 0 && !vis[v]){
            q.push({v,step+1});
            vis[v] = true;
        }
    }    
    
    if(!vis[b])
    cout << "-1" << endl;

    return 0;
}