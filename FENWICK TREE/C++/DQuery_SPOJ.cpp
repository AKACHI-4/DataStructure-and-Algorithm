#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define int long long 
const int N = 1e5+2, MOD = 1e9+7; 
int rootN; 

struct Q{ 
    int l, r, idx; 
};
Q q[N]; 
bool compare(Q q1, Q q2){
    if(q1.l/rootN==q2.l/rootN)
        return q1.r > q2.r;
    return q1.l < q2.l; 
}
signed main(){
    int n; cin>>n; 
    vi a(n);
    for(auto &i : a)
        cin>>i; 
    
    rootN = sqrtl(n); 

    int qu; cin>>qu; 
    for(int i=0;i<qu;i++){
        int l, r; cin>>l>>r; 
        q[i].l = l; 
        q[i].r = r; 
        q[i].idx = i; 
    }

    sort(q,q+qu,compare);
    
    vi ans(qu); 
    int cur_l = 0, cur_r = -1, l, r;
    int cur_ans = 0; 
    vi freq(10*N,0); 

    for(int i=0;i<qu;i++){
        l = q[i].l, r = q[i].r; 
        l--; r--; // 0 based indexing
        while(cur_r<r){
            cur_r++; 
            freq[a[cur_r]]++; 
            if(freq[a[cur_r]]==1)
                cur_ans++; 
        }
        while(cur_l>l){
            cur_l--; 
            freq[a[cur_l]]++; 
            if(freq[a[cur_l]]==1)
                cur_ans++; 
        }
        while(cur_l<l){
            freq[a[cur_l]]--; 
            cur_l++; 
            if(freq[a[cur_l]]==0)
                cur_ans--; 
        }
        while(cur_r>r){
            freq[a[cur_r]]--; 
            cur_r--; 
            if(freq[a[cur_r]]==0)
                cur_ans--;  
        }
        ans[q[i].idx] = cur_ans;
    } 

    for(int i=0;i<qu;i++)
        cout<<ans[i]<<endl; 

    return 0;
}