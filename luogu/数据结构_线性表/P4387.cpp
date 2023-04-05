#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], out[N], in[N];
int q, n;

int main()
{
    cin >> q;

    while(q--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)  cin >> in[i];
        for(int i = 0; i < n; i++)  cin >> out[i];
        int top = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            stk[++top] = in[i];
            while(out[cnt] == stk[top])
            {
                cnt++;
                top--;
                if(top == 0)break;
            }
        }
        if(top == 0)    cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}