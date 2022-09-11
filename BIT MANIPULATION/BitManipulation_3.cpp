#include<bits/stdc++.h>
#include<iostream>

using namespace std;

/* 
Q.1 Write a program to find a unique number in an array whre all numbers except one, are present twice ?
*/
// int unique(int arr[], int n)
// {
//     int xorsum = 0; 
//     for(int i=0;i<n;i++)
//     {
//         xorsum = xorsum^arr[i];
//     }
//     return xorsum; 
// }
// int main()
// {
//     int a[] = {1,2,2,3,3,4,1,5,5};
//     int n = sizeof(a)/sizeof(a[0]);
//     cout<<unique(a,n);
//     return 0;
// }

/* 
Q.2 Write a program to find two unique number in an array whre all numbers except one, are present twice ?
*/
bool setBit(int n, int pos)
{
    return ( ( n & (1<<pos) ) != 0 ); 
}
int twoUniqueNumber(int a[], int n)
{
    int xorsum = 0; 
    for(int i=0;i<n;i++)
    {
        xorsum = xorsum^a[i];
    }
    int tempxor = xorsum; 
    int setbit = 0; 
    int pos = 0; 
    while(setbit != 1)
    {
        setbit = xorsum & 1;
        pos++; 
        xorsum = xorsum >> 1; 
    }
    int newxor = 0 ;
    for(int i=0;i<n;i++)
    {
        if(setBit(a[i],pos-1))
        {   
            newxor = newxor^a[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;

    return 0; 
}
int main()
{   
    int a[] = {2,4,6,7,4,5,6,2};
    int n = sizeof(a)/sizeof(a[0]);
    twoUniqueNumber(a,n); 
    return 0; 
}


/* 
Q.3 Write a program to find a unique number in an array whre all numbers except one, are present twice ?
*/
// bool getBit(int n, int pos)
// {
//     return ( (n & (1<<pos)) != 0 );
// }
// int setbit(int n, int pos)
// {
//     return ( n | (1<<pos) );
// }
// int unique_in_three_(int a[], int n)
// {   
//     int result = 0; 
//     for(int i=0;i<64;i++)
//     {
//         int sum=0; 
//         for(int j=0;j<n;j++)
//         {
//             if(getBit(a[j],i))
//             {
//                 sum++; 
//             }
//         }    
//         if(sum%3 != 0)
//         {
//             result = setbit(result, i);
//         }
//     }
//     return result;
// }
// int main()
// {
//     int a[] = {1,3,2,3,4,2,1,1,3,2};
//     cout<<unique_in_three_(a, 10);
//     return 0; 
// }