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

int MaxPathSumUtil(Node* root, int &ans) /* &->bcz to make change in value of ans we have to get it by address */
{
    if(root==NULL)
        return 0; 
    int Left = MaxPathSumUtil(root->left, ans);
    int Right = MaxPathSumUtil(root->right, ans);
    
    /*
        In Notes :- 
        ans = max sum 
        NodeMax = Sum@node 
    */

    /* here we used strategy and just try to lookin that which value is greater among four */
    int NodeMax = max(max(root->data, root->data+Left+Right), max(root->data + Left, root->data + Right));

    ans = max(ans, NodeMax);   

    /* maximum value for a node from left data, right data and from it's own data */
    int SinglePathSum = max(root->data, max(root->data + Left, root->data + Right));
    
    return SinglePathSum; 
}       

int MaxPathSum(Node* root)
{
    int ans = INT_MIN;
 
    MaxPathSumUtil(root, ans); /* Utility Function */

    return ans;
}

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(-12);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    cout<<MaxPathSum(root);

    return 0;
}