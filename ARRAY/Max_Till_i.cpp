#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 0, 5, 4, 6, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int mx = INT_MIN; 

    for(int i=0;i<n;i++)
    {
        mx = max(mx, a[i]);
        cout<<mx<<" ";
    }
    return 0;
}