#include<iostream>

using namespace std;

const int N = 2e6 + 10;
int e[N], idx = 1, ne[N];
int m, n, tmp;

void add(int x)
{
    e[idx++] = x;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        add(tmp);
    }


    while(m--)
    {
        cin >> tmp;
        cout << e[tmp] << endl;
    }
    return 0;
}