#include<bits/stdc++.h>

using namespace std;

const int MAX = 10e6 + 10;

struct Node{
    int start, end;
}a[MAX];

bool cmp(Node a, Node b){
    return a.end < b.end;
}



int main(){
    ios::sync_with_stdio(false);

    int n, cont = 0, res = 1;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].start >> a[i].end;
    }
    sort(a,a+n,cmp);
    // for(int i = 0; i < n; i++ )cout << a[i].start << " " << a[i].end << endl;
    int loc = 0;
    for(int i = 0; i < n; i++){
        if(a[loc].end <= a[i].start){
            // cout << a[loc].end << endl << a[i].end<< endl;
            loc = i;
            res++;
        }
    }

    cout << res;
    return 0;
}