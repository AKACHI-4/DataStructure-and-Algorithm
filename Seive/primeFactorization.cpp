/* 1. Prime Factorisation using Sieve */

/* Brute Force Method 

Time : O(NloglogN)
Space : O(1)

*/
 
void PrimeFactor(int n)
{
    int spf[100] = {0}; /* smallest prime factor */

    for(int i=2;i<=n;i++) {
        spf[i] = i;  
    }

    for(int i=2;i<=n;i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i;j<=n;j+=i)
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
