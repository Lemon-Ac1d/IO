#include<bits/stdc++.h>

using namespace std;
const int MAX = 5000 + 10;
struct Node{
    int height, power;
}apple[MAX];

bool cmp(Node a, Node b){
    if(a.power < b.power)   return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    int n, s, a, b, cont = 0, top;
    cin >> n >> s >> a >> b;

    for(int i = 0; i < n; i++){
        cin >> apple[i].height >> apple[i].power;
    }
    sort(apple, apple + n, cmp);
    top = a + b;

    for(int i = 0; i < n; i++){
        if(apple[i].height > top)   continue;
        s -= apple[i].power;
        if(s < 0)   break;
        cont++;
    }
    cout << cont;
    return 0;
}