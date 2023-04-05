#include<bits/stdc++.h>

using namespace std;
const int MAX = 5000;

struct Node{
    int p,a;
}a[MAX];

bool cmp(Node a, Node b){
    return a.p < b.p;
}
int main(){
    ios::sync_with_stdio(false);
    int n,m,t=0;
    int res = 0;
    cin >> m >> n;
    while( t < n)
        cin >> a[t].p >> a[t++].a;

    sort(a, a+n, cmp);
    t=0;

    while(m){
        if(a[t].a != 0){
            a[t].a--;
            res += a[t].p;
            //cout <<res;
            m--;
        }
        else t++;
    }
    cout << res;

    return 0;
}