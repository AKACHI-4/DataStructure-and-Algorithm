#include<bits/stdc++.h>
using namespace std;

int SmallestSubarraySum(int a[], int n, int x){
    int sum = 0, ans = n+1; /* ans = Minimum length */ 
    int st = 0, en = 0; 
    while(en<n){
        while(sum<=x && en<n)
            sum += a[en++];
        while(sum>x && st<n){
            if(en-st < ans)
                ans = en-st;
            sum -= a[st++];
        }
    }
    return ans; 
}

int32_t main(){
    int a[] = {1,4,45,6,10,9};
    int x=51, n=6;

    cout<<SmallestSubarraySum(a,n,x); 
    return 0;
}
