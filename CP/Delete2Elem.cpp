#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define mii map<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)


void deletePairs(){
    int n; 
    cin>>n; 
    int a[n]; 
    rep(i,0,n) cin>>a[i]; 
    mii mp;
    int Sum = 0;  
    rep(i,0,n){
        Sum += a[i]; 
        mp[a[i]]++; 
    }
    int deleteSum = (Sum*2)/n;
    if((Sum*2)%n){
        cout<<0<<endl; 
        return; 
    }
    int ans = 0; 
    for(auto it : mp){
        if(it.first > deleteSum) break; 
        int rem = deleteSum - it.first; 
        if(rem < it.first) break;
        else if(rem == it.first) ans += ((it.second)*(it.second-1))/2; 
        else ans += (it.second * mp[rem]);
    }

    cout<<ans<<endl; 
}
int main(){ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    int t; // no. of test cases; 
    cin>>t; 
    while(t--){
        deletePairs(); 
    }

    return 0; 
}