#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data; 
    Node* left; 
    Node* right; 

    Node(int val)
    {
        data = val; 
        left = NULL; 
        right = NULL; 
    }
};

Node* SearchInBST(Node* root, int key)
{
    if(root==NULL)
        return NULL; 
    if(root->data==key)
        return root; 
    else if(root->data>key)
        return SearchInBST(root->left, key);
    else
        return SearchInBST(root->right, key);
}

int32_t main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    Node* ans = SearchInBST(root, 10);
    if(ans==NULL)
        cout<<"key is not here"<<endl; 
    else
        cout<<"I got the key. it is "<<ans->data<<" na.."<<endl;
    return 0;
}