#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;
int n;

int main(){
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        while(tt && stk[tt] >= x)    tt--;
        if(!tt) cout << "-1" << " ";
        else cout << stk[tt] << " ";
        stk[++tt] = x;
    }

    return 0;
}