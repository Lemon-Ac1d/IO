#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], ph[N], hp[N], cnt;
int k, x, n, m;
char op[5];

void head_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}


void down(int u)
{
    int t = u;
    if(u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(u != t)
    {
        head_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u / 2 && h[u] < h[u/2])
    {
        head_swap(u, u / 2);
        u >>= 1;
    }
}

int main(){
    cin >> n;

    while(n--)
    {
        cin >> op;

        if(!strcmp(op, "I"))
        {
            cin >> x;
            cnt ++;
            m++;
            ph[m] = cnt;
            hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if(!strcmp(op, "PM"))  cout << h[1] << endl;
        else if(!strcmp(op, "DM"))
        {
            head_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if(!strcmp(op, "D"))
        {
            cin >> k;
            k = ph[k];
            head_swap(k,cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}