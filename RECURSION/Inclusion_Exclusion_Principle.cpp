/* This principle is used to solve certain programming question based on Finding the number of way to do sum */

/*  
    Ex- n1 = no. of student can talk in hindi
        n2 = no. of student can talk in english
        n3 = no. of student that can talk in both
        Total students = n1 + n2 - n3     
*/

#include<bits/stdc++.h>

using namespace std;

/* Q.1 How many numbers between 1 and 1000 are divisible by 5 or 7 ? */

// int divisible(int n, int a, int b)
// {
//     int c1 = n/a;
//     int c2 = n/b; 

//     int c3 = n/(a*b);

//     return ( (c1 + c2) - c3 ); 
// }

// int main()
// {
//     int n, a, b; 
//     cin>>n>>a>>b;
    
//     cout<<divisible(n,a,b)<<endl; 

//     return 0;
// }

/* Q.2 Euclid Algorithm to find GCD/HCF ? */

int GCD(int a, int b)
{
    while(b!=0)
    {
        int rem = a%b; 
        a = b; 
        b = rem; 
    }
    return a; 
}
int32_t main()
{
    int a, b; 
    cin>>a>>b;
    
    cout<<GCD(a,b)<<endl;

    return 0;
}
