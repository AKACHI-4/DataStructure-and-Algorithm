#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+2; 
int arr[N], Tree[4*N]; 

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
void update(int root, int st, int en, int idx, int val){
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

    Tree[root] = max(Tree[2*root],Tree[2*root+1]);
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
        }
        else if(btn==2){
            int idx, val; cin>>idx>>val;
            update(1,0,n-1,idx,val); 
            cout<<Tree[idx]<<endl;
        }
        else
            break;
    }

    cout<<endl;

    return 0;
}