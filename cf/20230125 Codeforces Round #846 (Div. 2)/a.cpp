#include<iostream>

using namespace std;
const int N = 310;
int t, n;
int odds[N],evens[N], odd, tmp, even;

int main(){
    cin >> t;

    while(t--)
    {
        cin >> n;
        odd = even = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            if(tmp % 2 == 1)   odds[odd++] = i;
            else evens[even++] = i;
            // cout << odd << even << endl;
        }
        // cout << odd << "  " << even << endl;
        if(odd >= 3)
        {
            puts("YES");
            cout << odds[0] << " " << odds[1] << " " << odds[2] << endl;
        }
        else if (odd > 0 && even >= 2)
        {
            puts("YES");
            cout << evens[0] << " " << evens[1] << " " << odds[0] << endl;
        }
        else    puts("NO");

    }

    return 0;
}