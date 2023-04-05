#include<iostream>
#include<vector>

using namespace std;
const int N = 1010;
int n, m;
int s[N][N], h[N];


int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> s[i][0];
        for(int j = 1; j < n; j++){
            cin >> s[i][j];
        }
        h[i] = 1;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j < n; j++){
            
        }
    }

    return 0;
}