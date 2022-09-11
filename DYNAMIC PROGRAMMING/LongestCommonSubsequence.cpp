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

// const int N = 1e3+2;

// int DP[N][N];

// int LCS(string &a, string &b, int n, int m){
//     if(n<0 || m<0)
//         return 0;  
//     if(DP[n][m]!=-1) 
//         return DP[n][m];
//     if(a[n]==b[m])
//         return DP[n][m] = 1 + LCS(a,b,n-1,m-1);
//     return DP[n][m] = max(LCS(a,b,n,m-1),LCS(a,b,n-1,m));
// }
// signed main(){
//     rep(i,0,N){
//         rep(j,0,N)
//             DP[i][j] = -1; 
//     }

//     string s1, s2; 
//     cin>>s1>>s2; 

//     int n=s1.size(), m=s2.size(); 

//     cout<<LCS(s1,s2,n-1,m-1)<<endl;

//     return 0;
// }

signed main(){
    string a, b; 
    cin>>a>>b; 

    int n=a.size(), m=b.size(); 

    vvi DP(n+1,vi(m+1,1));

    rep(i,0,n+1){
        rep(j,0,m+1){
            if(i==0 || j==0){
                DP[i][j] = 0; 
                continue;
            }
            if(a[i-1]==b[j-1])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
        }
    }

    cout<<DP[n][m]<<endl;

    return 0; 
}