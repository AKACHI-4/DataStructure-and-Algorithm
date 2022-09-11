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
    int n;
    cin>>n;

    vi a(n);

    rep(i,0,n)
        cin>>a[i];

    int x; 
    cin>>x; 

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0; 

    for(int i=0;i<n;i++){
        cout<<x/a[i]<<endl;
        ans += x/a[i];
        cout<<ans<<endl;
        cout<<x/a[i] * a[i]<<endl;
        x -= x/a[i] * a[i];
        cout<<x<<endl;

        cout<<endl;
    }
    /* In C++, a/b = integer not float */
    cout<<ans; 
    return 0; 
}
