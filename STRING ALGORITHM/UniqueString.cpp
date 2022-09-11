#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define vs vector<string> 
#define vi vector<int> 

const int p = 31, MOD = 1e9+7;
int power[26]; 

int calculateHash(string str){
    int hash = 0;
    for(int i=0;i<str.size();i++)
        hash += ((str[i]-'a'+1)*power[i])%MOD;
    return hash;
}
signed main(){
    
    // vs strings = {"aa","aa","bc","cd","bc","aa","b","ad","ad"}; 
    /* brute force */
    // int distinct = 1; 
    // sort(strings.begin(),strings.end());
    // // {"aa","aa","aa","ad","ad","b","bc","bc","cd"}
    // // TC : O(nmlogn)
    // for(int i=1;i<strings.size();i++){
    //     if(strings[i]!=strings[i-1])
    //         distinct++; 
    // }
    // cout<<distinct<<endl; 


    vs strings = {"aa","bc","aa","cd","bc","cd","b","b","b"}; 
    power[0] = 1;
    for(int i=1;i<26;i++)
        power[i] = (power[i-1] * p) % MOD; 
    vi hashes; 
    for(auto str : strings){
        hashes.push_back(calculateHash(str));
    } // TC : O(nm)
    sort(hashes.begin(),hashes.end()); 
    // TC : O(nlogn)

    // Final TC : O(nm + nlogn)
    int distinct = 1;
    for(int i=1;i<hashes.size();i++){
        if(hashes[i]!=hashes[i-1])
            distinct++;
    }

    cout<<distinct<<endl;

    return 0;
}