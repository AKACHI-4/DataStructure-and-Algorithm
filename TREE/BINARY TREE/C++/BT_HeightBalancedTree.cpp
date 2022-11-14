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

int Height(Node* root)
{
    if(root==NULL)
        return 0; 
    return max(Height(root->left),Height(root->right)) + 1; 
}

/* Normal Approach */
bool IsBalanced_1(Node* root)
{
    if(root == NULL)
        return true; 
    if(!IsBalanced_1(root->left))
        return false;
    if(!IsBalanced_1(root->right))
        return false;

    int Lh = Height(root->left);
    int Rh = Height(root->right);
    
    if( abs(Lh-Rh) <= 1 )
        return true;
    else    
        return false; 
}   // TIME COMPLEXITY : O(n)

/* Optimised Approach */
bool IsBalanced_2(Node* root, int* height)
{
    if(root==NULL)
        return 1; 
    int Lh = 0, Rh = 0; 
    if(!IsBalanced_2(root->left, &Lh))
        return 0;
    if(!IsBalanced_2(root->right, &Rh))
        return 0;  
    
    *height = max(Lh, Rh) + 1; 
    /* condition for height balanced */
    if(abs(Lh-Rh) <= 1)
        return 1; 
    else    
        return 0; 
}   // TIME COMPLEXITY : O(n)

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right = new Node(3);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // if(IsBalanced_1(root))
    //     cout<<"Balanced Tree"<<endl;
    // else{
    //     cout<<"Unbalanced Tree"<<endl;
    // }

    int height = 0; 
    if(IsBalanced_2(root, &height))
        cout<<"Balanced Tree"<<endl;
    else{
        cout<<"Unbalanced Tree"<<endl;
    }

    return 0;
}