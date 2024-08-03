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

int search(int inorder[], int st, int en, int val)
{
    for(int i=st;i<=en;i++)
    {
        if(inorder[i]==val) 
            return i; 
    }
    return -1; 
}

Node* BuildTree(int postorder[], int inorder[], int st, int en)
{
    static int idx = 4;
    if( st>en )
        return NULL; 
    int val = postorder[idx];
    idx--; 
    Node* curr = new Node(val);
    if( st==en )
        return curr;
    int pos = search(inorder, st, en, val);

    curr->right = BuildTree(postorder, inorder, pos+1, en);
    curr->left = BuildTree(postorder, inorder, st, pos-1);

    return curr; 
}

void preorder(Node* root)
{
    if(root==NULL)  
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
        return; 
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int Postorder[] = { 4, 2, 5, 3, 1 };
    int Inorder[] = { 4, 2, 1, 5, 3 };

    Node* node = BuildTree(Postorder, Inorder, 0, 4 );
    postorder(node);
    cout<<endl; 
    preorder(node);

    return 0;
}