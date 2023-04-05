#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[20];
int n, k, res = 0;
vector<int> p;

bool judge(int n){
    int i = 2;
    while(n%i) i++;
    if(i == n)  return 1;
    return 0;
}

void dfs(int x, int sum, int pos)
{
    if(x == k)
    {
        if(judge(sum))
        {
            res++;
            // cout << sum << endl;
        }
        return;
    }

    for(int i = pos; i < n; i++){
        dfs(x+1, sum + a[i], i + 1);
    }
}

int main(){

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    dfs(0,0,0);
    cout << res;
    return 0;
}