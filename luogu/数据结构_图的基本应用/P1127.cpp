#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

vector<int> a[1010];
int h[26];
string s[1010];
int n, ind[1010];
queue<int> q;
bool vis[1010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] ;
    }

    for(int i = 0; i < n; i++){
        char ed = s[i][s[i].size()];
        for(int j = 0; j < n; j++){
            if(ed == s[j][0]){
                a[i].push_back(j);
                ind[j] ++;
            }
        }
    }
    for(int i = 0 ; i < n; i++)
        if(!ind[i]) q.push(i);

    while(q.size()){
        int t = q.front();
        q.pop();
        vis[t] = true;

        for(int i = 0; i < a[t].size(); i++){
            
        }

    }

    return 0;
}