/*
Pair Sum Problem

Find whether there exist 2 numbers that sum to K.

Important: The Array should be sorted for two pointer approach.

Idea: keep a low and high pointer, decide which pointer to move on the basis of arr[low] + arr[high].

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool PairSum_Brute(int a[], int n, int k)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]+a[j]==k)
            {
                cout<<i<<" "<<j<<endl; 
                return true;
            }
        }
    }
    return false; 
}   // Time Complexity : O(n^2)

bool PairSum_TwoPointer(int a[], int n, int k) // For this approach array should be sorted then we can use this approach if it is not then we have to sort the array first
{
    int low = 0; 
    int high = n-1; 

    while(low<high)
    {
        if(a[low]+a[high]==k)
        {
            cout<<low<<" "<<high<<endl; 
            return true; 
        }
        else if(a[low]+a[high]>k)
        {
            high--; 
        }
        else
        {
            low++; 
        }
    }
    return false; 
}

int main()
{
    
    int a[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31; 

    cout<<PairSum_Brute(a,8,k)<<endl;

    cout<<PairSum_TwoPointer(a,8,35)<<endl; 

    return 0; 
}