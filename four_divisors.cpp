#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
    int T;
    cin>>T;
    while(T--){
	int n,ans=0;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++){
		int tmp = sqrt(v[i]);
		if(tmp*tmp==v[i]) continue;
		else{
			int count=0,sum=0;
			for(int j=1;j<=sqrt(v[i]);j++){
				if(v[i]%j==0){
					count+=2;
					sum+=j;
					sum+=v[i]/j;
				}
			}
			if(count==4)  ans+=sum;
		}
	}
		cout<<ans<<endl;
    }
    return 0;
}