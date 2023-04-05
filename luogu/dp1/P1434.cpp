#include <iostream>
#include <vector>

using namespace std;

const int N = 210;

int r, c;
int a[N][N], dp[N][N];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        // if(xx > 0 && yy > 0 && xx <= r && yy <= c && a[x][y] > a[xx][yy]){
        //     dfs(xx, yy);
        //     dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
        // }

        if (xx < 1 || yy < 1 || xx > r || yy > c || a[x][y] <= a[xx][yy])
            continue;
        dfs(xx, yy);
        dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
    }
    return dp[x][y];
}

int main()
{
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans;
    return 0;
}