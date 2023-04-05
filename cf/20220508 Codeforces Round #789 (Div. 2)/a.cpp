#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,a[102],as[103]={0},res[1003];
	cin>>t;
	bool flag=0;
	for(int i=0;i<t;i++){
		memset(as,0,sizeof(as));
		flag=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
			as[a[j]]++;
			if(as[a[j]]>1)flag=1;
		}
		if(as[0])res[i]=n-as[0];
		else if(flag)	res[i]=n;
		else	res[i]=n+1;
	}
	
	for(int i=0;i<t;i++){
		cout<< res[i]<<endl;
	}
	return 0;
}