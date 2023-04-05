#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 10;
int q[N];

int main(){
    int n,c;
    long long res = 0;
    cin >> n >> c;
    
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }

    sort(q,q+n);

    for(int i = 0; i < n; i++){
        int l = 0, r = i, x = q[i]-c;
        if(q[l] == q[r])  continue;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= x)  r = mid;
            else l = mid + 1;
        }
        if(q[l] == x){
            int s = l;
            int l = s, r = n;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            res += l - s + 1;
        }
    }
    cout << res;
    return 0;
}