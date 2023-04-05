#include<iostream>
#include <iomanip>
using namespace std;


int main(){
    int s, n, m;
    cin >> s >> n >> m;
    
    double l = 0, r = 1000, a, mid;
    while(r - l > 0.0001){
        mid = (l + r) /2;
        a = s;
        for(int i = 0; i < m; i++){
            a = a*(1 + mid) - n;
        }
        if (a > 0)
            r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(1) << mid * 100;
    return 0;
}