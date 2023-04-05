#include<iostream>

using namespace std;

long long a, b, n;

int main(){
    cin >> a >> b >> n;

    long long t = n % (a * 5 + b * 2);
    long long ans = n / (a * 5+ b * 2) * 7;

    for(int i = 1; i < 8; i++){
        if(i < 6)   t -= a;
        else t -= b;
        if(t <= 0){
            ans += i;
            break;
        }
    }
    cout << ans;

    return 0;
}