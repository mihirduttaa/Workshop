#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)

{

    if (a == 1)

        return b;

    return gbd(b % a, a);

}

int main() {
    // your code goes here
    int T;
    cin>>T;
    while(T--){
	int n;
	cin>>n;
	vector<long long> v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	long long ans = v[0];
	for(int i=1;i<n;i++)
	    ans = gcd(ans,v[i]);
	if(ans==1) cout<<1<<endl;
	else cout<<0<<endl;
    }
}