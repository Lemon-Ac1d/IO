#include<iostream>
#include<map>
using namespace std;
map<int, int> m;
int main(){
    int n, tmp;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        m[tmp] = i;
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(m.count(x))  cout << m[x] << endl;
        else cout << 0 << endl;

    }

    return 0;
}