#include<bits/stdc++.h>
using namespace std;

#define vs vector<string> 

class TrieNode{
public: 
    bool end; 
    TrieNode* next[26]; 
    TrieNode(){
        for(int i=0;i<26;i++)
            next[i] = NULL; 
        end = false; 
    }
};
class Trie{ 
private: 
    TrieNode* root;
public: 
    Trie(){
        root = new TrieNode(); 
    }    
    void insert(string &s){ 
        TrieNode* it = root; 
        for(auto ch : s){
            if(!it->next[ch-'a'])
                it->next[ch-'a'] = new TrieNode();
            it = it->next[ch-'a'];
        }   
        it->end = true;
    }
    void find(string &s){
        TrieNode* it = root; 
        for(auto ch : s){
            if(!it->next[ch-'a']){
                cout<<"No matching word\n"; 
                insert(s); 
                return; 
            }
            it = it->next[ch-'a'];
        }
        vs res;
        DFS(s,it,res,"");
        for(auto str : res){
            cout<<s+str<<endl;
        }
    }

    void DFS(string &s, TrieNode* it, vs &ans, string curr){
        if(it==NULL)
            return; 
        if(it->end)
            ans.push_back(curr); 
        for(int i=0;i<26;i++){
            if(it->next[i])
                DFS(s,it->next[i],ans,curr+char('a'+i));
        }
    }
};
signed main(){
    Trie* root = new Trie(); 
    int n; cin>>n; 
    vs words(n);
    for(auto &str : words){
        cin>>str; 
        root->insert(str);
    }
    int query; cin>>query; 
    string str;
    while(query--){
        cin>>str;
        root->find(str);
        cout<<endl; 
    }
    return 0;
}