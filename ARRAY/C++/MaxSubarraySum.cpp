/*
Problem- Find the subarray in an array which has maximum sum
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n=4;
    int a[n] = {-1, 4, 7, 2};


    // /* Brute force Approach: */
    // int MaxSum=INT_MIN; 
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         int sum = 0; 
    //         for(int k=i;k<=j;k++)
    //         {
    //             sum += a[k];
    //         }
    //         cout<<sum<<endl;
    //         MaxSum = max(MaxSum, sum);
    //     }
    // }
    // cout<<endl<<MaxSum<<endl; 
    // Time Complexity : O(n^3)
 

    /* Cumulative Sum Approach */
    // int currsum[n+1];
    // currsum[0] = 0;

    // for(int i=1;i<=n;i++)
    // {
    //     currsum[i] = currsum[i-1] + a[i-1];
    // }

    // int maxsum = INT_MIN; 
    // for(int i=1;i<=n;i++)
    // {
    //     int sum=0;
    //     for(int j=0;j<i;j++)
    //     {
    //         sum = currsum[i] - currsum[j];
    //         maxsum = max(sum, maxsum);
    //     } 
    // }    

    // cout<<maxsum<<endl; 
    // Time Complexity : O(n^2)


    /* 
    Kadane's Algorithm 
    
    We would start from the last element and calculate the sum of every possible subarray ending with the element A[n-1]. Then, we would calculate the sum of every possible subarray ending with A[n-2], A[n-3] and so on up to A[0].
    */

    // int currsum = 0;
    // int maxsum = INT_MIN; 

    // for(int i=0;i<n;i++)
    // {
    //     currsum += a[i];
    //     /*
    //      In below one we store the value of currsum in mxsum so when currsum becomes 0 so we have a optional part in the form of mxsum
    //     */
    //     if(maxsum < currsum)
    //     {
    //         maxsum = currsum;     
    //     }
    //     if(currsum<0)
    //     {
    //         currsum = 0;
    //     }
    // }
    // cout<<maxsum<<endl; 
    // Time Complexity : O(n)


    return 0;
}

