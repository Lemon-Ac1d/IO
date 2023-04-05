#include<bits/stdc++.h>

using namespace std;
typedef struct point{
    int x;
    int y;
}point;
point b,c,d[9];
int cmp(int a ,int b){
    for(int i=0;i<9;i++){
        if(a==d[i].x && b==d[i].y)
        return 0;
    }
    return 1;

}
int main(){
    ios::sync_with_stdio(false);

    cin >> b.x >> b.y >> c.x >> c.y ;
    d[0]=c;
    d[1].x=c.x+2;d[1].y=c.y+1;
    d[2].x=c.x+1;d[2].y=c.y+2;
    d[3].x=c.x-1;d[3].y=c.y+2;
    d[4].x=c.x-2;d[4].y=c.y+1;
    d[5].x=c.x-2;d[5].y=c.y-1;
    d[6].x=c.x-1;d[6].y=c.y-2;
    d[7].x=c.x+1;d[7].y=c.y-2;
    d[8].x=c.x+2;d[8].y=c.y-1;
    // for(int i=0;i<9;i++){
    //     cout << d[i].x << " "<< d[i].y<<endl;
    // }
    
    long long dp[22][22];
    
    for(int i=0;i<=b.x;i++){//x轴
        for(int j=0; j <= b.y ; j++){//y轴
            if(!cmp(i,j)){
                dp[i][j]=0;
            }
            else{
                if(i==0&&j==0)dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j];
                
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            
            //cout << "dp["<< i<<" "<<j << "]="<<dp[i][j]<<" ";
            //cout << dp[i][j]<<" ";
        }
        //cout <<endl;
    }
    //cout << cmp(4,0)<<endl;
    cout << dp[b.x][b.y];
    return 0;
}