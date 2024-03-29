#include<iostream>

using namespace std;

const int N = 1e5;

int son[N][26], cnt[N], idx;
int n;
string s, op;

void insert(string s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if(!son[p][u])  son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(string s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if(!son[p][u])  return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    cin >> n;
    while(n--)
    {
        cin >> op >> s;
        if(op == "I") insert(s);
        else   cout << query(s) << endl;
    }

    return 0;
}