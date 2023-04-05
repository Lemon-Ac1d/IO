#include<iostream>

using namespace std;
// p = 131/13331 Q = 2^64
// 一般不会发生冲突

typedef unsigned long long ULL;
const int N = 100010, P = 131;
char str[N];
ULL h[N], p[N];
int n, m;

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
//20406103

int main(){
    cin >> n >> m;

    cin >> str + 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }

    while(m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1, r1) == get(l2, r2))  puts("Yes");
        else puts("No");
    }

    return 0;
}