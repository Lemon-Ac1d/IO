#include<bits/stdc++.h>

using namespace std;

void dfs(int k, int x ,int y ,int sx,int sy){
    // k 是阶数     x,y是公主的位置     sx,sy是正方形左下角方块的位置
    if(k==0)return;
    int t = (1 << k-1);//正方形的边长
    if(x < sx+t && y < sy+t){
        //左下角
        printf("%d %d %d\n",sx+t,sy+t,3);
        dfs(k-1,x,y,sx,sy);
        dfs(k-1,sx+t,sy+t-1,sx+t,sy);
        dfs(k-1,sx+t,sy+t,sx+t,sx+t);
        dfs(k-1,sx+t-1,sy+t,sx,sy+t);
    }
    else if(y<sy+t){
        //右下角
        printf("%d %d %d\n",sx+t-1,sy+t,4);
        dfs(k-1,sx,sy,sx+t-1,sy+t-1);
        dfs(k-1,x,y,sx+t,sy);
        dfs(k-1,sx+t,sy+t,sx+t,sy+t);
        dfs(k-1,sx+t-1,sy+t,sx,sy+t);
    }
    else if(x > sx+t){
        //右上角
        printf("%d %d %d\n",sx+t-1,sy+t-1,2);
        dfs(k-1,sx,sy,sx+t-1,sy+t-1);
        dfs(k-1,sx+t,sy+t-1,sx+t,sy);
        dfs(k-1,x,y,sx+t,sy+t);
        dfs(k-1,sx+t-1,sy+t,sx,sy+t);
    }
    else{
        //左上角
        printf("%d %d %d\n",sx+t,sy+t-1,1);
        dfs(k-1,sx+t-1,sy+t-1,sx,sy);
        dfs(k-1,sx+t,sy+t-1,sx+t,sy);
        dfs(k-1,sx+t,sy+t,sx+t,sy+t);
        dfs(k-1,x,y,sx,sy+t);
    }
}

int main(){
    ios::sync_with_stdio(false);

    int k,x,y;
    cin >> k >> x >> y;

    dfs(k,x,y,1,1);

    return 0;
}
