// #include "bits/stdc++.h"
// using namespace std; 
// #define vi vector<int> 

// void merge(vi &arr, int st, int mid, int en){
//     int l1 = mid+1;
//     int l2 = en+1;
//     vi ans((en-st)+1);
//     int i=st,j=mid+1, k=0;
//     while(i<l1 && j<l2){
//         if(arr[i]<arr[j])
//             ans[k++] = arr[i++];
//         else
//             ans[k++] = arr[j++];
//     }
//     while(j<l2)
//         ans[k++] = arr[j++];
//     while(i<l1)
//         ans[k++] = arr[i++];
//     for(i=0;i<k;i++)
//         arr[st+i] = ans[i];
// }
// void MergeSort(vi &a, int st, int en){
//     if(st>=en) return;
//     int mid = st + (en-st)/2;
//     MergeSort(a,st,mid);
//     MergeSort(a,mid+1,en);
//     merge(a,st,mid,en);   
// }
// void mergeSort(vi &arr, int n) {
//     MergeSort(arr,0,n-1);
// }
// int main(){
//     vi arr = {4,3,1,6,7,5,2};
//     mergeSort(arr,7);
//     for(auto i : arr)
//         cout<<i<<" ";
//     return 0; 
// }

