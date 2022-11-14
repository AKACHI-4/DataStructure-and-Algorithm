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

    vi DP(n+1,0);
    DP[0] = 1;
    // as we considered empty set so assuming that if 0 friend so we can pair them as single
    DP[1] = 1;
    
    // why add because we want total no. of ways

    rep(i,2,n+1)
        DP[i] = DP[i-1] + (i-1)*DP[i-2];
    cout<<DP[n]<<endl;

    return 0;
}