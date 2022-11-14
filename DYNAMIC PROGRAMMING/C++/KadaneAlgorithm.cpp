#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main(){
    int n; cin>>n; 
    vi a(n);
    for(auto &i : a)
        cin>>i;

    int curr = 0, maxTillnow = 0; 

    rep(i,0,n){
        if(curr<0) curr=0;
        curr += a[i];
        maxTillnow = max(maxTillnow,curr);
    }
    cout<<maxTillnow<<endl;
    return 0;
}