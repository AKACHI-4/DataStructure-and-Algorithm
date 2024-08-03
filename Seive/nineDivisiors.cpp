#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long long int nineDivisors(long long int N){
        int nineDivcnt = 0;
        int n = sqrt(N); 
        vector<int> prime(n+1);
        for(int i=1;i<=n;i++) 
            prime[i] = i; 
        
        for(int i=2;i*i<=n;i++){
            if(prime[i]==i){
                for(int j=i+i;j<=n;j+=i)
                    prime[j] = i;
            }
        }
        
        for(int i=0;i<=n;i++)
            cout<<prime[i]<<" ";
        cout<<endl;
        
        for(int i=2;i<=n;i++){
            int p = prime[i];
            int q = prime[i/p];
            cout<<p<<" "<<q<<endl;
            if((p!=q && p*q==i && q!=1) || (prime[i]==i && pow(i,8)<=N)){
                nineDivcnt++; 
            }
            
        }
        
        return nineDivcnt; 
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0; 
}
