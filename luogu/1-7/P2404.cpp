#include<iostream>

using namespace std;

int n;
int path[10];
bool st[10];
void dfs(int begin, int u, int pos)
{
    if(begin == n)  return;
    if(u == n)
    {
        for(int i = 0; i < pos - 1 ; i++)
            cout << path[i] << '+';
        cout << path[pos-1] << endl;
        return;
    }

    for(int i = begin; i <= n - u; i++)
    {
        path[pos] = i;
        dfs(i, u+i, pos+1);
    }

}

int main()
{
    cin >> n;

    dfs(1, 0, 0);

    return 0;
}