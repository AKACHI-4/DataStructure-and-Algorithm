#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e5+7, MOD = 1e7+2;

int totient[N];
signed main(){
    int n; cin>>n;
    n += 1; 

    for(int i=0;i<n;i++)
        totient[i] = i; 

    for(int i=2;i<n;i++){
        if(totient[i]==i){
            for(int j=2*i;j<n;j+=i){
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }

    for(int i=2;i<n;i++)    
        cout<<totient[i]<<" ";

    return 0;
}