#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 3e5 + 10;
typedef pair<int, int> PII;
int n, x, c, l, r, m;

vector<int> alls;
vector<PII> query, add;
int a[N], s[N];

int find(int n){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= n)  r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l,r});
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);

        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}