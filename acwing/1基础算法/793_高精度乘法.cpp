#include<iostream>
#include<vector>

using namespace std;
typedef vector<int> vint;
vint A;
string a;
int b;

vint multi(vint A, int b)
{
    vint C;
    int  t = 0;
    for(int i = 0; i < A.size(); i++)
    {   
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    if(t)   C.push_back(t);
    while(C.size() > 1 && C.back() == 0)    C.pop_back();
    return C;
}


int main(){
    cin >> a >> b;

    for(int i = a.size() - 1; i >= 0; i--)  A.push_back(a[i] - '0');

    auto C = multi(A, b);

    for(int i = C.size() - 1; i >= 0; i--)  cout << C[i];

    return 0;
}