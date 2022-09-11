#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int rw, cln; 
    cin>>rw>>cln; 

    int a[rw][cln];

    int key; 
    cin>>key; 

    for(int i=0;i<rw;i++)
    {
        for(int j=0;j<cln;j++)
        {
            cin>>a[i][j];
        }
    }

    bool flag; 

    for(int i=0;i<rw;i++)
    {
        for(int j=0;j<cln;j++)
        {
            if(a[i][j]==key)
            {
                flag=true; 
            }
        }
    }
    if(flag)
    {
        cout<<"element is found"<<endl;
    }
    else
    {
        cout<<"element is not found"<<endl;
    }
    return 0;
}