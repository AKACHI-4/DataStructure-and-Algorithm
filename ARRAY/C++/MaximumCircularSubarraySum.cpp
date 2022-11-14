#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kadane(int a[], int n)
{
    int currsum = 0; 
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        currsum += a[i];
        if(currsum<0)
        {
            currsum = 0;
        }
        maxsum = max(maxsum,currsum);
    }
    return maxsum; 
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

    int wrapsum; 
    int nonwrapsum; 

    nonwrapsum = kadane(a,n);

    int TotalSum=0; 
    for(int i=0;i<n;i++)
    {
        TotalSum += a[i];
        a[i] = -a[i];
    }

    wrapsum = TotalSum + kadane(a,n); // here kadane is for reversed sign array 

    cout<<max(wrapsum, nonwrapsum)<<endl;

    return 0;
}