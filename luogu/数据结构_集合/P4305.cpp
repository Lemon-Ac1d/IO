#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 50021;
const int mod = N;
int a[N];
int st[N];
int read()
{
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, tmp;
        memset(st, 0, sizeof st);
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            tmp = read();
            int num = ((tmp % mod) + mod ) % mod;
            if(!st[num])    cout << tmp << " ";
            st[num] = true;
        }
        puts("");

    }

    return 0;
}