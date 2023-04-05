#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;

int n, x;
char op[2];


void insert(int u)
{
    int k = ((u % N) + N) % N;
    e[idx] = u;
    ne[idx] = h[k];
    h[k] = idx++;
}


bool search(int u)
{
    int k = ((u%N) + N) % N;
    for(int i = h[k]; i!= -1; i = ne[i])
        if(e[i] == u)   return true;

    return false;
}



int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    while(n--)
    {
        cin >> op;
        if(*op == 'I')
        {
            cin >> x;
            insert(x);
        }
        else if(*op == 'Q')
        {
            cin >> x;
            if(search(x))   puts("Yes");
            else puts("No");
        }
    }

    return 0;
}