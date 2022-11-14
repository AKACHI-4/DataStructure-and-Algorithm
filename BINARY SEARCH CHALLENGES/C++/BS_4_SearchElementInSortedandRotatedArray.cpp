#include<bits/stdc++.h>
using namespace std;

int SearchInRotatedArray(int a[], int key, int L, int R){
    if(L>R) /* Invalid Range */
        return -1;
    int mid = (L+R)/2;
    if(a[mid]==key){
        return mid;
    } 
    if(a[L]<=a[mid]){
        if(key>=a[L] && key<=a[mid])
            return SearchInRotatedArray(a,key,L,mid-1);
        return SearchInRotatedArray(a,key,mid+1,R);
    }
    if(key>=a[mid] && key<=a[R]){
        return SearchInRotatedArray(a,key,mid+1,R);
    }
    return SearchInRotatedArray(a,key,L,mid-1);
}

int32_t main(){
    int a[] = {6,7,8,9,10,1,2,5};
    int n = 8, key = 8;
    int ans = SearchInRotatedArray(a,key,0,7);
    if(ans==-1)
        cout<<"Key Doesn't Exist !!"<<endl;
    else
        cout<<"Key is present at index : "<<ans<<endl;
    return 0;
} 