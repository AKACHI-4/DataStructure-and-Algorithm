
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; 
    cin>>n; 

    char a[n+1];
    
    cin>>a; 

    bool check = true; 

    for(int i=0;i<n;i++)
    {
        if(a[i] != a[n-1-i])
        {
            check = false;
            break;
        }
    }

    if(check)
    {
        cout<<"Word is Pallindrome"<<endl;
    }
    else
    {
        cout<<"Not Pallindrome"<<endl;
    }

    return 0;
}