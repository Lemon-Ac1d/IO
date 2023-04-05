#include<iostream>

using namespace std;
const int M = 110, N = 1010;

int m, n, q[N], hh, tt, res;
bool st[M];
int main()
{
    cin >> m >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(!st[tmp])
        {
            st[tmp] = true;
            res++;
            if( (tt - hh) + 1 > m)
            {
                st[q[hh++]] = false;
            }
            q[tt++] = tmp;
        }
    }
    cout << res;
    return 0;
}