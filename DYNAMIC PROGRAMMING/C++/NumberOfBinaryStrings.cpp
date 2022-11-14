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
    int n; cin>>n; 
    vi Fib(n+2,0);
    Fib[0] = 1;
    Fib[1] = 1; 
    rep(i,2,n+2)
        Fib[i] = Fib[i-2] + Fib[i-1];
    cout<<Fib[n+1]<<endl;
    return 0;
}