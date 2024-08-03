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

bool Is_BST(Node* root, Node* min, Node* max)
{
    if(root==NULL)
        return true; 
    if(min != NULL && root->data <= min->data)
        return false;
    if(max != NULL && root->data >= max->data)
        return false;
    /* here we check is left subtree valid or not */
    bool Left_Valid = Is_BST(root->left, min, root);
    /* here we check is right subtree valid or not */
    bool Right_Valid = Is_BST(root->right, root, max);

    return Left_Valid and Right_Valid;
} // Time Complexity : O(n), n - no. of total nodes 
 
int32_t main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    if(Is_BST(root, NULL, NULL))
        cout<<"Yes, It is a BST !!"<<endl;
    else 
        cout<<"Not a BST"<<endl;
    return 0;
}

