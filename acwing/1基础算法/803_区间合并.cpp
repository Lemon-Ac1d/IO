#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, l, r;
vector<PII> add, tmp;
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> l >> r;
        add.push_back({l, r});
    }
    sort(add.begin(), add.end());

    int e = -2e9;
    int st = e, ed = e;

    for (auto item : add){
        l = item.first, r = item.second;
        if(l > ed){
            if(ed != e)
                tmp.push_back({st, ed});
            st = l, ed = r;
        }
        else
            ed = max(ed, r);
    }
    if(st != e)
        tmp.push_back({st,ed});
    cout << tmp.size() << endl;

    return 0;
}