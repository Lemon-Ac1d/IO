#include<iostream>

using namespace std;

const int N =  1e5 + 10;
int q[N];
int n;

void quick_sort(int q[],int l, int r)
{
    if(l >= r)   return;
    int mid = q[l + r >> 1]; 
    // 注意不是先找个mid位置，因为mid位置上的数字可能是被交换的
    // 所以需要用固定的存储这个数
    int i = l-1, j = r + 1;
    
    while(i < j)
    {
        do i++; while(q[i] < mid);
        do j--; while(q[j] > mid);
        if(i < j)   swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)  cin >> q[i];

    quick_sort(q,0,n-1);

    for (int i = 0; i < n; i++)
        cout << q[i] << ' ';

    return 0;
}