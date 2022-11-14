/*
Problem-
Find the smallest positive missing number in the given array.
Example: [0, -10, 1, 3, -20], Ans = 2

Intuition-
If in O(1), we can tell if an element is present in an array, then our task will be simpler.
For that, we will maintain a Check[ ] array, that will if an element x is present in the array or not.
It will be of boolean type as we only need to check the presence or absence of the number.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; 
    cin>>n; 

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    const int N = 1e6+2; 
    bool check[N];
    for(int i=0;i<N;i++)
    {
        check[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            check[a[i]]=true; 
        }
    }
    
    int ans = -1; 
    for(int i=1;i<N;i++)
    {
        if(check[i]==false)
        {
            ans = i; 
            break; 
        }
    }

    cout<<ans<<endl;
    return 0;
}