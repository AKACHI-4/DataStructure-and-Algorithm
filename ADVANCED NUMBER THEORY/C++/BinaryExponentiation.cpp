#include<bits/stdc++.h>
using namespace std;

#define int long long
int N = 1e5+2, MOD = 1e9+7; 

/*
using Divide and Conqueror approach :-

Recursive Definition :

power(x, n) = power(x, n / 2) * power(x, n / 2); // if n is even
power(x, n) = x * power(x, n / 2) * power(x, n / 2); // if n is odd

Optimization : same subproblem is computed twice for each recursive call, We can optimize above by computing the solution of the subproblem once only.

let p = power(x, n)

TC : O(logn) & SC : O(logn)
*/

// int BinaryExponentiation(int a, int n){
//     if(n==0)
//         return 1; 
//     int p = BinaryExponentiation(a,n/2); 
//     if(n&1)
//         return (((p*p)%MOD)*a)%MOD;
//     else    
//         return (p*p)%MOD; 

// }

/*
Extend the pow function to work for negative n and float x:
*/

// double Power(double b, int e) {
//     if (e == 0)
//         return 1;

//     double p = Power(b, e / 2); 

//     cout << p << " " << e << endl;

//     if (e & 1) {
//         if (e < 0)
//             return (p * p) / b;
//         else
//             return (b * (p * p));
//     } else {
//         return (p * p);
//     }
// }

/*
Calculate pow(x,n) using Binary operators: Iterative Approach

1. Every number can be written as the sum of powers of 2
2. We can traverse through all the bits of a number from LSB to MSB in O(log n) time.
*/

int BinaryExponentiation(int a, int n){
    int ans = 1;

    while(n) {
        // cout<<(n&1)<<endl;

        if(n&1)
            ans = (ans*a) % MOD; 
        
        // cout<<ans<<endl;
        
        a = (a*a) % MOD;
        // cout<<a<<endl;
        
        n >>= 1;
        // cout<<n<<endl;
    }
    return ans;
}

signed main(){
    // double base; int power; 

    int base, power;
    cin>>base>>power; 
    
    base %= MOD; 

    cout<<BinaryExponentiation(base,power)<<endl;
    // cout << Power(base, power) << endl;

    return 0;
}