#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 102, MOD = 1e9+7; 

// int arr[N]; 
// int DP[N][N];

// int MCM(int i, int j){
//     // no matrix is there 
//     if(i==j)
//         return 0;
    
//     if(DP[i][j]!=-1)
//         return DP[i][j];
    
//     DP[i][j] = MOD; // intially having a big value
//     rep(k,i,j)
//         DP[i][j] = min(DP[i][j], MCM(i,k) + MCM(k+1,j) + arr[i-1]*arr[k]*arr[j]);
    
//     return DP[i][j];
// }

// signed main(){

//     memset(DP, -1, sizeof DP);

//     int n; cin>>n;

//     rep(i,0,n)
//         cin>>arr[i];
    
//     cout<<MCM(1,n-1)<<endl;

//     return 0;
// }


signed main(){
    int n; 
    cin>>n; 

    int a[n];
    rep(i,0,n)
        cin>>a[i];
    
    vvi DP(n+1,vi(n+1,-1));

    // base condition
    rep(i,0,n)
        DP[i][i] = 0; 

    // DOUBTED !!
    rep(l,2,n){
        rep(i,1,n-l+1){
            int j=i+l-1;
            DP[i][j] = MOD;
            rep(k,i,j){
                DP[i][j] = min(DP[i][j], DP[i][k]+ DP[k+1][j]+ a[i-1]*a[k]*a[j]);
            }
        }
    }

    cout<<DP[1][n-1]<<endl; +

    return 0;
}