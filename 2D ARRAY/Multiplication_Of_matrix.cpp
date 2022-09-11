/*
Problem
Given two 2-Dimensional arrays of sizes n1Xn2 and n2Xn3. Your task is to multiply these matrices and output the multiplied matrix.

Constraints
1 <= n1,n2,n3 <= 1,000
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2, n3; 
    cin>>n1>>n2>>n3; 

    int a1[n1][n2], a2[n2][n3];

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin>>a1[i][j];
        }
    }
    
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cin>>a2[i][j];
        }
    }
    
    int ans[n1][n3];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            ans[i][j]=0;
        }
    }

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            for(int k=0;k<n2;k++)
            {
                ans[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }    

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}