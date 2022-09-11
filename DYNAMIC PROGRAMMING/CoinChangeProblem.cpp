#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

// MEMOIZATION

// const int N = 1e3+2; 
// int DP[N][N];
// int CoinChange(vi &a, int n, int v){
//     if(v==0)
//         return 1;
//     if(v<0)
//         return 0; 
//     if(n<=0)
//         return 0; 
//     if(DP[n][v] != -1)
//         return DP[n][v];
//     /*
//         There are two option for every coin :-
//         1. Take that coin -> (a,n,v-a[n-1])
//         2. Do not take that coin -> (a,n-1,v)
//     */
//     return DP[n][v] = CoinChange(a,n,v-a[n-1]) + CoinChange(a,n-1,v);
//     // return CoinChange(a,n,v-a[n-1]) + CoinChange(a,n-1,v);
// }
// signed main(){
//     rep(i,0,N){
//         rep(j,0,N)
//             DP[i][j] = -1;
//     }
//     int n; cin>>n; 
//     // n -> no. of coins
//     vi a(n); // coins list
//     rep(i,0,n)
//         cin>>a[i]; 
//     int x; cin>>x; // value
//     cout<<CoinChange(a,n,x)<<endl;
//     return 0;
// }


// TABULATION

// signed main(){ 
//     int n; cin>>n; 
//     // no. of coins
//     vi a(n); // coins list
//     rep(i,0,n)
//         cin>>a[i];
//     int x; cin>>x; // value
//     // 2D-DP Table
//     // vvi DP(n+1,vi(x+1,0));
//     // DP[0][0] = 1;
//     // rep(i,1,n+1){
//     //     rep(j,0,x+1){
//     //         if(j-a[i-1] >= 0)
//     //             DP[i][j] += DP[i][j-a[i-1]];
//     //         DP[i][j] += DP[i-1][j];
//     //     }
//     // }
//     // Space Complexity : O(n*x)
//     // Time Complexity : O(n*x)
//     // cout<<DP[n][x]<<endl;
//     // 1D-DP Table
//     vi DP(x+1,0);
//     DP[0] = 1;
//     rep(i,0,n){
//         rep(j,0,x+1){
//             if(j>=a[i] and j-a[i]>=0)
//                 DP[j] += DP[j-a[i]];
//         }
//     }
//     // Space Complexity : O(n)
//     // Time Complexity : O(n*x)
//     cout<<DP[x]<<endl;
//     return 0; 
// }