#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {9, 2, 7, 6, 4, 8, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++)
    {
        int current = a[i];
        int j=i-1;
        while(a[j]>current && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current; 
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}