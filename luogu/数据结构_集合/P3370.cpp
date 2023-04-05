#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int base = 131, N = 1e4 + 10;
char s[1600];
ull a[N];
ull mod = 212370440130137957ll;
ull haxi(char s[])
{
    int lec = strlen(s);
    ull res = 0;
    for(int i = 0; i < lec; i++)
    {
        res += (res * base + (ull)s[i]) % mod;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        a[i] = haxi(s);
    }
    sort(a + 1, a + n + 1);
    ull ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i + 1])
            ans++;
    }
    cout << ans + 1;
    return 0;
}