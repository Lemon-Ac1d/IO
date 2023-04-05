#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N], n, k;

int qsort(int l, int r, int k){
    if(l >= r)  return a[l];
    int mid = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while(i < j){
        do i++; while(a[i] < mid);
        do j--; while(a[j] > mid);
        if(i < j)   swap(a[i], a[j]);
    }
    int s = j - l + 1;
    if(k > s)   return qsort(j + 1, r, k - s);
    else return qsort(l, j, k);
}


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cout << qsort(1, n, k);

    return 0;
}