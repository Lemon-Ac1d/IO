#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int p[N];

int n, m, a, b;
string op;

int find(int x)
{
    if(p[x] != x)   p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;

    while(m--)
    {
        cin >> op >> a >> b;
        if(op == "M")
        {
            p[find(a)] = find(b);
        }
        else
        {
            if(find(a) == find(b))  cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}