#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    string s;
    long long n,i;
    cin >> s >> n;

    long long num = s.length();

    while (n > num ){
        i = num;
        while(n>i) i <<= 1; //num*2

        i = i/2;
        n -=(i+1);
        if(n==0) n = i;
    }
    cout << s[n-1];
    return 0;
}