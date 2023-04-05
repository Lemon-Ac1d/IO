#include<iostream>

using namespace std;

int n;
int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        int t = max((n-i), i - 1);
        cout << 2 * t << endl;
    }

    return 0;
}