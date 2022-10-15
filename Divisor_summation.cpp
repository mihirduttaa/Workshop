#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int lim=1000000;
    vector<int> primes(lim+1,1); 
    vector<int> spf(lim+1,-1);
    primes[1] = 0;
    for(int i=2;i<=sqrt(lim);i++){
        if(primes[i]==1){
            for(int j=i;j*i<=lim;j++){
                if(primes[i*j]==1){
                    spf[i*j] = i;
                    primes[i*j]=0;
                }
            }
        }
    }

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++){
            int tmp = v[i];
            map<int,int> fac; 
            while(spf[tmp]!=-1){
                fac[spf[tmp]]++;
                tmp /= spf[tmp];
            }
            if(tmp!=1) fac[tmp]++;
        }
        
        for(auto it:fac){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}