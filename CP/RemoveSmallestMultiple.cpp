#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

void removeSmallest(){ 
    int n; cin>>n; 
    string bin; 
    cin>>bin; 
    int ans = 0; 
    rep(i,1,n+1){
        int cur = 1; 
        while(cur*i<=n){
            if(bin[cur*i-1]=='1') break; 
            if(bin[cur*i-1]=='0') ans += i; 
            // now marking visited
            bin[cur*i-1] = '2'; 
            cur++; 
        }
    }

    cout<<ans<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    int t; 
    cin>>t; 
    while(t--){
        removeSmallest(); 
    }
    return 0; 
}