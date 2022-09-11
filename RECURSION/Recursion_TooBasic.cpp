#include<bits/stdc++.h>

using namespace std;


/* Add all numbers till n */

// int SumTillN(int n)
// {
//     if(n==0)
//     {
//         return 0; 
//     }
//     return n + SumTillN(n-1);
// }
// int main()
// {
//     int n; 
//     cin>>n; 
//     cout<<SumTillN(n);
//     return 0;
// }


/* Calculate n raised to power of p */

// int nRaisep(int n, int p)
// {
//     if(p==0)
//     {
//         return 1; 
//     }
//     return n * nRaisep(n,p-1);
// }
// int main()
// {
//     int n, p;
//     cin>>n>>p;

//     cout<<nRaisep(n,p);
// }


/* Factorial of a number n */
// int fact(int num)
// {
//     if(num==1)
//     {
//         return 1; 
//     }
//     return num * fact(num-1);
// }
// int main()
// {
//     int num; 
//     cin>>num;

//     cout<<fact(num);
// }


/* Print the nth Fibonacci number */
// int Fib(int n){
//     if(n<2)
//         return n; 
//     /* as we know any fibonacci number is sum of it's previous two fibonacci number except for 0 and 1 */
//     return Fib(n-1) + Fib(n-2);
// }
// int main(){
//     int n; cin>>n; 
//     cout<<Fib(n)<<endl;

//     return 0; 
// }