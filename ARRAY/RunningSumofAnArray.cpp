#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* BASIC */
int Sum(int a[], int n)
{
    if(n<=0)
        return 0; 
    return (Sum(a,n-1) + a[n-1]);
}
int main()
{
    int n; 
    cin>>n; 
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<Sum(a, n);
    return 0; 
}


// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int ans[n];
//     ans[0] = a[0];
//     cout<<ans[0]<<" ";
//     for(int j=1;j<n;j++)
//     {
//         for(int k=j;k>=0;k--)
//         {
//         ans[j] += a[k];
//         }
//         cout<<ans[j]<<" ";
//     }
//     return 0;
// }