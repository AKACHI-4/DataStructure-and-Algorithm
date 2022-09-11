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

/* BUILD A BST USING ARRAY */
Node* BuildBST(Node* root, int val)
{
    if(root==NULL)
        return new Node(val); 
    if(val<root->data)
        root->left = BuildBST(root->left, val);
    else
        root->right = BuildBST(root->right, val);
    return root; 
}

void inorder(Node* root)
{
    if(root==NULL)
        return; 
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int32_t main()
{
    Node* root = NULL; 
    root = BuildBST(root,5); 
    int a[] = {5,1,3,4,2,7};
    for(int i=1;i<6;i++)
        BuildBST(root, i[a]);
    inorder(root);
    return 0;
}       