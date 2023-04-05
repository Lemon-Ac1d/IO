#include<iostream>
#include<cstring>

using namespace std;

string str[20];
int st[20];
int length = 0, n;
int canlink(string str1, string str2)
{
    for(int i = 1; i < min(str1.length(), str2.length()); i++)
    {
        int flag = 1;
        for(int j = 0; j < i; j++)
        {
            if(str1[str1.length() - i + j] != str2[j]) flag = false;
        }
        if(flag) return i;
    }
    return 0;
}

void solve(string now, int lencnow)
{
    length = max(lencnow, length);
    for(int i = 0; i < n; i++)
    {
        if(st[i] >= 2)continue;
        int c = canlink(now, str[i]);
        if(c > 0)
        {
            st[i] ++;
            solve(str[i], lencnow + str[i].length() - c);
            st[i] --;
        }
    }
}


int main(){
    cin >> n;
    for(int i = 0; i <= n; i++)  st[i] = false, cin >> str[i];

    solve(' ' + str[n], 1);

    cout << length;
    return 0;
}