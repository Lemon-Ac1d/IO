#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int main(){
    ios::sync_with_stdio(false);
    int n, tmp,sum;
    cin >> n;
    priority_queue<int, vector<int>, greater <int>> q;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        q.push(tmp);
    }
    while(q.size() >= 2){
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        sum += (a+b);
        q.push((a+b));
    }
    cout << sum;
    return 0;
}