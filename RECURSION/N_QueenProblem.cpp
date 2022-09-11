#include<bits/stdc++.h>

using namespace std;

bool isSafe(int** a, int x, int y, int n)
{
    for(int row=0;row<x;row++)
    {
        if(a[row][y]==1)
        {
            return false; // it means we cann't put a queen on that position
        }
    }
    int row = x; 
    int col = y;
    while(row>=0 && col>=0)
    {
        if(a[row][col]==1)
        {
            return false;
        }
        row--;
        col--; 
    }
    row = x; 
    col = y;
    while(row>=0 && col<n)
    {
        if(a[row][col]==1)
        {
            return false;
        }
        row--;
        col++; 
    }
    return true; 
}
bool NQueen(int** a, int x, int n) // we don't need y here bcz after placing queen we jumped on next row so therefore no use of y here
{
    if(x>=n)
    {
        return true;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(a,x,col,n))
        {
            a[x][col] = 1;
            if(NQueen(a,x+1,n))
            {
                return true; 
            }

            a[x][col] = 0; // backtracking
        }
    }
    return false; 
}
int32_t main()
{
    int n; 
    cin>>n; 

    int** arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 0; 
        }
    }

    if(NQueen(arr,0,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl; 
        }
    }

    return 0;
} 