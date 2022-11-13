/* Normal Merge */ 

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

vector<int> merge(vi &a, vi &b){
    int n1 = a.size(), n2 = b.size();
    int i=0,j=0,k=0; 
    vi ans(n1+n2);
    while(i<n1 or j<n2){
        if(a[i]<b[j]){
            ans[k] = a[i];
            i++; k++; 
        }
        else{
            ans[k] = b[j];
            j++; k++;
        }
    }
    /* if any one of the array will not be traversed completely */
    while(i<n1){
        ans[k] = a[i];
        k++; i++; 
    }
    while(j<n2){
        ans[k] = b[j];
        k++; j++; 
    }
    
    return ans;
}
vector<int> mergesort(vi &a, int st, int en){

    if(a.size()==1)
        return a; 
    
    int mid = st + (en-st)/2;
    vi left = mergesort(a,st,mid);
    vi right = mergesort(a,mid+1,en);

    return merge(left,right);
}
signed main(){
    int n, i; cin>>n; 
    vector<int> a(n);
    for(auto i : a)
        cin>>i;
    vi ans(n); 
    ans = mergesort(a,0,n);
    for(auto i : ans)
        cout<<i<<" "; 
    return 0;
}