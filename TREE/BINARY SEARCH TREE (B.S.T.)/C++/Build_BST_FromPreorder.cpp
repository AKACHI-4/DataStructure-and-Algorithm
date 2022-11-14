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

Node* ConstructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n)
/*
key - it is the current value which we wanna to build 
(min, max) - ( minimum till that node, maximum till that node )
*/
{   
    if(*preorderIdx >= n)   
        return NULL;
    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key); 
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n)
            root->right = ConstructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        if(*preorderIdx < n)
            root->left = ConstructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
    }
    return root;
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
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5; 
    int preorderIdx = 0; 

    Node* root = ConstructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);

    inorder(root);

    return 0;
}