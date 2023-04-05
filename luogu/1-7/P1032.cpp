#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
struct{
    int pos = 1, x1, y1, x2, y2;
}h[30];
const int N =  310;
int n, m;
char ch;
int g[N][N], d[N][N];
bool st[N][N];
int sx, sy, ex, ey;
int dx[] = { -1, 1, 0, 0}, dy[] = { 0, 0, -1, 1};
void bfs()
{
    queue<PII> q;
    q.push({sx, sy});
    memset(d, -1, sizeof d);
    d[sx][sy] = 0;
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            // cout << x << " " << y << endl;
            if(x < 1 || x > n + 1 || y < 1 || y > m + 1)    continue;

            if(!st[x][y] && g[x][y] == 1)
            {
                st[x][y] = true;
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
            else if(!st[x][y] && g[x][y] > 1)
            {
                // cout << x << "  "<< y << endl;

                auto tmp = h[g[x][y] - 2];
                st[x][y] = true;
                int x1 = tmp.x1, x2 = tmp.x2, y1 = tmp.y1, y2 = tmp.y2;

                //  cout << x1 << y1 << x2 << y2 << endl;

                if(x == x1 && y == y1) x = x2, y = y2;
                else x = x1, y =y1;
                d[x][y] = d[t.first][t.second] + 1;
                
                // cout << x << "  " << y << endl;
                
                q.push({x,y});
            }
        }
    }
}



int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> ch;
            if(ch == '#')   g[i][j] = 0;
            else 
            {
                g[i][j] = 1;
                if(ch == '@')   sx = i, sy = j, st[i][j] = 1;
                else if(ch == '=')  ex = i, ey = j;
                else if (ch <= 'Z' && ch >= 'A')  
                {
                    int t = ch - 'A';
                    g[i][j] = t + 2;
                    if(h[t].pos == 1) h[t].x1 = i, h[t].y1 = j, h[t].pos ++;
                    else h[t].x2 = i, h[t].y2 = j;
                }
            }
        }
        getchar();
    }
    bfs();
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //         cout << g[i][j] << ' ';
    //     cout << endl;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << d[i][j] << ' ';
    //     cout << endl;
    // }

    cout << d[ex][ey];
    return 0;
}