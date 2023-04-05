#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
    ios::sync_with_stdio(false);
    
    bool b[260]={0};
    int k;
    cin >> s >> k;
    int lenc = s.length();
    while(k--){
        for(int i = 0; i < lenc - 1; i++){
            if(s[i] > s[i+1]){
                // cout << s[i] <<" " << s[i+1] <<endl;
                for(int j = i; j < lenc - 1; j++){
                    s[j] = s[j+1];
                }
                // cout <<s <<endl;
                break;
            }
        }
        lenc--;
    }
    int i = 0;
    while(i < lenc && s[i] == '0')i++;
    if(i == lenc) putchar('0');
    else
        for(int j = i; j < lenc; j++){
            putchar(s[j]);
        }
}