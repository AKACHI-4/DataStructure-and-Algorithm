#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int arr[N], SegTree[4*N]; 

void Build(int root, int st, int en){
    if(st==en){
        SegTree[root] = arr[st];
        return; 
    }

    int mid = st + (en-st)/2; 

    Build(2*root,st,mid); 
    Build(2*root+1,mid+1,en); 

    SegTree[root] = SegTree[2*root] + SegTree[2*root+1]; 
}

int query(int root, int st, int en, int l, int r){
    // l...r  st...en
    // st...en l...r

    // doesn't lies
    if(st>r or en<l) 
        return 0; 

    // completely lies
    if(st>=l and en<=r)
        return SegTree[root];

    // overlaps

    int mid = st + (en-st)/2; 

    int q1 = query(2*root,st,mid,l,r); 
    int q2 = query(2*root+1,mid+1,en,l,r); 

    return q1 + q2; 
}

signed main(){
    int n; cin>>n; 

    for(int i=0;i<n;i++)
        cin>>arr[i];

    Build(1,0,n-1); 

    for(int i=1;i<(2*n);i++)
        cout<<SegTree[i]<<" "; 
    cout<<endl;

    while(1){
        int btn; cin>>btn; 
        if(btn!=1)
            break;

        int l, r; cin>>l>>r;
        cout<<query(1,0,n-1,l,r)<<endl; 
    }

    return 0;
}