
#include<bits/stdc++.h>

using namespace std;

bool isSafe(int** a, int x, int y, int n) // int** a bcz I m dynamically allocating the memory for 2d array a
{
    if(x<n && y<n && a[x][y]==1)
    {
        return true; 
    }
    return false; 
}

bool RatInMaze(int** a, int x, int y, int n, int** solarr)
{
    /* base condition */
    if(x==n-1 && y==n-1)
    {
        solarr[x][y]=1; // only to get path
        return true; 
    }

    if(isSafe(a,x,y,n))
    {
        solarr[x][y] = 1;
        /* Move in Right direction */
        if(RatInMaze(a,x+1,y,n,solarr))
        {
           return true;  
        }
        if(RatInMaze(a,x,y+1,n,solarr))
        {
            return true; 
        }
        solarr[x][y] = 0;       // backtracking
    }
    return false; 
}

int main()
{
    int n; 
    cin>>n; 

    int** arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int** solarr = new int*[n];
    for(int i=0;i<n;i++)
    {
        solarr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            solarr[i][j] = 0; 
        }
    }

    if(RatInMaze(arr,0,0,n,solarr))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl; 
        }
    }

    return 0;
}