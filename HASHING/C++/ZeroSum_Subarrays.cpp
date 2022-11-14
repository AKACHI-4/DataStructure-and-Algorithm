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
    rep(i,0,n)
        cin>>a[i];

    map<int, int> cnt; 

    int prefsum = 0; 

    rep(i,0,n)
    {
        prefsum += a[i];
        cnt[prefsum]++;
    }

    int ans = 0; 

    map<int, int> :: iterator it; 

    for(it = cnt.begin(); it != cnt.end(); it++){
        
        int c = it->ss;
        /* bcoz frequency stored in 2nd of the map */
        ans += (c*(c-1))/2;

        if(it->ff == 0)
            ans += it->ss; 
    
    }

    cout<<"No. of subarrays having sum 0 : "<<ans<<endl; 

    return 0; 
}