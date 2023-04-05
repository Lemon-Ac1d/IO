#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int l[N], r[N], e[N], idx;
bool st[N];

int n, k, p, m, x;
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++;
}

void remove(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k];
    if(k == r[0])   r[0] = r[r[0]];
    if(k == l[1])   l[1] = l[l[1]];  
}
int main()
{
    cin >> n;
    r[0] = 1;
    l[1] = 0;
    idx = 2;
    insert(0, 1);st[2] = 1;
    for(int i = 2; i <= n; i++)
    {
        cin >> k >> p;
        if(p == 1)  insert(k + 1, i);
        else    insert(l[k + 1], i);
        st[i + 1] = 1;
    }

    cin >> m;
    while(m--)
    {
        cin >> x;
        if(st[x + 1])
            remove( x + 1);
             st[x + 1] = 0;
    }
    int i;
    for(i = r[0]; i != 1; i = r[i])
    {   
        cout << e[i] << " " ;
    }

    return 0;
}