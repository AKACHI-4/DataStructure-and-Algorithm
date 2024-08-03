#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+2; 
int arr[N], Tree[4*N], Lazy[4*N]; 

void Build(int root, int st, int en){
    if(st==en){
        Tree[root] = arr[st];
        return ;  
    }
    
    int mid = st + (en-st)/2;

    Build(2*root,st,mid); 
    Build(2*root+1,mid+1,en); 

    Tree[root] = max(Tree[2*root],Tree[2*root+1]); 
}

int query(int root, int st, int en, int l, int r){
    // st...en l...r
    // l...r st...en

    // carefully
    if(st>r or en<l)
        return INT_MIN; 
    // l.. st...en ..r
    if(st>=l and en<=r)
        return Tree[root]; 

    int mid = st + (en-st)/2; 

    int q1 = query(2*root,st,mid,l,r); 
    int q2 = query(2*root+1,mid+1,en,l,r); 

    return max(q1,q2); 
}

void pointUpdate(int root, int st, int en, int idx, int val){
    if(st==en){
        arr[idx] = val; 
        Tree[root] = val; 
        return; 
    }

    int mid = st + (en-st)/2; 

    if(idx<=mid)
        update(2*root,st,mid,idx,val);
    else
        update(2*root+1,mid+1,en,idx,val);

    Tree[root] = min(Tree[2*root],Tree[2*root+1]);
}

// l, r -> range to increase value with val
void rangeUpdate(int root, int st, int en, int l, int r, int val) {
    if (Lazy[root] != 0) {
        Tree[root] += Lazy[root];

        // if not a leave node
        if (st != en) {
            Lazy[2*root] += Lazy[root];
            Lazy[2*root+1] += Lazy[root];
        }

        Lazy[root] = 0;    
    }

    // doesn't lies
    if (r<st or l>en or st>en) return;

    // completely lies
    if (st>=l and en<=r) {
        Tree[root] += val;

        if (st != en) {
            Lazy[2*root] += val;
            Lazy[2*root+1] += val;
        }

        return;
    }

    int mid = st + (en - st) >> 1;

    rangeUpdate(2*root, st, mid, l, r, val);
    rangeUpdate(2*root+1, mid+1, en, l, r, val);

    Tree[root] = max(Tree[2*root], Tree[2*root+1]); 
}

void lazyQuery(int root, int st, int en, int l, int r, int val) {
    if (Lazy[root] != 0) {
        Tree[root] += Lazy[root];

        if (st != en) {
            Lazy[2*root] += Lazy[root];
            Lazy[2*root+1] += Lazy[root];
        }

        Lazy[root] = 0;
    } 

    // doesn't lies
    if (r<st or l>en or st>en) return;

    // completely lies
    if (st>=l and en<=r) return Tree[root];

    int mid = st + (en - st) >> 1;

    return min(lazyQuery(2*root, st, mid, l, r, val),lazyQuery(2*root+1, mid+1, en, l, r, val));
}

signed main(){
    int n; cin>>n; 

    for(int i=0;i<n;i++)
        cin>>arr[i];

    // {Max} Segmant tree
    Build(1,0,n-1); 

    for(int i=1;i<=17;i++)
        cout<<Tree[i]<<" ";

    while(1){
        int btn; cin>>btn; 
        if(btn==1){
            int l,r; cin>>l>>r; 
            cout<<query(1,0,n-1,l,r)<<endl; 
        } else if (btn==2) {
            int idx, val; cin>>idx>>val;
            pointUpdate(1,0,n-1,idx,val); 
            cout<<Tree[idx]<<endl;
        } else if (btn==3) {
            int l, r; cin>>l>>r;
            int val; cin>>val;
            rangeUpdate(1,0,n-1,l,r,val); 
            cout<<Tree[idx]<<endl;
        } else if (btn==4) {

        } else break;
    }

    cout<<endl;

    return 0;
}