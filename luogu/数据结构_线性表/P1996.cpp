#include<iostream>

using namespace std;

int n, m, s = 0;
bool vis[110];
int main()
{
    cin >> n >> m;    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(++s > n) s = 1;
            if(vis[s]) j--;
        }
        cout << s <<' ';
        vis[s] = 1;
    }


    return 0;
}