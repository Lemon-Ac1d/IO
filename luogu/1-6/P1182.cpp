#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N];
int l = 0, r = 0, mid,n,m;

bool check(int x){
    int t = m;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(t < 0)
            break;
        if(q[i] + sum <= x){
            sum += q[i];
        }

        else{
            sum = q[i];
            t--;
        }
    }
    return t<=0;
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++)  {
        cin >> q[i];
        if(q[i] > l)    l= q[i];
        r+=q[i];
    }
    
    while(l <= r){
        mid = l + r >> 1;

        if(check(mid)){

            l = mid + 1;
        }
        else   r = mid - 1;
    }   
    

    cout << l;
    return 0;
}