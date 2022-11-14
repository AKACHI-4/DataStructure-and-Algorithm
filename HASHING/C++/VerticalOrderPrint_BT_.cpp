#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define pii pair<int,int> 
#define vii vector<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

struct Node
{
    int data; 
    Node* left;
    Node* right;

    Node(int num){
        data = num; 
        left = NULL; 
        right = NULL; 
    }
};

void Get_VerticalOrder(Node* root, int HD, map<int, vi> &mp){
    if(root==NULL)
        return ; 
    mp[HD].push_back(root->data);
    Get_VerticalOrder(root->left, HD-1, mp);
    Get_VerticalOrder(root->right, HD+1, mp);
}

signed main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right =  new Node(3); 
    root->right->left =  new Node(5); 
    root->right->right =  new Node(7); 

    map<int, vi> mp; 

    int HD = 0; 

    Get_VerticalOrder(root, HD, mp);

    map<int, vi> :: iterator it;

    for(it=mp.begin();it!=mp.end();it++){
        for(int i=0;i<(it->ss).size();i++)
            cout<<(it->ss)[i]<<" ";
        cout<<endl; 
    }


    return 0;
} /* TIME COMPLEXITY : O(nlogn) */