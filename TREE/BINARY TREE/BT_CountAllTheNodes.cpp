#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public: 
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

int CountNodes(Node* root)
{
    if(root==NULL)
        return 0;
    return CountNodes(root->left) + CountNodes(root->right) + 1;  
}

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<CountNodes(root)<<endl; 

    return 0;
}