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

Node* InorderSucc_(Node* root)
{
    Node* curr = root;
    while (curr && curr->left!=NULL)
        curr = curr->left; 
    return curr; 
}

Node* DeleteInBST(Node* root, int val)
{   
    if(root->data > val)
        root->left = DeleteInBST(root->left, val);
    else if(root->data < val)
        root->right = DeleteInBST(root->right, val);
    else 
    {
        /* Case - 1 and Case - 2 */
        if(root->left == NULL)
        {
            Node* temp = root->right; 
            free(root);
            return temp; 
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp; 
        }
        /* Case - 3 */
        Node* temp = InorderSucc_(root->right);
        root->data = temp->data;
        root->right = DeleteInBST(root->right, temp->data);
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
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    cout<<"Before Deletion : "; 
    inorder(root);
    cout<<endl; 
    root = DeleteInBST(root,2);
    cout<<"After Deletion : ";
    inorder(root);

    return 0;
}