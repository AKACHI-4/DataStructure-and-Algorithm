#include "bits/stdc++.h"
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

/*     
PREORDER TRAVERSAL
( Root -> Left Subtree -> Right Subtree )
*/
void Preorder(struct Node* root)
{
    if(root==NULL)
        return ; 
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

/* 
INORDER TRAVERSAL 
( Left Subtree -> Root ->  Right Subtree )
*/
void Inorder(struct Node* root)
{
    if(root==NULL)
        return ; 
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

/* 
POSTORDER TRAVERSAL 
( Left Subtree -> Right Subtree -> Root )
*/
void Postorder(struct Node* root)
{
    if(root==NULL)
        return ; 
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Preorder : ";
    Preorder(root); 
    cout<<"\n";
    cout<<"Inorder : ";
    Inorder(root);  
    cout<<"\n";
    cout<<"Postorder : ";
    Postorder(root); 
    cout<<"\n";
    
    return 0;
}
