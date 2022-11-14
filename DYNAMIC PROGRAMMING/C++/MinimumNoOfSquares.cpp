#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

const int N = 1e5+2, MOD = 1e7+9;

// MEMEOIZATION 
// int DP[N];
// int MinSquare(int n){
//     if(n==3 or n==2 or n==1 or n==0) return n;
//     if(DP[n]!=MOD) return DP[n];
//     for(int i=1;(i*i)<=n;i++){
//         DP[n] = min(DP[n],1+MinSquare(n-i*i));
//     }
//     return DP[n];
// }
// signed main(){
//     int n; cin>>n; 
//     rep(i,0,N)
//         DP[i] = MOD;
//     cout<<MinSquare(n)<<endl;
//     rep(i,0,n)
//         cout<<DP[i]<<" ";
//     return 0;
// }

// TABULATION 

signed main(){
    int n; cin>>n; 
    
    vi DP(n+1,MOD);

    DP[0] = 0; 
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3; 

    for(int i=1;i*i<=n;i++){
        for(int j=0;i*i+j<=n;j++){
            DP[i*i+j] = min(DP[i*i+j],1+DP[j]);
        }
    }

    for(auto it : DP)
        cout<<it<<" ";
    cout<<endl;

    cout<<DP[n]<<endl;

    return 0; 
}

