#include<stdio.h>
int a[1010];
char s[1010];

int merge_sort(int l, int r){
    if(l >= r)  return 0;
    int mid = l + r >> 1;
    int res = merge_sort(l, mid) + merge_sort(mid+1, r);
    int i = l, j = mid + 1, k = 0;
    int tmp[1010];
    while (i <= mid && j <= r)
    {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else{
            res += mid - i + 1;
            // printf("%d %d\n", a[i], a[j]);
            tmp[k++] = a[j++];
        }
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r)   tmp[k++] = a[j++];
    
    for(int i = l, j = 0; j < k; ) a[i++] = tmp[j++];
    return res;
}


int main(){
    int n = 0;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)  scanf("%c", &s[i]);
    for(int i = 0; i < n; i++)  a[i] = s[i] - '0';

    // for (int i = 0; i < n; i++)
    //     printf("%d ", a[i]);
    // puts("");

    int m = merge_sort(0, n-1);

    // for (int i = 0; i < n; i++)
    //     printf("%d ", a[i]);
    // puts("");

    printf("%d", m);

    return 0;
}