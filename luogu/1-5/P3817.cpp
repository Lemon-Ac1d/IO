#include<bits/stdc++.h>

using namespace std;

const int MAX = 10e5 + 10;
int a[MAX];

int main(){
    ios::sync_with_stdio(false);
    int n,x;
    long long res=0;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        if((a[i-1] + a[i]) <= x)
            continue;
        else{
            int tmp = (a[i - 1] + a[i]) - x;
            res += tmp;
            if( (a[i] - tmp) < 0){
                a[i-1] = a[i] - (tmp - a[i-1]);
                a[i] = 0;
            }
            else{
                a[i] -= tmp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    //     cout << a[i];
    // cout <<endl;
    cout << res;    
    return 0;
}