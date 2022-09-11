#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> BIT; 
int query(int idx){
    int ans = 0; 
    while(idx>0){
        ans += BIT[idx]; 
        idx -= idx & -(idx);
    }
    return ans; 
}
void update(int idx, int val){ 
    while(idx<=n){
        BIT[idx] += val; 
        idx += idx & -(idx); 
    }
}
signed main(){
    cin>>n; 
    BIT = vector<int>(n); 
    vector<int> a(n+1); 
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        update(i,a[i]); 
    }

    int q; cin>>q; 
    while(q--){
        int btn; cin>>btn; 
        if(btn==1){
            int l, r; cin>>l>>r; 
            int ans = query(r) - query(l-1);
            cout<<ans<<endl;
        }else{
            int idx,val; cin>>idx>>val; 
            update(idx,-a[idx]); 
            a[idx] = val;
            update(idx,val); 
        }
    }

    return 0;
}