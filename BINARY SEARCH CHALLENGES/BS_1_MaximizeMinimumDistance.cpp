#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int a[], int n, int k){
    int pos = a[0], elements = 1;
    /* we already has been considerd 0th element as per indexing */ 
    for(int i=1;i<n;i++){
        if(a[i]-pos >= mid){
            pos = a[i];
            elements++;
            if(elements==k)
                return true;
        }
    }
    return false; 
}
int Largest_MinDistance(int a[], int n, int k){
    sort(a,a+n);
    int res = -1; 
    int left = a[0], right = a[n-1];
    while(left<right){
        int mid = (left+right)/2; // left+(right-left)/2;
        if(isFeasible(mid,a,n,k)){
            /* Left binary search */ 
            res = max(res,mid); 
            left = mid+1;
        }
        else{
            /* right binary search */ 
            right = mid;
        }
    }
    return res ; 
}
int32_t main(){
    int arr[] = {2,4,5,7,6};
    cout<<Largest_MinDistance(arr,5,3)<<endl; 
    return 0;
}