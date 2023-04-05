#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int a[N], tt, hh;
int n;

int main()
{
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            cin >> a[tt++];
        }
        else if (op == "empty")
        {
            if (hh == tt)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (op == "pop")
        {
            hh++;
        }
        else
        {
            cout << a[hh] << endl;
        }
    }

    return 0;
}