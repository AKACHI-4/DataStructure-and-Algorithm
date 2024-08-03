/* SEIVE OF ERATOSTHENES */
/* one of it's uses to find prime number in a given range */

/* It gives us a better approach on those question where we have to check for individual element */

/*

Time : O(Nloglog/N)
Space : O(1)
 
*/

#include<bits/stdc++.h>
using namespace std;

void primeSeive(int n)
{
    int prime[100] = {0};

    for(int i=2;i<=n;i++)
    {
        if(prime[i] == 0)
        {
            for(int j=(i*i);j<=n;j+=i)
            {
                prime[j] = 1; 
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i] == 0)
        {
            cout<<i<<" "; 
        }
    }
    cout<<endl; 
}

int main()
{
    int n; 
    cin>>n;
    cout<<"Prime number from 2 to "<< n <<" is : "<<endl;
    primeSeive(sqrt(n)); 
    return 0;
}
