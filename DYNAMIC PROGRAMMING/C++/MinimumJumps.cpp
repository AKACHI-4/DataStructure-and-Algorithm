#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int INF = 1e3+2;

signed main(){
    int n; cin>>n; 

    vi arr(n); 
    for(auto &i : arr)
        cin>>i; 

    vi jumps(n,INF);

    if(!arr[0]){
        cout<<INF<<endl;
        return 0; 
    }

    jumps[0] = 0; 

    rep(i,1,n){
        rep(j,0,i){
            if(i <= j+arr[j]){
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }

    for(auto i : jumps)
        cout<<i<<" ";
    cout<<endl;

    cout<<jumps[n-1]<<endl;

    return 0;
}