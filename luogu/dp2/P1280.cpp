#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e4 + 10;
int n, k, p, t;
vector<PII> alls;
int f[N], sum[N];
bool cmp(PII a, PII b){
    return a.first > b.first;
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> p >> t;
        alls.push_back({p, t});
        sum[p]++;
    }
    sort(alls.begin(), alls.end(), cmp);

    // int i = 1;
    // for(auto item : alls){
    //     cout << item.first << " " << item.second << " " << sum[item.first] << endl;
    // }


    int num = 0;
    for(int i = n; i >= 1; i--){
        if(sum[i] == 0) f[i] = f[i + 1] + 1;
        else for(int j = 1; j <= sum[i]; j++){
            if(f[i+alls[num].second] > f[i])
                f[i] = f[i + alls[num].second];
            num++;
        }
    }

    cout  << f[1] << endl;

    return 0;
}