#include<bits/stdc++.h>
using namespace std;

int Catalan(int n) {
    if(n==0)
        return 1; 
    int res = 0; 

    for(int i=0;i<n;i++)
        res += Catalan(i) * Catalan(n-i-1);
    return res;
} 

// It is a basic approach and time complexity for this approach is too high 
// we can optimise it but to optimise we have to use DP so 
// when we get DP we'll update it in it's optimised form. 

int32_t main()
{
    for(int i=0;i<10;i++)
        cout<<Catalan(i)<<" ";
    cout<<endl; 
    return 0;
}