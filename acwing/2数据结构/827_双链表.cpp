#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int e[N], l[N], r[N], idx = 0;
int m, k, x;
string op;

void insert(int k, int x){
    e[idx] = x;
    r[idx] = r[k];  l[r[k]] = idx;
    r[k] = idx; l[idx] = k;
    idx++;
}

void remove(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}


int main(){
    cin >> m;
    r[0] = 1, l[1] = 0;
    idx = 2;

    while(m--){
        cin >> op >> k;
        if(op == "L"){
            insert(0, k);
        }
        else if(op == "R"){
            insert(l[1], k);
        }
        else if(op == "D"){
            remove(k+1);
        }
        else if(op == "IL"){
            cin >> x;
            insert(l[k+1], x);
        }
        else{
            cin >> x;
            insert(k+1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}