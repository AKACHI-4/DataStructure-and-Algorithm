#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
int n; 
vi BIT;
int getSum(int idx){
    int sum = 0; 
    while(idx>0){
        sum += BIT[idx];
        idx -= idx & -(idx);
    }
    return sum;
}
void update(int idx, int inc){
    while(idx<=n){
        BIT[idx] += inc; 
        idx += idx & -(idx); 
    }
}
signed main(){
    cin>>n; 
    vi a(n); 
    for(auto &i : a)
        cin>>i; 
    vi temp = a; 
    sort(temp.begin(),temp.end()); 
    for(int i=0;i<n;i++)
        a[i] = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin() + 1; 
    BIT = vi(n+1); 
    int inv = 0; 
    for(int i=n-1;i>=0;i--){
        inv += getSum(a[i]-1); 
        update(a[i],1);
    }
    cout<<inv<<endl;
    return 0;
}// TC : O(nlogn)