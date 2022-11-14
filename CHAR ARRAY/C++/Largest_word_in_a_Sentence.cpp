#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; 
    cin>>n;
    cin.ignore(); // used to remove buffer

    char a[n+1];

    cin.getline(a, n); // getline function helps us to store space between word in a sentence
    cin.ignore();

    int i=0; 
    int currlen=0, maxLen=0;
    int st = 0, maxst = 0; 

    while(1)
    {
        if(a[i]==' ' || a[i]=='\0')
        {
            if(currlen > maxLen)
            {
                maxst = st; 
            }
            maxLen=max(currlen, maxLen);
            currlen = 0 ; 
            st = i+1; 
        }
        else
        {
            currlen++;
        }
        if(a[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout<<maxLen<<endl;

    for(int i=0;i<maxLen;i++)
    {
        cout<<a[i+maxst]; 
    }

    return 0;
}