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

    vi a(n); 
    for(auto &i : a)
        cin>>i; 
    
    // every single element can be considered as sequence so we assume length 1 first 

    vi forward(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                forward[i] = max(forward[i],1+forward[j]);
        }
    }

    vi backward(n,1);
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j])
                backward[i] = max(backward[i],1+backward[j]);
        }
    }

    int LBS=0; 
    rep(i,0,n)
        LBS = max(LBS, forward[i] + backward[i] - 1); 

    cout<<LBS<<endl;

    return 0;
}