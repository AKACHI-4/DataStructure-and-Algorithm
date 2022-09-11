#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

class TrieNode{ 
public: 
    TrieNode* next[2];
    TrieNode(){
        next[0] = NULL; 
        next[1] = NULL; 
    }
};
TrieNode* BuildTrie(vi &a){
    TrieNode* root = new TrieNode();
    int n = a.size(); 
    for(int i=0;i<n;i++){
        int temp = a[i];
        TrieNode* curr = root; 
        for(int i=31;i>=0;i--){
            int bit = (temp>>i) & 1; 
            if(curr->next[bit]==NULL)
                curr->next[bit] = new TrieNode(); 
            curr = curr->next[bit]; 
        }
    }
    return root; 
}
int MaximumXOR(vi &a, TrieNode* root){
    int Max = 0; 
    for(int i=0;i<a.size();i++){
        int num = a[i]; 
        TrieNode* curr = root; 
        int cur_max = 0; 
        for(int i=31;i>=0;i--){
            int bit = ((num>>i) & 1) ? 0 : 1;
            if(curr->next[bit]){
                cur_max <<= 1;
                cur_max |= 1;
                curr = curr->next[bit];
            }else{
                cur_max <<= 1;
                cur_max |= 0;
                curr = curr->next[bit xor 1];
            }
            Max = max(Max,cur_max);
        }
    }
    return Max;
}
signed main(){

    vector<int> arr = {3,10,5,15,2};
    TrieNode* root = BuildTrie(arr);

    cout<<MaximumXOR(arr,root)<<endl; 
    return 0;
}