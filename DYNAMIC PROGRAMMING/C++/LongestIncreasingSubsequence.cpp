#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+6, MOD = 1e7+2;

// int DP[N];

// int Lis(vi &a, int n){
    
//     cout<<n<<endl;

//     if(DP[n]!=-1)
//         return DP[n];

//     DP[n] = 1; // Single element is also in Lis

//     rep(i,0,n)
//     {
//         if(a[n]>a[i] )
//             DP[n] = max(DP[n],1+Lis(a,i));
//     }

//     cout<<"DP[n]: "<<DP[n]<<endl;

//     return DP[n];
// }
// signed main(){

//     rep(i,0,N)
//         DP[i] = -1;
    
//     int n; 
//     cin>>n;

//     vi a(n);

//     rep(i,0,n)
//         cin>>a[i];

//     cout<<Lis(a,n-1)<<endl;

//     return 0;
// }


signed main(){
    int n; 
    cin>>n; 

    vi a(n);

    rep(i,0,n)
        cin>>a[i];

    vi DP(n,1);
    // single element is also part of Lis
    
    int ans = 0; 
    rep(i,1,n){
        rep(j,0,i){
            if(a[i]>a[j])
                DP[i] = max(DP[i],1+DP[j]);
        }
        ans = max(ans,DP[i]);
    }
    cout<<DP[n-1]<<endl;
    cout<<ans<<endl;

    
    return 0; 
}