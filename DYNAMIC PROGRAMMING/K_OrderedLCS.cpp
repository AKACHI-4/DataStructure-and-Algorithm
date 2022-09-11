#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int DP[100][100];

int K_LCS(string &a, string &b, int i, int j, int k){
    if(i<0 or j<0)
        return 0; 
    
    if(DP[i][j]!=-1)
        return DP[i][j];
    
    // Reccurence
    int sol1(0), sol2(0), sol3(0);
    if(a[i]==b[j])
        sol1 = 1 + K_LCS(a,b,i-1,j-1,k);
    if(k>0)
        sol2 = 1 + K_LCS(a,b,i-1,j-1,k-1);
    sol3 = max(K_LCS(a,b,i-1,j,k),K_LCS(a,b,i,j-1,k));

    return max({sol1,sol2,sol3});
}
signed main(){
    memset(DP,-1,sizeof DP);
    string s1, s2; 
    cin>>s1>>s2; 
    int k; cin>>k;
    cout<<K_LCS(s1,s2,s1.size()-1,s2.size()-1,k)<<endl;
    return 0;
}