#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

vi a;
int DP[100][100];
int solve(int i, int j){
    if(i==j) return a[i];
    if(i>j) return 0; 

    if(DP[i][j]!=-1)
        return DP[i][j]; 

    int c1 = a[i] + min(solve(i+2,j),solve(i+1,j-1));
    int c2 = a[j] + min(solve(i+1,j-1),solve(i,j-2));

    return DP[i][j] = max(c1,c2);
}
signed main(){
    memset(DP,-1,sizeof(DP));
    int n; cin>>n; 
    a = vi(n);
    for(auto &i : a)
        cin>>i; 

    cout<<solve(0,n-1)<<endl;

    return 0;
}