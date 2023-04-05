#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
long long n, m, q[N];
long long mid, lec;

int main()
{
    long long l = 0, r = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        r = max(r,q[i]);
    }

    r--;

    while (l < r)
    {
        mid = l + r + 1 >> 1;   
        lec = 0;
        for (int i = 0; i < n; i++)
        {
            if (q[i] > mid)
                lec += q[i] - mid;
        }
        if (lec >= m)
            l = mid ;
        else
            r = mid -1;
    }
    cout << l;
    return 0;
}