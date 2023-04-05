#include<bits/stdc++.h>

using namespace std;
const int MAX = 3 * 10e4 +10;
int a[MAX];
bool b[MAX];
int main(){
    ios::sync_with_stdio(false);
    int w,n,res = 0;
    cin >> w >> n;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    memset(b,sizeof(b),0);

    sort(a,a+n);
    //for(int i=0;i<n;i++)cout<< a[i]<<endl;
    for(int i = 0; i < n; i++){
        if(b[i])    continue;
        for(int j = n-1; j >=0; j--){
            if(b[j])    continue;
            if((a[i] + a[j]) <= w){
                res ++;
                b[i] = 1;
                b[j] = 1;
                //cout << a[i] <<"&" << a[j] <<  j << endl;
                break;
            }
        }
        if(!b[i]){
            res++;
            b[i]=1;
        }
    }

    cout << res;
    
    return 0;
}