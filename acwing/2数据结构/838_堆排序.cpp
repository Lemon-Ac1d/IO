#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int h[N], cnt;

int m, n;

void down(int x)
{
    int t = x;
    if(x * 2 <= cnt && h[x*2] < h[t])    t = x * 2;
    if(x * 2 + 1 <= cnt && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
    if(t != x)
    {
        swap(h[x], h[t]);
        down(t);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)  cin >> h[i];
    cnt = n;
    for(int i = n / 2; i; i--)  down(i);

    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[cnt--];
        down(1);
    }
    puts("");
    return 0;
}