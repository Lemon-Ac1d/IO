#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const int N = 1e5 + 10;

int s[N];

int main(){
    int m, n;
    cin >> m >> n;

    for(int i = 0; i < m; i++){
        cin >> s[i];
    }

    sort(s,s+m);
    long long res = 0;
    while(n--){
        int x;
        cin >> x;

        int l = 0, r = m-1;
        while(l < r){
            int mid = l + r >> 1;
            if(s[mid] <= x) l = mid + 1;
            else r = mid;
        }
        // cout << x << "    " << s[l] << endl;
        if (x <= s[0]) // 这里需要特判断一下，不然只能得70分
        {
            res += s[0] - x;
        }else
        res += min(abs(s[l-1] - x),abs(s[l] - x));
    }

    cout << res;
    return 0;
}