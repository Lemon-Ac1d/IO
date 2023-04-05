#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, cnt= 1;
char l, r;
vector<int> g[27];
int ind[27];
bool vis[27];
string s;
int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        scanf("%c<%c", &l, &r);
        g[l - 'A'].push_back(r - 'A');
        ind[r - 'A'] ++;
    }
    
    queue<int> q;

    for(int i = 0; i < 26; i++){
        if(!ind[i]) q.push(i);
    }

    if(q.empty())
        puts("Sorted sequence cannot be determined.");
    if(q.size() != 1){
        puts("Inconsistency found after x relations.");
        return 0;
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        s += (t+'A');
        for(int i = 0; i < g[t].size(); i++){
            if(--ind[i] == 0){
                q.push(i);
                cnt++;
            }
        }
    }
    if(cnt == n)
        printf("Sorted sequence determined after %d relations: %s.",n, s);

    return 0;
}