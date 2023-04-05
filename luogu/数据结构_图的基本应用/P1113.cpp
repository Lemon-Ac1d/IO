#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e4 + 10;
int n, num, to, tmp;
vector<int> a[N];
int t[N], d[N];
bool vis[N];

int dfs(int x){
    if(d[x])    return d[x];
    for(int i = 0; i < a[x].size(); i++){
        d[x] = max(d[x], dfs(a[x][i]));
    }
    d[x] += t[x];
    return d[x];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num >> tmp >> to;
        t[num] = tmp;
        while(to){
            a[num].push_back(to);
            cin >> to;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, dfs(i)); 
    }
    cout << res  << endl;
    return 0;
}