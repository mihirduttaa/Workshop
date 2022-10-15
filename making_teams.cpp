#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maxo(ll a,ll b){
    return (a>b) ? a : b;
}

int main(){
    vector<vector<ll>> pasc(61,vector<ll>(61));
    pasc[0][0]=1;
    for(int i=1;i<=60;i++){
        for(int j=0;j<=i;j++){
            if(j==0 or j==i) pasc[i][j] =1;
            else pasc[i][j] = pasc[i-1][j-1] + pasc[i-1][j];
        }
    }
    int T;
    cin>>T;
    while(T--){
        int n,m,x;
        cin>>n>>m>>x;
        ll ans =0;
        ans += pasc[n+m][x];
        if(x<=m) ans-= pasc[m][x];
        if((x-1)<=m) ans-=pasc[m][x-1]*n;
        if((x-2)<=m) ans-=pasc[m][x-2]*pasc[n][2];
        if((x-3)<=m) ans-= pasc[m][x-3] * pasc[n][3];
        if(x<=n) ans-= pasc[n][x];
        cout<<ans<<endl;
    }
    return 0;
}