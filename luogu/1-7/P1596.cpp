#include<iostream>

using namespace std;
const int N = 110;
bool g[N][N], st[N][N];
int n, m, res = 0;
string s;
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1}, dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

bool f(int x, int y)
{
    if(!g[x][y])    return 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            int xx = x + dx[i], yy = y + dy[j];
            if(xx < 0 || xx > n || yy < 0 || yy > m)    continue;
            if(!st[xx][yy] && g[xx][yy])
            {
                st[xx][yy] = true;
                f(xx,yy);
            }
        }
    return 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == 'W') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!st[i][j])
            {
                res += f(i, j);
                // cout << i << "  " <<  j << "  " <<res << endl;
            }
        }
    }
    cout << res;
    return 0;
}