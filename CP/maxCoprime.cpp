#include<bits/stdc++.h>
using namespace std;
int coprime(){
    int n, x; 
    cin>>n; 
    vector<int> Hash(1000,-1); 
    int mx = -1;
    for(int i=1;i<=n;i++){
        cin>>x; 
        mx = max(mx,x); 
        Hash[x] = i; 
    }
    int ans = -1; 
    for(int i=1;i<=mx;i++){
        if(Hash[i]!=-1){
            for(int j=1;j<=mx;j++){    
                if(Hash[j]!=-1 && __gcd(i,j)==1)
                    ans = max(ans,Hash[i]+Hash[j]); 
            }
        }
    }
    return ans; 
}
int main(){ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    int t; // no. of test cases; 
    cin>>t; 
    while(t--){
        cout<<coprime()<<endl;
    }

    return 0; 
}