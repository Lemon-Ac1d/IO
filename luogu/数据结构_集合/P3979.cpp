#include<iostream>
#include<map>
#include<vector>
#include<cstring>

using namespace std;
const int N = 1e6 + 10;
int cnt[N];
int main(){
    int n;
    map<string, vector<int>> m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int l;
        cin >> l;
        while(l--){
            string s;
            cin >> s;
            m[s].push_back(i);
        }
    }

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < m[s].size(); i++){
            if(!cnt[m[s][i]])
            {
                cout << m[s][i] << " ";
                cnt[m[s][i]] ++;
            }
        }
        puts("");
    }

    return 0;
}