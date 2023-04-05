#include<bits/stdc++.h>

using namespace std;

int a[55];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    long long res = 0;
    cin >> n;
    a[0] = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a,a+n,cmp);

    //res += a[0] * a[0];

    int last = 0, i = 0,j = 0;
    while(j < n){
        //cout << a[i] << ' ' << last << "   " ;
        res += pow((a[i] - last), 2);
        //cout << res << endl;
        last = a[i];
        j++;
        if(j % 2){
            i = n - 1 -(j/2);
        }else{
            i = (j/2);
        }
        //j++;
    }

    cout << res;

    return 0;
}