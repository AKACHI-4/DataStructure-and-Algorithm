#include<bits/stdc++.h>
using namespace std;

#define int long long
 
const int N = 1e5+2;
int arr[N]; 
int Tree[4*N]; 

void Build(int root, int s, int e){
    if(s==e){
        Tree[root] = arr[s];
        return; 
    }
    int mid = s + (e-s)/2; 
    Build(2*root,s,mid); 
    Build(2*root+1,mid+1,e); 
    Tree[root] = Tree[2*root] + Tree[2*root+1]; 
}
void update(int root, int s, int e, int idx){
    // here s = e = idx at base condition 
    if(s==e){
        if(arr[s]==0){
            arr[s] = 1;
            Tree[root] = 1; 
        }else{
            arr[s] = 0;
            Tree[root] = 0; 
        }
        return; 
    }
    int mid = s + (e-s)/2; 
    if(idx <= mid)
        update(2*root,s,mid,idx); 
    else
        update(2*root+1,mid+1,e,idx); 
    Tree[root] = Tree[2*root] + Tree[2*root+1]; 
}
int query(int root, int s, int e, int k){
    if(s==e)
        return s; 
    
    int mid = s + (e-s)/2; 

    if(k < Tree[2*root])
        return query(2*root,s,mid,k);
    else
        return query(2*root+1,mid+1,e,k-Tree[2*root]); 
}
signed main(){
    int n, m; cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i]; 
    Build(1,0,n-1); 
    for(int i=1;i<10;i++)
        cout<<Tree[i]<<" "; 
    cout<<endl; 
    while(m--){
        int btn; cin>>btn; 
        if(btn==1){
            int idx; cin>>idx; 
            update(1,0,n-1,idx); 
        }else{
            int k; cin>>k; 
            int ansidx = query(1,0,n-1,k); 
            cout<<ansidx<<endl; 
        }
    }
    return 0;
}