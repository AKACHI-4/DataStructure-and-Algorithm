#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define pii pair<int,int> 
#define vii vector<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main()
{
    // map<int,int> mp;
    
    // mp[8] = 2;

    // cout<<mp[8]<<endl; 

    // /* working as an array in terms of frontend */


    unordered_map<int,int> mp; 
     
    mp.insert({1,0});
    mp.insert({3,2});
    mp.insert({2,1});
    mp.insert({4,3});
    mp.insert({5,4});

    sort(mp.begin(),mp.end()); 

    for(auto it = mp.begin(); it != mp.end(); it++ ){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}