#include<bits/stdc++.h>
using namespace std;

int proc(int num,bool n[]){
	
}
int main(){

	int t,num,res[1003]={0};
	bool n[200005];
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>num;
		for(int i=0;i<num/2;i++){
			cin>>n[2*i]>>n[2*i+1];
			if(n[2*i]!=n[2*i+1]){
				res[j]++;
				cout<<n[2*i]<<"  "<<n[2*i+1]<<"  "<<res[j]<<endl;
			}
				
		}
		for(int i=0;i<num;i++){
		cout<<n[j]<<endl;
	}
	}
	for(int i=0;i<t;i++){
		cout<<res[i]<<endl;
	}
	return 0;
}