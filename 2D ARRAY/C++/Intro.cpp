#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int rw, cln; 
    cin>>rw>>cln; 

    int a[rw][cln];

    for(int i=0;i<rw;i++)
    {
        for(int j=0;j<cln;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<rw;i++)
    {
        for(int j=0;j<cln;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl; 
    }


    return 0;
}

