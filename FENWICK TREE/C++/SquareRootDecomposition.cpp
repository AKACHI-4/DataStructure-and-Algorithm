#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 


signed main(){
    int n; cin>>n; 
    vi a(n); 
    for(auto &i : a)
        cin>>i; 

    int len = sqrt(n) + 1;
    vi b(len); 
    for(int i=0;i<n;i++)
        b[i/len] += a[i];

    int q; cin>>q; 
    while(q--){
        int l, r; cin>>l>>r;
        l--; r--;
        int sum = 0; 
        for(int i=l;i<=r;){
            if(i%len==0 and i+len-1<=r){
                sum += b[i/len]; 
                i += len; 
            }else{
                sum += a[i]; 
                i++; 
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}