#include<bits/stdc++.h>

using namespace std;
const int MAX = 10e5 + 10;
int n,a[MAX], l = 1, r = 1, cont = 0;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        while(a[i] != 0)
        {
            r = i;
            a[i]--;
            while(a[++r] != 0){
                a[r]--;
            };
            cont ++;
        }
    }
    cout << cont;

    return 0;
}