#include<iostream>

using namespace std;
const int N = 2e5 + 10;
int t, n, a[N], sum;

bool check(int gcd)
{
    
    long long t = 0, sp = 0;
    for(int i = 1; i <= n; i++)
    {
        t += a[i];
        if (t && t % gcd == 0)
        {
            sp ++;
            t = 0;
        }
    }
    if(sp > 1 && !t)   return true;
    else return false;
}

int main(){
    cin >> t;

    while(t--)
    {
        cin >> n;
        sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int ed = sum / n;
        for (int i = sum / 2; i >= 1; i--)
        {
            if(check(i))
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}