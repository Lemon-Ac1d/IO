#include<iostream>

using namespace std;

char s[110][110];
char t[] = "yizhong";
bool b[110][110];
int n;
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1}, dy[] = {-1, -1,-1, 0, 1, 1, 1, 0};
void search(int x, int y)
{

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            int st = 1; // 匹配到的位置
            int xx = x + dx[i], yy = y + dy[j];
            if(xx < 0 || xx > n || yy < 0 || yy > n)    continue;
            while(s[xx][yy] == t[st])
            {
                if (st == 6)
                    break;
                xx += dx[i], yy += dy[j];
                st ++;
            }
            if(s[xx][yy] == t[st] && st == 6)
            {
                for(int k = 0; k <= 6; k++)
                {
                    b[x + k * dx[i]][y + k * dy[j]] = true;
                }
            }
        }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> s[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
    {
        if(s[i][j] == 'y')
        {
            search(i,j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(b[i][j]) cout << s[i][j];
            else cout << '*';
        }
        puts("");
    }
    return 0;
}