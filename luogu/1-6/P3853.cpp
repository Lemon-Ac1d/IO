#include<iostream>

using namespace std;
const int N = 10000000 + 10;
int q[N];
int d, n, k;
bool check(int x){
    int y = k;
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(y < 0){
            break;
        }
        if(q[i] - pos <= x){
            pos = q[i];
        }
        else{
            pos += x;
            i--;
            y--;
        }
    }

    return y>=0;
}

int main()
{

    cin >> d >> n >> k;

    for(int i = 0; i < n; i++)  cin >> q[i];

    q[n] = d;

    long long l = 0, r = d, res = 0, mid;

    while(l <= r){
        mid = l + r >> 1;
        if(check(mid)){
            res = mid;
            r = mid -1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}