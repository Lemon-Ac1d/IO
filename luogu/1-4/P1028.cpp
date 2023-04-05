#include<bits/stdc++.h>

using namespace std;
long num[1003]={0},n;

void f(int i){
    if(i>n) return;
    num[i]=1;
    for(int j = 1 ; j*2 <= i ; j++){
        num[i] += num[j];
    }
    f(++i);
}
int main(){
    ios::sync_with_stdio(false);
    num [1]=1;
    cin >> n;

    f(2);
    cout << num[n];
    return 0;
}