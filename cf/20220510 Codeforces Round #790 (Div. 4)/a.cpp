#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	int i=t;
	string s;
	bool res[1003]={0};
	while(t--){
		cin>>s;
		if((s[0] + s[1] + s[2] ) ==s[3] + s[4] + s[5] )
			res[t]=1;
	}
	
	t=i;
	while(t--){
		if(res[t])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}