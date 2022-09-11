#include<bits/stdc++.h>
using namespace std;

#define vll vector<long long> 
#define rep(i,a,b) for(int i=a;i<b;i++)

// Fibonacci Sequence: 0, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,.....  
const int N = 1e5+2, MOD = 1e9+7; 

// MEMOIZATION 
long long DP[N]; // 1D-DP
long long fib(int n){
    // we are assuming index as position that's why one extra zero U can modify code as per your comfort
    if(n==0||n==1)  return 0; 
    if(n==2) return 1;  
    // DP Check part
    if(DP[n]!=-1)
        return DP[n];
    return DP[n] = fib(n-1) + fib(n-2); // memoization part
}
signed main(){
    int n; cin>>n; 
    rep(i,0,N)
        DP[i] = -1;
    cout<<fib(n)<<endl;
    return 0;
} // Time Complexity: O(n)

// TABULATION 
signed main(){
    int n; cin>>n; 

    vll Fib(n+1);
    // we are assuming index as position that's why one extrazero U can modify code as per your comfort
    Fib[0] = 0; 
    Fib[1] = 0; 
    Fib[2] = 1;
    // Bottom-up(*Tabulation part below here)
    for(int i=3;i<=n;i++)
        Fib[i] = Fib[i-1] + Fib[i-2];

    cout<<Fib[n]<<endl;

    return 0;
}