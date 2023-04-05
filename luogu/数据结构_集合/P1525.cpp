#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 20009;
const int maxm = 200019;
struct Edge // 定义边:起点nex,终点to,边权w
{
    int nex, to, w;
} p[maxm];
int n, m, fa[maxn], Enemy[maxn];

int find(int k) // 并查集找父亲
{
    if (fa[k] != k) fa[k] = find(fa[k]);
    return fa[k];
}
bool cmp(Edge x, Edge y)
{
    return x.w > y.w;
}
int main(){
    int n,m;
    cin >> n >> m;

    for(int i = 1 ; i <= m; i++){
        cin >> p[i].nex >> p[i].to >> p[i].w;
    }
    for(int i = 1; i <=n; i++)  fa[i] = i;
    sort(p+1, p + 1 + m, cmp);

    for(int i = 1; i <= m; i++)
    {
        int x = find(p[i].nex), y = find(p[i].to);
        if(x == y){
            cout << p[i].w;
            return 0;
        }
        if (!Enemy[p[i].nex])
            Enemy[p[i].nex] = p[i].to;
        else
            fa[find(Enemy[p[i].nex])] = find(p[i].to);
        // 同上
        if (!Enemy[p[i].to])
            Enemy[p[i].to] = p[i].nex;
        else
            fa[find(Enemy[p[i].to])] = find(p[i].nex);
    }
    printf("0"); // 没有矛盾
    return 0;
}