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
    int n=5, W=11;
    vi val = {4,3,5,6,1}; 
    vi wt = {3,2,4,5,1};
    vi DP(W+1,0);
    rep(w,0,W+1){
        rep(i,0,n){
            if(w-wt[i]>=0)
                DP[w] = max(DP[w],val[i]+DP[w-wt[i]]);
        }
    }

    cout<<DP[W]<<endl;
    
    return 0;
}