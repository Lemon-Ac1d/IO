#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], head = -1,  idx = 0;
int m, k, x;
char op[5];
void insert_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++; 
}

void insert(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void del(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    cin >> m;
    memset(e, -1, sizeof(e));
    while(m--){
        cin >> op[1] >> k;

        if(op[1] == 'H'){
            insert_to_head(k);
        }
        else if(op[1] == 'D'){
            if(!k)  head = ne[head];
            else del(k - 1);
        }
        else{
            cin >> x;
            insert(k-1, x);
        }
    }
    int i = head;

    while (i != -1)
    {
        cout << e[i] << ' ';
        i = ne[i];
    }

    return 0;
}