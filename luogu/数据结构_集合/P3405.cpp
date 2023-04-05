#include<iostream>

using namespace std;
long long n, ans;
int co[28282828] = {0};
string c, p;

int main(){
    cin >> n;
    while(n--)
    {
        cin >> c >> p;
        int x = (c[0] - 'A') * 100 + c[1] - 'A';
        int y = (p[0] - 'A') * 100 + p[1] - 'A';
        if (co[y * 10000 + x] && y != x)
            ans += co[y * 10000 + x];
        // 累加与前面城市的特殊城市对数
        co[x * 10000 + y]++; // 把拼接成的数记录下来
    }
    cout  << ans << endl;
    return 0;
}