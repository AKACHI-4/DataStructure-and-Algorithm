#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int> 
#define ff first
#define ss second

#define int long long
const int N = 1e5+2, MOD=1e9+7; 
int arr[N];
pair<int,int> Tree[4*N]; 

void Build(int root, int st, int en){
    if(st==en){
        Tree[root].ff = arr[st];
        Tree[root].ss = 1;
        return ;  
    }
    
    int mid = st + (en-st)/2;

    Build(2*root,st,mid); 
    Build(2*root+1,mid+1,en); 

    pii a = Tree[2*root]; 
    pii b = Tree[2*root+1];

    if(a.ff < b.ff){
        Tree[root].ff = a.ff;
        Tree[root].ss = a.ss;  
    }else if(b.ff < a.ff){
        Tree[root].ff = b.ff; 
        Tree[root].ss = b.ss;  
    }else{
        Tree[root].ff = a.ff; 
        Tree[root].ss = a.ss + b.ss; 
    }
}
pii query(int root, int st, int en, int l, int r){
    // st...en l...r
    // l...r st...en

    // carefully
    if(st>r or en<l){
        pii p;
        p.ff = MOD; 
        p.ss = -1;
        return p; 
    }
    // l.. st...en ..r
    if(st>=l and en<=r)
        return Tree[root]; 

    int mid = st + (en-st)/2; 

    pii q1 = query(2*root,st,mid,l,r); 
    pii q2 = query(2*root+1,mid+1,en,l,r); 

    pii q;

    if(q1.ff<q2.ff){
        q = q1;
        // return q1;
    }else if(q2.ff<q1.ff){
        q = q2;
        // return q2;
    }else{
        // pii q; 
        q.ff = q1.ff; 
        q.ss = q1.ss + q2.ss;
        // return q; 
    }

    return q;
}
void update(int root, int st, int en, int idx, int val){
    if(st==en){
        arr[idx] = val; 
        Tree[root].ff = val;
        Tree[root].ss = 1; 
        return; 
    }

    int mid = st + (en-st)/2; 

    if(idx<=mid)
        update(2*root,st,mid,idx,val);
    else
        update(2*root+1,mid+1,en,idx,val);

    pii a = Tree[2*root]; 
    pii b = Tree[2*root+1];    

    if(a.ff < b.ff){
        Tree[root].ff = a.ff;
        Tree[root].ss = a.ss;  
    }else if(b.ff < a.ff){
        Tree[root].ff = b.ff; 
        Tree[root].ss = b.ss;  
    }else{
        Tree[root].ff = a.ff; 
        Tree[root].ss = a.ss + b.ss; 
    }
}
signed main(){
    int n, m; cin>>n>>m; 
    
    for(int i=0;i<n;i++)
        cin>>arr[i]; 
    
    Build(1,0,n-1); 

    while(m--){
        int btn; cin>>btn;
        // 2 -> query 1 -> update
        if(btn==2){
            int l, r; cin>>l>>r; 
            pii ans = query(1,0,n-1,l,r); 
            cout<<ans.ff<<" "<<ans.ss<<endl;
        }else if(btn==1){
            int idx, val; cin>>idx>>val;
            update(1,0,n-1,idx,val);
        }else
            break;
    }

    return 0;
}