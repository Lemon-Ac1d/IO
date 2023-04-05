    #include<bits/stdc++.h>

    using namespace std;
    const int MAX = 1000 + 10;
    struct Node{
        int t;
        int num;
    }a[MAX];

    bool cmp (Node a,Node b){
        return a.t < b.t;
    }

    int main(){
        //ios::sync_with_stdio(false);
        int n;
        cin >> n;
        for(int i = 0; i < n ; i++) 
        {
            cin >> a[i].t;
            a[i].num = i;
        }

        long long time = 0;
        sort(a,a+n,cmp);
        for (int i = 0; i < n; i++)
        {
            cout << a[i].num + 1 << " "; //先把简单的做了，输入由小到大的编号
            time += a[n-i-1].t * i;
        }

        cout << endl;
        // for(int i = n-1; i > 0; i--){
        //     time += a[n-i-1].t * i;
        // }
        // cout << time/n;
        // cout << time;

        double per = time * 1.0 / n;
        printf("%.2lf", per);

        return 0;
    }