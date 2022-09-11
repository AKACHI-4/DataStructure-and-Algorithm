#include<bits/stdc++.h>
using namespace std;

int power = 31; 
const int N = 1e5+ 2, MOD = 1e9+7; 

signed main(){
    string s = "na"; 
    string t = "apnacollegena"; 
    int S = s.size(), T = t.size(); 

    vector<long long> powers(T+1); 
    powers[0] = 1;
    for(int i=1;i<T+1;i++)
        powers[i] = (powers[i-1] * power) % MOD; 
    
    vector<long long> hashes(T+1,0);
    for(int i=0;i<T;i++)
        hashes[i+1] = (hashes[i] + (t[i] - 'a' + 1)*powers[i]) % MOD;  
    long long hash_s = 0; 
    for(int i=0;i<S;i++)
        hash_s = (hash_s + (s[i] - 'a' + 1)*powers[i])%MOD; 

    for(int i=0;i+S-1<T;i++){
        long long cur_hash = (hashes[i+S] - hashes[i] + MOD) % MOD;
        if(cur_hash == (hash_s * powers[i]) % MOD)
            cout<<s<<" found at index "<<i<<endl;; 
    }

    return 0;
} // TC : O(S+T)