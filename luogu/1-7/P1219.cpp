#include<iostream>
#include<cstring>
using namespace std;
const int N = 20;
int n, path[N], cnt = 0;
int col[N], dg[N*2], udg[N*2];
void dfs(int u){

    if(u == n){
        if(cnt > 2){
            cnt++;
            return;
        }
        for(int i = 0; i < n; i++)  cout << path[i] << ' ';
        cnt++;
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!col[i] && !dg[u+i] && !udg[n-u+i]){
            path[u] = i + 1;
            col[i] = dg[u+i] = udg[n - u + i] = 1;
            dfs(u+1);
            col[i] = dg[u + i] = udg[n - u + i] = 0;
        } 
    }
}

int main(){

    cin >> n;

    dfs(0);
    cout << cnt;
    return 0;
}