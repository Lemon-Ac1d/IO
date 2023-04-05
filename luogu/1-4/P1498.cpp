#include<bits/stdc++.h>

using namespace std;

char a[3000][3000];
int h=2,w=4;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    memset(a,' ',sizeof(a));
    a[1][2] = a[2][1] = '/';
    a[1][3] = a[2][4] = '\\';
    a[2][2] = a[2][3] = '_';
    int h=2,w=4;
    

    for(int i = 1;i<n;i++){
        for(int j = 1;j<=h;j++){
            for(int k = 1;k<=w;k++){
                a[j+h][k] = a[j+h][k+w] = a[j][k];
                a[j][k] = ' ';
            }//向下想右复制
        }
        for(int j = 1;j<=h;j++){
            for(int k = 1; k<=w; k++){
                a[j][k+w/2] = a[j+h][k];
            }
        }
        w=w<<1;
        h=h<<1;
    }

    for(int i=1;i<=h;i++){
        for(int j = 1; j<=w ;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}