#include<bits/stdc++.h>

using namespace std;
struct Node{
    int w, v;
}a[110];

bool cmp(Node aa, Node bb){
    return aa.v * bb.w > bb.v * aa.w;

}
int main(){
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> a[i].w >> a[i].v;
    sort(a,a+n,cmp);
    double value;
    for(int i = 0; i < n; i++){
       
        if(a[i].w <= t){
            value += a[i].v;
            t -= a[i].w;
        }
        else{
            value += a[i].v  * 1.0  * t / (a[i].w * 1.0) ;
            break;
        }

        
    }
    printf("%.2lf",value);

    return 0;
}