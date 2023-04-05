#include <iostream>

using namespace std;
const int N = 2e5 + 10;
int t, n, a[N], sum;

bool check(int gcd, int &pos)
{
    int t = 0, i = pos + 1;
    for (; i <= n; i++)
    {
        if (t && t % gcd == 0)
            t = 0;
        t += a[i];
    }
    pos = --i;
    if (t && t % gcd == 0)
        return true;
    else
        return false;
}

int binary(int l, int r)
{
    if (l >= r)
        return l;
    int mid = l + r + 1 >> 1;
    int pos = 0;
    if (check(mid, pos))
        return binary(mid, r);
    else
        return binary(l, mid - 1);
}
int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        // cout <<  sum << endl;
        cout << binary(1, sum / 2) << endl;
    }

    return 0;
}