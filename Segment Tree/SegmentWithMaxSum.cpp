#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct GRP{
    int pref, suff, sum, ans;
    GRP(int a, int b, int c, int d){
        pref = a; 
        suff = b; 
        sum = c; 
        ans = d;
    }
};

const int N = 1e5+2;
int arr[N]; 
struct GRP* Tree[4*N]; 

void Build(int root, int st, int en){
    if(st==en){
        if(arr[st]<=0)
            Tree[root] = new GRP(0,0,arr[st],0);
        else
            Tree[root] = new GRP(arr[st],arr[st],arr[st],arr[st]); 
        return; 
    }

    int mid = st + (en-st)/2; 

    Build(2*root,st,mid); 
    Build(2*root+1,mid+1,en); 

    int pref = max(Tree[2*root]->pref,(Tree[2*root]->sum+Tree[2*root+1]->pref));
    int suff = max(Tree[2*root+1]->suff,(Tree[2*root]->suff+Tree[2*root+1]->sum)); 
    int sum  = Tree[2*root]->sum + Tree[2*root+1]->sum; 
    int ans = max({Tree[2*root]->ans,Tree[2*root+1]->ans,Tree[2*root]->suff+Tree[2*root+1]->pref});

    Tree[root] = new GRP(pref,suff,sum,ans); 
}
void update(int root, int st, int en, int idx, int val){
    if(st==en){
        arr[st] = val; 
        if(arr[st]<=0)
            Tree[root] = new GRP(0,0,arr[st],0);
        else 
            Tree[root] = new GRP(arr[st],arr[st],arr[st],arr[st]); 
        return ; 
    }

    int mid = st + (en-st)/2; 

    if(idx<=mid){
        update(2*root,st,mid,idx,val);
    }else{
        update(2*root+1,mid+1,en,idx,val);
    }

    int pref = max(Tree[2*root]->pref,(Tree[2*root]->sum+Tree[2*root+1]->pref));
    int suff = max(Tree[2*root+1]->suff,(Tree[2*root]->suff+Tree[2*root+1]->sum)); 
    int sum  = Tree[2*root]->sum + Tree[2*root+1]->sum; 
    int ans = max({Tree[2*root]->ans,Tree[2*root+1]->ans,Tree[2*root]->suff+Tree[2*root+1]->pref});

    Tree[root] = new GRP(pref,suff,sum,ans);  
}
signed main(){
    int n, m; cin>>n>>m; 

    for(int i=0;i<n;i++)
        cin>>arr[i];

    Build(1,0,n-1);
    for(int i=1;i<=11;i++)
        cout<<Tree[i]->pref<<" "<<Tree[i]->suff<<" "<<Tree[i]->sum<<" "<<Tree[i]->ans<<endl;

    while(m--){
        int idx, val; 
        cin>>idx>>val; 
        update(1,0,n-1,idx,val); 
        cout<<Tree[1]->ans<<endl; 
    }

    return 0;
}