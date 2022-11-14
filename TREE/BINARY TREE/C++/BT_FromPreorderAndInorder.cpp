#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public : 
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

int search(int inorder[], int st, int en, int curr)
{
    for(int i=st;i<=en;i++)
    {
        if(inorder[i]==curr)
            return i; 
    }
    return -1; 
}

Node* BuildTree(int Preorder[], int Inorder[], int st, int en)
{
    static int idx = 0;

    if( st > en )
        return NULL; 
    int curr = Preorder[idx];
    idx++; 
    Node* node = new Node(curr);

    if(st==en)
    {
        return node; 
    }

    int pos = search(Inorder, st, en, curr);

    node->left = BuildTree(Preorder, Inorder, st, pos-1);
    node->right = BuildTree(Preorder, Inorder, pos+1, en);

    return node; 
}

void inorder(Node* root)
{
    if(root==NULL)
        return ; 
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int Preorder[] = { 1, 2, 4, 3, 5 };
    int Inorder[] = { 4, 2, 1, 5, 3 };

    Node* root = BuildTree(Preorder, Inorder, 0, 4);
    inorder(root);

    return 0;
}