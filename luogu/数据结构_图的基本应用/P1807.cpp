#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 1510, M = 5e4 + 10, null = 0x3f3f3f3f, mod = 1e5;

int n, m, u, v, w;
int g[N][N], dist[N];

int bfs(){
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while(q.size()){
        auto t = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(g[t][i] && dist[i] < dist[t] + g[t][i]){
                dist[i] = dist[t] + g[t][i];
                q.push(i);
            }
        }
    }
    return dist[n];
}


int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        g[u][v] = max(g[u][v], w);
    }

    cout << bfs();

    return 0;
}