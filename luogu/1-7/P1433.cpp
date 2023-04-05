#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;

const int N = 210;
int n, x, y;
pair<int, int > f[N];
bool vis[N] = {0};
double path = 0x3f3f3f3f;

void dfs(int s, double res, int u, int v, int ne)
//s表示吃了已经吃了多少个奶酪 res表示已经走了多少路 u，v 表示当前位置
{
    if(s == n)
    {
        path = min(path,res);
        return;
    }
    // 吃
    if(ne != -1)
        vis[ne] = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        int xx = f[i].first, yy = f[i].second;
        double p = sqrt(pow(xx - u, 2) + pow(yy - v, 2));
        vis[i] = 1;
        
        dfs(s + 1, res + p, xx, yy, -1);
        // 不吃
        if(s==n-1)  return;
        dfs( s, res, u, v, ne);

    }


}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> f[i].first >> f[i].second;
    }

    dfs(0,0,0,0,-1);
    printf("%.2lf",path);
    return 0;
}