#include<bits/stdc++.h>
using namespace std;

/* Check if an array is sorted or not */
// Approach - 1
// bool sorted(int a[], int n)
// {
//     if(n==1)
//     {
//         return true;
//     }
//     return ( ( a[0]<a[1] ) && sorted(a+1, n-1) ); 
// }
// int main()
// {   
//     int a[] = {1,2,3,4,5,6,7,8,9};
//     cout<<sorted(a, 9)<<endl; 
//     return 0;
// }
// Approach - 2
// #include<bits/stdc++.h>
// using namespace std;
// bool checksorted(int arr[], int n){
//     if(!n)
//         return true;
//     if(arr[n]<arr[n-1])
//         return false;
//     return checksorted(arr, n-1);
// }
// signed main(){
//     int arr[] = {1,2,9,4,5};
//     cout<<checksorted(arr,5);
//     return 0;
// }


/* Print numbers till n */

/* 1. Decreasing order */
// void Dec(int n)
// {
//     if(n==0)
//     {
//         return; 
//     }
//     cout<<n<<endl;
//     // Backtrack 
//     Dec(n-1);
// }
// int main()
// {
//     int n; 
//     cin>>n; 
//     Dec(n);
// }

/* 2. Increasing order */
// void Inc(int n)
// {
//     if(n==0)
//     {
//         return; 
//     }
//     Inc(n-1);
//     cout<<n<<endl; 
// }
// int main()
// {
//     int n; 
//     cin>>n; 
//     Inc(n);
// }


/* Find the first and last occurence of a number in an array */
// int LastOccur(int a[], int n, int i, int key)
// {
//     if(i==n)
//         return -1; 
//     if((LastOccur(a,n,i+1,key) != -1))
//         return LastOccur(a,n,i+1,key);
//     // Backtrack 
//     if(a[i] == key)
//         return i;
//     return -1; 
// }
// int FirstOccur(int a[], int n, int i, int key)
// {
//     if(i == n)
//         return -1; 
//     if(a[i] == key)
//         return i; 
//     return FirstOccur(a, n, i+1, key);
// }
// int32_t main()
// {
//     int a[] = {4,2,1,2,5,2,7};
//     cout<<FirstOccur(a,7,0,2)<<endl;
//     cout<<LastOccur(a,7,0,2)<<endl;
// }   
void Dec(int i, int n){
    if(i>n)
        return;
    Dec(i+1,n);
    cout<<i<<endl;
}
int main(){
    int n; cin>>n; 
    Dec(1,n);
    return 0; 
}