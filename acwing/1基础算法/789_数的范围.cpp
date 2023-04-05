#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int n, q, k;

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--)
    {
        cin >> k;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != k)
        {
            cout << "-1 -1" << endl;
        }
        else
        {
            cout << l - 1 << " ";
            int r = n;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << r - 1 << endl;
        }
    }

    return 0;
}