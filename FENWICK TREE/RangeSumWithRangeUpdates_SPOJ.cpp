#include<bits/stdc++.h>
using namespace std;
int query(int idx, int BIT[], int n){
    int ans = 0; 
    while(idx>0){
        ans += BIT[idx]; 
        idx -= idx & -(idx); 
    }
    return ans;
}
void update(int idx, int inc, int BIT[], int n){
    while(idx<=n){
        BIT[idx] += inc;
        idx += idx & -(idx); 
    }
}
signed main(){
    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        int BIT[n+10] = {0};
        int u; cin>>u; 
        while(u--){
            int l, r, inc; cin>>l>>r>>inc; 
            l++; r++; 
            update(l,inc,BIT,n); // A[L...] + inc
            update(r+1,-inc,BIT,n); // A[R+1...] - inc
            // A[L...R] + inc
        }
        int q; cin>>q; 
        while(q--){
            int w; cin>>w; 
            w++; 
            cout<<query(w,BIT,n)<<endl;; 
        }
    }
    return 0;
}