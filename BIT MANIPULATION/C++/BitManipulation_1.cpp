#include<bits/stdc++.h>
#include<iostream>

using namespace std;

/* Get Bit */
int GetBit(int n, int pos)
{
    return ( n & (1<<pos) != 0 );  
}

/* Set Bit */
int SetBit(int n, int pos)
{
    return ( n | (1<<pos) );
}

/* Clear Bit */
int ClearBit(int n, int pos)
{
    int mask = ~(1<<pos);
    return ( n & mask ); 
}

/* Update Bit */
/* Update Bit = First Clear Bit then Set Bit */
int UpdateBit(int n, int pos, int val)
{
    int mask = ~(1<<pos);
    n = n & mask;
    return ( n | (val<<pos) );
}

int main()
{
    cout<<GetBit(5,2)<<endl;
    cout<<SetBit(5,1)<<endl;
    cout<<ClearBit(5,2)<<endl;
    cout<<UpdateBit(5,1,1)<<endl;

    return 0;
}