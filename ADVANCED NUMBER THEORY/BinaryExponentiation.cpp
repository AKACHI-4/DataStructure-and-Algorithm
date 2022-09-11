#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+2, MOD = 1e9+7; 

int BinaryExponentiation(int a, int n){
    if(n==0)
        return 1; 
    int p = BinaryExponentiation(a,n/2); 
    if(n&1)
        return (((p*p)%MOD)*a)%MOD;
    else    
        return (p*p)%MOD; 

}

// int BinaryExponentiation(int a, int n){
//     int ans = 1;
//     while(n>0){
//         cout<<(n&1)<<endl;
//         if(n&1)
//             ans = (ans*a)%MOD; 
//         cout<<ans<<endl;
//         a = (a*a)*MOD;
//         cout<<a<<endl;
//         n >>= 1;
//         cout<<n<<endl;
//     }
//     return ans;
// }

signed main(){
    int base, power; 
    cin>>base>>power; 
    
    base %= MOD; 

    cout<<BinaryExponentiation(base,power)<<endl;

    return 0;
}