#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int bit_size = 32;

class TrieNode{
public: 
    TrieNode* next[2]; 
    TrieNode(){
        next[0] = NULL; 
        next[1] = NULL; 
    }
};
TrieNode* trie; 
void insert(int val){ 
    TrieNode* root = trie;
    for(int i=bit_size-1;i>=0;i--){
        int cur_bit = (val>>i) & 1; 
        if(!root->next[cur_bit])
            root->next[cur_bit] = new TrieNode(); 
        root = root->next[cur_bit];
    }
}
int query(int num){ 
    TrieNode* it = trie;
    int ans = 0; 
    for(int i=bit_size-1;i>=0;i--){
        int cur_bit = (num>>i) & 1;
        int opp_bit = cur_bit xor 1;
        if(it->next[opp_bit]){
            it = it->next[opp_bit]; 
            ans |= 1<<i;
        }else{
            it = it->next[opp_bit xor 1];
        }
    }
    return ans;
}
signed main(){
    int n; cin>>n; 
    vi a(n); 
    for(auto &i : a)
        cin>>i; 
    trie = new TrieNode(); 
    insert(0);
    vi RMax(n+1,0);
    int R = 0; 
    for(int i=n-1;i>=0;i--){
        R ^= a[i];
        if(i!=n-1){
            RMax[i] = max(RMax[i+1],query(R));
            insert(R);
        }else{
            RMax[i] = query(R); 
            insert(R);
        }
    }
    free(trie); 
    trie = new TrieNode();
    insert(0);
    int ans = 0; 
    int L = 0;
    for(int i=0;i<n;i++){
        L ^= a[i]; 
        ans = max(ans,RMax[i+1]+query(L));
        insert(L); 
    }

    cout<<ans<<endl;

    return 0;
}