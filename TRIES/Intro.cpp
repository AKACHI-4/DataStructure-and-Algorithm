#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

class Trie{
public: 
    class node{
    public: 
        bool end; 
        node* next[26]; // coz of 26 next character
        node(){
            end = false;
            for(int i=0;i<26;i++)
                next[i] = NULL; 
        }
    };

    node* trie;
    Trie(){
        trie = new node(); 
    }

    void insert(string word){
        int i=0; 
        node* it = trie; 
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL)
                it->next[word[i]-'a'] = new node();
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end = true;
    }
    
    bool search(string word){
        int i=0; 
        node* it = trie; 
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL)
                return false; 
            it = it->next[word[i]-'a'];
        }
        return it->end; 
    }
};

signed main(){
    Trie* myTrie = new Trie(); 
    vector<string> words = {"krishna","Ram"};
    for(auto w : words)
        myTrie->insert(w); 
    if(myTrie->search("krishna"))
        cout<<"krishna found\n";
    else    
        cout<<"krishna not found\n";

    return 0;
}