#include<bits/stdc++.h>
 
using namespace std;
int t,n, o=0,j=0;

int main(){
    ios::sync_with_stdio(false);
 
    cin>>t;
    while(t--){
        cin>>n;
        
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x%2)o++;
            else j++;
        }
        cout << min(o,j) <<endl;
        o=j=0;
    }
    return 0;
}