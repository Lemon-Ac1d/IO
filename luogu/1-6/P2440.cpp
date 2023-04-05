#include <iostream>
#include <algorithm>

using namespace std;
long long n, k;
long long a[1000005];
bool check(long long x)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] / x);
    }
    return res >= k;
}

int main()
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long l = 1, r = 0x7fffffff;
    while (l < r)
    {
        long long mid = l + r + 1 >> 1;

        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;

    return 0;
}