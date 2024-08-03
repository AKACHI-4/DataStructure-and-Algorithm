#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+2, MOD = 1e9+7; 
int Tree[4*N]; 

struct triplet{ 
    int l, r, idx; 
}; 
int query(int root, int st, int en, int l, int r){
    // st...en l...r
    // l...r st...en

    // carefully
    if(st>r or en<l)
        return 0; 
    // l.. st...en ..r
    if(st>=l and en<=r)
        return Tree[root]; 

    int mid = st + (en-st)/2; 

    int q1 = query(2*root,st,mid,l,r); 
    int q2 = query(2*root+1,mid+1,en,l,r); 

    return q1+q2; 
}
void update(int root, int st, int en, int idx, int val){
    if(st==en){
        Tree[root] = val; 
        return; 
    }

    int mid = st + (en-st)/2; 

    if(idx<=mid)
        update(2*root,st,mid,idx,val);
    else
        update(2*root+1,mid+1,en,idx,val);

    Tree[root] = Tree[2*root] + Tree[2*root+1];
}
bool compare(triplet &a, triplet &b){
    return a.r < b.r;
}
signed main(){
    int n; cin>>n; 
    triplet t1; 
    t1.l = t1.r = -1;
    vector<triplet> T(n,t1); 
    for(int i=0;i<2*n;i++){
        int x; cin>>x; 
        if(T[x-1].l==-1)
            T[x-1].l = i ;
        else
            T[x-1].r = i;
        T[x-1].idx = x; 
    }
    
    sort(T.begin(),T.end(),compare); 

    vector<int> ans(n);

    for(int i=0;i<n;i++){
        ans[T[i].idx-1] = (T[i].r - T[i].l - 1) - 2*query(1,0,2*n-1,T[i].l,T[i].r);
        update(1,0,2*n-1,T[i].l,1); 
    }
    
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" "; 

    return 0;
} // RUNTIME ERROR