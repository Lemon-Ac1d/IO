#include<iostream>
#include<math.h>
using namespace std;

double l = -1000.0, r = 1000.0;
double n;
int main(){
    cin >> n;
    while(r - l > 1e-7){
        double mid = (l + r) / 2;
        if(pow(mid, 3) < n) l = mid;
        else r = mid;
    }
    printf("%.6lf", l);
    return 0;
}