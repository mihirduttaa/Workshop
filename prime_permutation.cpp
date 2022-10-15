#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define modo 1000000007
using namespace std;
ll maxo(ll a,ll b){
    return (a>b) ? a : b;
}
int ceil(float num) {
    int inum = (int)num;
    if (num == (float)inum) {
        return inum;
    }
    return inum + 1;
}
unsigned ll fac(unsigned ll n)
{
    if (n == 0)
        return 1;
    return (n * fac(n - 1))%modo;
}
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
    for(int i=2;i<=lim;i++){
        primes[i] = primes[i]+primes[i-1];
    }
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<((fac(primes[n])%modo) * (fac(n-primes[n])%modo))%modo<<endl;
    }
    return 0;
}