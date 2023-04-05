#include<iostream>

using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int a[N], n, tmp[N];

ll merge_sort(int l, int r){
    if(l >= r)  return 0;
    int mid = l + r >> 1;
    ll ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) tmp[++k] = a[i++];
        else {
            ans += mid - i + 1;
            tmp[++k] = a[j++];
        }
    }
    while(i <= mid) tmp[++k] = a[i++];
    while(j <= r)   tmp[++k] = a[j++];
    
    for(int i = l, j = 1; i <= r;   ) a[i++] = tmp[j++];
    return ans;  
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    merge_sort(1, n);

    for (int i = 1; i <= n; i++) cout << a[i] << " ";

    return 0;
}