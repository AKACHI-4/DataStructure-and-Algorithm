#include<bits/stdc++.h>
using namespace std;

int PeakElement(int a[], int L, int H, int n){
    int mid = L+(H-L)/2; /* never exceed integer range */    
    if( (mid==0 || a[mid-1] <= a[mid]) && (mid==n-1 || a[mid+1] <= a[mid] ) )
        return mid; 
    else if(mid>0 && a[mid-1] > a[mid])
        return PeakElement(a, L, mid-1, n);
    else    
        return PeakElement(a, mid+1, H, n);
}

int32_t main(){
    int arr[] = {0,6,8,5,7,9};
    int n = 6, ans = PeakElement(arr,0,n-1,n);

    cout<<"Peak Element is "<<arr[ans]<<" at "<<ans<<endl; 

    return 0;
}