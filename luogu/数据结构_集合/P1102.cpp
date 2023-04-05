#include<iostream>
#include<map>

using namespace std;
typedef long long ll;
const int N =  2e5 + 10;
ll a[N], res;
map<ll, ll> m;
int main(){
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] ++ ;
        a[i] -= c;
    }
    for(int i = 0; i < n; i++)  res += m[a[i]];
    cout << res;
    return 0;
}