#include<iostream>

using namespace std;
int num[50], hh;
char s[50], op[50];

int main()
{
    cin >> s + 1;

    for(int i = 1; s[i] != '@'; i++)
    {
        int tmp = 0;
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                tmp = s[i] - '0' + tmp * 10;
                i++;
            }
            i--;
            num[hh++] = tmp;
        }
        else if(s[i] == '.')    continue;
        else
        {
            int b = num[--hh], a = num[--hh], res;
            if(s[i] == '-') res = a - b;
            else if(s[i] == '+')    res = a + b;
            else if(s[i] == '*')    res = a * b;
            else    res = a / b;
            num[hh++] = res;
            // cout << a << "  " << b << " " << res << " " << s[i] << endl;
        }
    }
    cout << num[0] << endl;
    return 0;
}