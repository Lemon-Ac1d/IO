#include<iostream>

using namespace std;
const int N = 1e4 + 10;
int n, m;
int h[N], e[N * 2], ne[N * 2];

int find(int x)
{
    if(h[x] != x)   h[x] = find(h[x]);
    return h[x];
}

int main(){
    while(true)
    {
        cin >> n;
        if(n == 0)  return 0;

        for (int i = 1; i <= n; i++)
            h[i] = i;
        cin >> m;
        while(m--)
        {
            int x, y;
            cin >> x >> y;
            int a = find(x), b = find(y);
            if(a != b)  
            {
                h[a] = b;
                n--;
            }
        }
        cout << n - 1  << endl;

    }

    return 0;
}