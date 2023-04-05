#include<iostream>

using namespace std;
const int N = 110;
string s;
char a[N], b[N];
int top, w[N];
int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[')
        {
            a[++top] = s[i];
            w[top] = i;
            if (s[i] == '(')    b[i] = ')';
            else b[i] = ']';
        }
        if(s[i] == ')')
        {
            if(top && a[top] == '(')
            {
                b[w[top]] = ' ';
                top--;
            }
            else b[i] = '(';

        }
        if(s[i] == ']')
        {
            if(top && a[top] == '[')
            {
                b[w[top]] = ' ';
                top--;
            }
            else b[i] = '[';
        }
 
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(b[i] == '(' || b[i] == '[')  cout << b[i] << s[i];
        else if(b[i] == ')' || b[i] == ']') cout << s[i] << b[i];
        else cout << s[i];    
    }
    
    return 0;
}