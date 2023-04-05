#include<iostream>
#include<map>

using namespace std;
int n, q, p, k;
map<long long, int> mp;
long long i, j;

int main()
{
    cin >> n >> q;
    while(q--)
    {
        cin >> p >> i >> j;
        if(p == 1)
        {
            cin >> k;
            mp[i*1e5 + j] = k;
        }
        else cout << mp[i * 1e5 + j] << endl;
    }

    return 0;
}