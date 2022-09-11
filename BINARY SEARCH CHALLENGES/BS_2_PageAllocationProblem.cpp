#include<bits/stdc++.h>
using namespace std;

bool IsPossible(int a[], int n, int m, int m1){
    int SR = 1, sum = 0; 
    for(int i=0;i<n;i++){
        if(a[i]>m1)
            return false; 
        if(sum+a[i]>m1){
            SR++; 
            sum = a[i];
            if(SR>m)
                return false;
        }
        else{
            sum += a[i];
        }
    }
    return true;
}
int allocateMinimumPages(int a[], int n, int m){
    int sum = 0; 
    if(n<m)
        return -1;
    for(int i=0;i<n;i++)
        sum += a[i];
    int s=0, e=sum, ans=INT_MAX;
    while(s<=e){
        int mid = (s+e)/2;
        if(IsPossible(a,n,m,mid)){
            ans = min(ans, mid);
            e = mid-1;
        }
        else{
            s = mid+1; 
        }
    }
    return ans;   
}
int32_t main(){
    int a[] = {12,34,67,90};  
    cout<<allocateMinimumPages(a,4,2);  
    return 0;
}