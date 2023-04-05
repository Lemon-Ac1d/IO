#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int p[N], cnt[N];
int n, a, b, m;
string op;

int find(int x)
{
    if(p[x] != x)   p[x] = find(p[x]);
    return p[x];
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        cnt[i] = 1;
    }


    while(m--)
    {
        cin >> op;
        if(op == "C")
        {
            cin >> a >> b;
            b = find(b);
            a = find(a);
            if(a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if(op == "Q1")
        {
            cin >> a >> b;
            if(find(b) == find(a))  puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }

    }

    return 0;
}