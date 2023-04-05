#include<bits/stdc++.h>

using namespace std;
int t,n;
int f(int n){
    if(!n%2){
        cout << "-1";
    }
    else{
        cout << "0" << " "<< " " << n/2;
    }
}
int main(){
    ios::sync_with_stdio(false);

    cin >> t;

    while(t--){
        cin >> n;
        f(n);
    }

    return 0;
}