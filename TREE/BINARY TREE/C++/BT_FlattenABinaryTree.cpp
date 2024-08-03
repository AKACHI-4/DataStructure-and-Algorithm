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

void Flatten(Node* root)
{
    if( !root || !root->left && !root->right )
        return; 
    if(root->left != NULL)
    {
        Flatten(root->left);

        Node* temp = root->right; 
        root->right = root->left;
        root->left = NULL; 

        Node* n = root->right;
        while(n->right != NULL)
            n = n->right;
        n->right = temp; 
    }
    Flatten(root->right);
}

void inorder(Node* root)
{
    if(root==NULL) 
        return ; 
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int32_t main()
{
    Node* root = new Node(4);
    // root->left = new Node(9);
    // root->left->left = new Node(1);
    // root->left->right = new Node(3);
    // root->right = new Node(5);
    // root->right->right = new Node(6);

    Flatten(root);
    
    inorder(root);
    
    return 0;
}