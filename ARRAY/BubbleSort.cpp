#include "bits/stdc++.h"
using namespace std;

/* 1. Iterative Approach */
// void swap(int* a, int* b)
// {
//     int temp = *a; 
//     *a = *b; 
//     *b = temp; 
// }
// int main()
// {
//     int a[] = {3, 4, 9, 8, 6, 5, 2};
//     int n = sizeof(a)/sizeof(a[0]);
//     int counter = 1; 
//     while(counter < n)
//     {
//         for(int i=0;i<n-counter;i++)
//         {
//             if(a[i]>a[i+1])
//             {
//                 swap(&a[i],&a[i+1]);
//             }
//         }
//         counter++;
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

/* 2. Recursive Approach */
// void bubble(vector<int> &arr, int r, int c){
//     if(!r)
//         return; 
//     if(c<r){
//         if(arr[c]>arr[c+1]){
//             int temp = arr[c];
//             arr[c] = arr[c+1];
//             arr[c+1] = temp;
//         }
//         bubble(arr,r,c+1);
//     }
//     else 
//         bubble(arr,r-1,0);
// }
// int main(){
//     vector<int> arr = {15,14,13,12,11};
//     bubble(arr,arr.size()-1,0); 
//     for(auto i : arr)
//         cout<<i<<" ";
//     return 0;
// }