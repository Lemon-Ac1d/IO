#include<bits/stdc++.h>

using namespace std;

struct Node{
    int l,r;
}a[1010];

// bool cmp(Node x, Node y){
//     if(x.l < y.l)
//         return 1;
//     else if(x.l == y.l){
//         if(x.r <= y.r)
//             return 1;
//     }
//     return 0;
// }

int main(){
    ios::sync_with_stdio(false);
    int n;
    bool b[1010] = {0};
    cin >> n >> a[0].l >> a[0].r;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r;
    }

    long long last = a[0].l, max = 0,it = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1;j <=n; j++){
            if(b[j])continue;
            long long tmp = last / a[j].r;
            long long tmp_last = last *=a[j].l;
            if(tmp >= max){
                if(tmp_last < last)
                    max = tmp;
                    it = j;
            }else if(tmp == max){
                if(t)
            }
                
            last

        }
    }






    // sort(a+1,a+1+n,cmp);

    // for(int i=0;i<=n;i++)
    //     cout << a[i].l <<' '<<a[i].r << endl;

    // long long last = a[0].l,max = 0,tmp = 0;
    // for(int i = 1; i <= n; i++){
    //     for(int j = i;)
    //     tmp = last/a[i].r;
    //     //cout << tmp <<endl;
    //     if(max < tmp)max = tmp;
    //     last *=a[i].l;
    // }
    // cout << max;

    return 0;
}