#include<iostream>

using namespace std;
typedef long long ll;
const int M = 1e5 + 10, MOD = 1e9 + 7;

int n, ma, mb;
long long ans[M], res, d[M];
int A[M], B[M];
long long la, lb;
int main(){
	cin >> n >> ma;
	for(int i = ma; i ; i--)	cin >> A[i];
	cin >> mb;
	for(int i = mb; i ; i--)	cin >> B[i];
	ma = max(ma, mb);
	for(int i = 1; i <= ma; i++){
		ans[i] = max(A[i], B[i]) + 1;

	}
	for(int i = 1; i <= ma; i++){
		ans[i] = ans[i] > 2 ? ans[i] : 2;		
	}
	
	d[1] = 1;
	for(int i = 2; i <= ma; i++){
		d[i] = (d[i-1] * ans[i-1]) % MOD;
	}

	for(int i = ma; i ; i--) la += A[i] * d[i], la %= MOD;
	for(int i = mb; i ; i--) lb += B[i] * d[i], lb %= MOD;
	
	cout << (la - lb + MOD) % MOD;
	return 0;
}