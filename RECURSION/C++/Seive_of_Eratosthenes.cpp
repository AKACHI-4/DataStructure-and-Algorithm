/* SEIVE OF ERATOSTHENES */
/* one of it's uses to find prime number in a given range */

/* It gives us a better approach on those question where we have to check for individual element */

#include<bits/stdc++.h>

using namespace std;

// void primeSeive(int n)
// {
//     int prime[100] = {0};

//     for(int i=2;i<=n;i++)
//     {
//         if(prime[i] == 0)
//         {
//             for(int j=(i*i);j<=n;j+=i)
//             {
//                 prime[j] = 1; 
//             }
//         }
//     }
//     for(int i=2;i<=n;i++)
//     {
//         if(prime[i] == 0)
//         {
//             cout<<i<<" "; 
//         }
//     }
//     cout<<endl; 
// }
// int main()
// {
//     int n; 
//     cin>>n;
//     cout<<"Prime number from 2 to "<<n<<" is : "<<endl;
//     primeSeive(n); 
//     return 0;
// }


/* Variations based on seive of eratosthenes */

/* 1. Prime Factorisation using Sieve */

void PrimeFactor(int n)
{
    int spf[100] = {0}; /* smallest prime factor */
    for(int i=2;i<=n;i++)
    {
        spf[i] = i;  
    }
    for(int i=2;i<=n;i++)
    {
        if(spf[i] == i)
        {
            for(int j=pow(i,2);j<=n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j] = i; 
                }
            }
        }
    }

    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }

}

int32_t main()
{
    int n;
    cin>>n; 

    PrimeFactor(n);

    return 0; 
}

/* Nine Divisors */
 
//{ Driver Code Starts
// #include<bits/stdc++.h> 
// using namespace std; 

// // } Driver Code Ends
// class Solution{   
// public:
//     long long int nineDivisors(long long int N){
//         int nineDivcnt = 0;
//         int n = sqrt(N); 
//         vector<int> prime(n+1);
//         for(int i=1;i<=n;i++) 
//             prime[i] = i; 
        
//         for(int i=2;i*i<=n;i++){
//             if(prime[i]==i){
//                 for(int j=i+i;j<=n;j+=i)
//                     prime[j] = i;
//             }
//         }
        
//         for(int i=0;i<=n;i++)
//             cout<<prime[i]<<" ";
//         cout<<endl;
        
//         for(int i=2;i<=n;i++){
//             int p = prime[i];
//             int q = prime[i/p];
//             cout<<p<<" "<<q<<endl;
//             if((p!=q && p*q==i && q!=1) || (prime[i]==i && pow(i,8)<=N)){
//                 nineDivcnt++; 
//             }
            
//         }
        
//         return nineDivcnt; 
//     }
// };

// //{ Driver Code Starts.
// int main() 
// { 
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         long long int N;
//         cin>>N;
//         Solution ob;
//         cout << ob.nineDivisors(N) << endl;
//     }
//     return 0; 
// }
// } Driver Code Ends

