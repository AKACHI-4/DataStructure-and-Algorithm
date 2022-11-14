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
    int pos; cin>>pos;

    int c2(0), c3(0), c5(0);
    vi DP(pos);
    DP[0] = 1;
    rep(i,1,pos+1){
        DP[i] = min({2*DP[c2],3*DP[c3],5*DP[c5]});
        if(2*DP[c2]==DP[i])
            c2++; 
        if(3*DP[c3]==DP[i])
            c3++; 
        if(5*DP[c5]==DP[i])
            c5++; 
        // two multiple can have same output that's why no else-if
    }
    cout<<DP[pos-1]<<endl;

    for(auto i : DP)
        cout<<i<<" ";
    cout<<endl;
    return 0;
} // 1 2 3 