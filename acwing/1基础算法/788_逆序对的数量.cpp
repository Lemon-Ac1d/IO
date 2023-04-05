#include<iostream>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
int n, q[N], tmp[N];

ll merge_sort(int q[], int l, int r)
{
    if(l >= r)  return 0;
    int mid = l + r >> 1;
    ll res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    
    int i = l, j = mid + 1, k = 0;

    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])
            tmp[k++] = q[i++];
        else
        {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r)   tmp[k++] = q[j++];

    for(int i = l, j = 0; j <  k;)   q[i++] = tmp[j++];
    return res;
}

int main(){ 
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> q[i];

    cout << merge_sort(q, 0, n-1);

    return 0;
}