#include<bits/stdc++.h>
using namespace std;
#define int long long 
int power(int x, int y, int p){
    int ans = 1;
    x = x % p; 
    while(y>0){
        if(y&1)
            ans = (ans*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    }
    return ans;
}
int ModInverse(int a, int p){
    return power(a,p-2,p);
}
int Modfact(int n, int p){
    if(n>=p)
        return 0; 
    int ans = p-1; 
    for(int i=n+1;i<p;i++)
        ans = (ans * ModInverse(i,p))%p;
    return ans; 
}
signed main(){
    int t; cin>>t; 
    int n, p; 
    while(t--){
        cin>>n>>p; 
        cout<<Modfact(n,p)<<endl;
    }  
    return 0;
}