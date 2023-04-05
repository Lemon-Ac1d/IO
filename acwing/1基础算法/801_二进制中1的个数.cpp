#include<iostream>

using namespace std;

int n, tmp;

int lowbit(int x)
{
    return x & -x;
}

int main(){
    cin >> n;

    while(n--)
    {
        int res = 0;
        cin >> tmp;
        while(tmp)
        {
            tmp -= lowbit(tmp);
            res++;
        }
        cout << res << ' ';
    }

    return 0;
}