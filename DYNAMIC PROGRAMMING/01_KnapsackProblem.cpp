#include "bits/stdc++.h"
using namespace std; 

#define vi vector<int> 
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a;i<b;i++)

// const int N = 1e3+2, MOD = 1e9+7;
// Lookup table
// int DP[N][N];
// int val[N], Wt[N];

// int Knapsack(int n, int w){

//     if(w<=0 or n<=0)
//         return 0; 

//     if(DP[n][w]!=-1)
//         return DP[n][w];

//     if(w<Wt[n-1])
//         return DP[n][w] = Knapsack(n-1,w);
//     return DP[n][w] = max(Knapsack(n-1,w), Knapsack(n-1,w-Wt[n-1]) + val[n-1]);
     
// }
// signed main(){

//     rep(i,0,N){
//         rep(j,0,N)
//             DP[i][j] = -1;
//     }

//     int n; cin>>n; 

//     rep(i,0,n)
//         cin>>val[i];

//     rep(i,0,n)
//         cin>>Wt[i]; 

//     int w; cin>>w; 
    

//     cout<<Knapsack(n,w)<<endl;

//     return 0;
// }


signed main(){

    int n; cin>>n; 
    
    int val[n], Wt[n];

    rep(i,0,n)
        cin>>val[i];
    rep(i,0,n)
        cin>>Wt[i]; 

    int w; cin>>w; 

    vvi DP(n+1,vi(w+1));

    DP[0][0];


    return 0; 
}