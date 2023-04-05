#include<bits/stdc++.h>
#define W(a,b,c) (w[a][b][c]?w[a][b][c]:w[a][b][c]=f(a,b,c))
using namespace std;
long  w[25][25][25];
long f(long a, long b , long c ){
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a > 20 || b > 20 || c > 20) return W(20,20,20);
    if(a < b && b < c) return W(a,b,c-1)+W(a,b-1,c-1) - W(a,b-1,c);
    return W(a-1,b,c)+W(a-1,b-1,c)+W(a-1,b,c-1) - W(a-1,b-1,c-1);

}

int main(){
    ios::sync_with_stdio(false);
    long  a,b,c;
    while(1){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<f(a,b,c)<<endl;
    }

    return 0;
}