#include<iostream>

using namespace std;
const int N = 2e4 + 10;
int n, m, p;
int h[N], e[N], ne[N];

int find(int x)
{
    if(h[x] != x)   h[x] = find(h[x]);
    return h[x];
}


int main()
{
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) h[i] = i;
    
    while(m--)
    {
        int mi, mj;
        cin >> mi >> mj;
        int a = find(mi), b = find(mj);
        // cout << a << "___" << b << endl;
        if(a != b)  h[a] = b;
        // for (int i = 1; i <= n; i++)
        //     cout << h[i] << ' ';
        // cout << endl;
    }
    
    while(p--)
    {
        int x, y;
        cin >> x >> y;
        if(find(x) == find(y))    puts("Yes");
        else puts("No");
    }

    return 0;
}