#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int stk[N], hh = 0;
int m, x;
string op;

int main(){
    cin >> m;
    
    while(m--){
        cin >> op;
        if(op == "push"){
            cin >> x;
            stk[hh++] = x;
        }
        else if(op == "pop"){
            stk[--hh];
        }
        else if(op == "empty"){
            if(hh == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(op == "query")
            cout << stk[hh-1] << endl;
    }


    return 0;
}