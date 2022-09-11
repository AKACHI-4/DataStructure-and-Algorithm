#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n; cin>>n; 
    vector<int> a(n);
    for(auto &i : a)
        cin>>i; 
    sort(a.begin(),a.end());
    long long mx=0, mn=0; 
    for(int i=0;i<n/2;i++){
        mx += (a[n/2+i]-a[i]);
        mn += (a[2*i+1]-a[2*i]);
    }
    cout<<mn<<" "<<mx<<endl; 
    return 0;
}