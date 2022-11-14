/*
Problem- Given an unsorted array A of size N of non-negative integers, find a continuous subarray which adds to a given number S.

Constraints
1 <= N <= 10^5
0 <= Ai <= 10^10

Example

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}

Output: 2 4

Explanation: The sum of elements from 2nd position to 4th position is 12.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, s; 
    cin>>n>>s; 

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int i=0, j=0, st=-1, en=-1, sum=0; // i and j are iterator of two-pointer

    while(j<n && sum+a[j]<=s)
    {
        sum += a[j];
        j++;
    }
    
    if(sum == s)
    {
        cout<<i+1<<" "<<j<<endl; // j is already incremented
        return 0; 
    }
    /*
        increasing of j because it is also possible for last value of j, s cann't be determined bcz in increasing i and substract i with currsum can reduce currsum more then our expectation that's why increment of j is also necessary
    */
    while(j<n)
    {
        sum += a[j];
        while(sum > s)
        {
            sum -= a[i];
            i++;
        }

        if(sum == s)
        {
            st = i+1;
            en = j+1; 
            break; 
        }
        j++; 
    }

    cout<<st<<" "<<en<<endl; 

    return 0;
}