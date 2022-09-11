#include<bits/stdc++.h>
using namespace std;

void MaxSubarraySum(int a[], int n, int k, int x){
    int sum = 0, ans=0; 
    for(int i=0;i<k;i++)
        sum += a[i];
    if(sum<x)
        ans = sum; 
    for(int i=k;i<n;i++){
        sum -= a[i-k];
        sum += a[i];

        if(sum<x)
            ans = max(ans, sum);
    }
    cout<<ans<<" is the max subarray sum."<<endl; 
}

int32_t main(){
    int arr[] = {7,5,4,6,8,9};
    int n = 6, k = 3, x = 20; 
    MaxSubarraySum(arr,n,k,x);
    return 0;
}