#include<bits/stdc++.h>

using namespace std;
int n,ans=0x7fffffff,s[11],b[11];
void dfs(int i,int x, int y){
    if(i>n){
        if(x==1 && y==0)return;
        ans=min(abs(x-y),ans);
        return;
    }
    dfs(i+1,x,y);
    dfs(i+1,x*s[i],y+b[i]);
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin >> s[i] >> b[i];
    }

    dfs(1,1,0);
    cout <<ans;
    return 0;;
}