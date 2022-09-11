#include<iostream>
#include<bits/stdc++.h>
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
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(a[j]<a[i])
//             {
//                 swap(&a[j],&a[i]);
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

/* 1. Recursive Approach */

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection(vector<int> &a, int r, int c, int mx){
    if(!r)  
        return; 
    if(r<c){
        if(a[mx]<a[c] && mx!=c)
            mx = c;
        selection(a,r,c+1,mx);
    }
    else{
        swap(&a[r],&a[mx]);
        selection(a,r-1,0,0);
    }
}
int main(){
    vector<int> a = {20,19,18,17,16,15};
    selection(a,a.size(),0,0);

    for(auto it : a)
        cout<<it<<" ";
    return 0; 
}