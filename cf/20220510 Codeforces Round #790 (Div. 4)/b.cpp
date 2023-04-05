#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,n,min;
	long res[55]={0};
	cin>>t;
	int a=t;
	while(t--){
		cin>>n;
		cin>>min;
		for(int i=1;i<n;i++){
			int tmp;
			cin>>tmp;
			if(min>tmp){
				res[t]+=(min-tmp)*i;
				min=tmp;
				//cout<<">"<< "   "<<res[t]<<endl;
			}
			else if(tmp==min);
			
			else{
				res[t]+=tmp-min;
				//cout<<"<"<< "   "<<res[t]<<endl;
			}
		}	
	}
	while(a--)
		cout << res[a] <<endl;	
	return 0;
}