#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }

    while (m--)
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (q[l] == x)
            cout << l << " ";
        else
            cout << "-1" << ' ';
    }

    return 0;
}