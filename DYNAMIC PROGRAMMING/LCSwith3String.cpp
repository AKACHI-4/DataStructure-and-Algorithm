#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int DP[100][100][100];

int LCSin3(string &a, string &b, string &c, int i, int j, int k){
    if(i<0 or j<0 or k<0)
        return 0; 

    if(DP[i][j][k]!=-1)
        return DP[i][j][k];

    if(a[i]==b[j] and b[j]==c[k])
        return DP[i][j][k] = 1 + LCSin3(a,b,c,i-1,j-1,k-1);
    else{
        int m = LCSin3(a,b,c,i-1,j,k);
        int n = LCSin3(a,b,c,i,j-1,k);
        int o = LCSin3(a,b,c,i,j,k-1);

        return DP[i][j][k] = max({m,n,o});
    }
}
signed main(){
    memset(DP,-1,sizeof DP );
    string s1, s2, s3;
    cin>>s1>>s2>>s3; 
    cout<<LCSin3(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);

    return 0;
}