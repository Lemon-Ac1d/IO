#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
const int INF = 2147483647;
int f[N], a[N], n, t, num[N];

int main(){
    int n = 0;
    while(cin >> a[++n]); --n;
    
    memset(f, 0, sizeof f);
    t = 0;f[0] = INF;
    for(int i = 1; i <= n; i++){
        int l = 0, r = t;
        while(l < r){
            int mid = l + r + 1>> 1;
            if(f[mid] >= a[i]) l = mid;
            else r = mid - 1; 
        }
        
        int x = l + 1;
        if(x > t)   t = x;
        f[x] = a[i];
        // for(int i = 1; i < 7; i++)cout << f[i] << "   ";
        // puts("");
    }
    
    cout << t << endl;

    memset(f, 0, sizeof f);
    t = 0; f[0] = 0;
    for(int i = 1; i <= n; i++){
        int l = 0, r = t ;
        while(l < r){
            int mid = l + r + 1>> 1;
            if(f[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        int x = l + 1;
        if(x > t)   t = x;
        f[x] = a[i];
    }
    cout << t << endl;



    // memset(f, 0, sizeof f);
    // t = 0;f[0] = 0;
    // for(int i = 1; i <= n; i++){
    //     int l = 0, r = t + 1;
    //     while(r - l > 1){
    //         int mid = l + (r - l) / 2;
    //         if(f[mid] < a[i]) l = mid;
    //         else r = mid;
    //     }
    //     int x = l + 1;
    //     if (x > t)
    //         t = x;
    //     f[x] = a[i];
    //         // for(int i = 1; i < 7; i++)cout << f[i] << "   ";
    //         // puts("");
    // }
    // cout << t << endl;
    return 0;
}